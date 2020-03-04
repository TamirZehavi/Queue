#include "Queue.h"

Queue::Queue(int size)
{
	this->SetSize(size);
	this->counter = 0;
	this->end = -1;
	this->start = 0;
	this->InitQ(size);
}

void Queue::SetSize(int size)
{
	if (size < 2)
	{
		cout << "Invalid queue size. setting to minimal size" << endl;
		this->size = 2;
	}
	else this->size = size;

}

Queue::~Queue()
{
	if (this->IDs)
		delete[]this->IDs;
}

void Queue::InitQ(int)
{
	this->IDs = new int[size];
	assert(this->IDs);
}

bool Queue::IsEmpty() const
{
	return this->counter == 0;
}

bool Queue::IsFull() const
{
	return this->size == this->counter;
}

void Queue::Enlarge()
{
	int old_size = this->size;
	int* tmp = new int[this->size]; //new array for copying
	assert(tmp);
	for (int i = 0; i < this->size; i++)// copy old one to tmp
		tmp[i] = this->IDs[i];
	this->size *= 2; //double the size
	delete[] this->IDs;
	this->InitQ(this->size);
	for (int i = 0; i < old_size; i++) //copy back
		this->IDs[i] = tmp[i];
	delete[] tmp;
}

void Queue::Insert(int id)
{
	if (this->check_ID(id))
	{
		if (this->IsFull())
		{
			cout << "Queue full! Doubling size" << endl;
			this->Enlarge();
			this->Insert(id);
		}
		else
		{
			this->end = (this->end + 1) % this->size;  //make sure it's a cercular array
			this->IDs[this->end] = id;				   //make sure it's a cercular array
			this->counter++;						   //make sure it's a cercular array
		}
	}
	else
	{
		cout << "Invalid ID. Please try again." << endl;
		return;
	}
}

void Queue::Remove()
{
	if (this->IsEmpty())
	{
		cout << "Nothing to remove!" << endl;
	}

	this->start = (this->start + 1) % this->size;  //make sure it's a cercular array
	this->counter--;							   //make sure it's a cercular array
}		

int Queue::front()
{
	if (this->IsEmpty()) {
		return 0;
	}
	return IDs[this->start];

}

void Queue::PrintQ()
{
	Queue tmp = Queue(this->size);
	while (!this->IsEmpty()) //copy Queue into tmp
	{
		tmp.Insert(this->front());
		this->Remove();
	}
	this->start = 0; //adjusting pointers
	this->end = -1;	 //adjusting pointers
	while (!tmp.IsEmpty())
	{
		cout << tmp.front() << " ,";  
		this->Insert(tmp.front());  //copy back to this Queue
		tmp.Remove();
	}

}

bool Queue::check_ID(int id)
{
	if (id == 1000 || id <= 0)
		return false;
	else return true;
}

int Queue::PopChild()
{
	int tmpID = NULL;
	Queue tmp = Queue(this->size);
	while (!this->IsEmpty())
	{
		if (!tmpID)//only if tmpID hasn't been assigned yet, keep checking
		{
			if (this->front() > 1000)
			{
				tmpID = this->front();
				this->Remove();
			}
			else
			{
				tmp.Insert(this->front());
				this->Remove();
			}
		}
		else//tmpID have been assinged, no need to check for children in the queue
		{
			tmp.Insert(this->front());
			this->Remove();
		}

	}

	this->start = 0;	 //adjusting pointers
	this->end = -1;		 //adjusting pointers
	while (!tmp.IsEmpty())
	{
		this->Insert(tmp.front());
		tmp.Remove();
	}

	if (!tmpID)
		return NULL;
	else return tmpID;

}