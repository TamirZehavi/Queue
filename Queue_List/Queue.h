#pragma once
#include <iostream>
#include <cassert>

using namespace std;

class Queue
{
private:
	int* IDs;
	int size;
	int counter;
	int start;
	int end;
	void Enlarge();
	bool check_ID(int);
	void SetSize(int);

public:
	Queue(int size);
	~Queue();

	void InitQ(int);
	bool IsEmpty() const;
	bool IsFull() const;
	void Insert(int);
	void Remove();
	int front();

	void PrintQ();
	int PopChild();


};

