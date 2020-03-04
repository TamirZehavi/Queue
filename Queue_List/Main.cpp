#include <iostream>
#include <string.h>
#include "Queue.h"

using namespace std;

void PrintMenu();
void Menu(Queue&);

int main()
{
	Queue q1 = Queue(1);
	Menu(q1);
}

void PrintMenu()
{
	cout << "--------Welcome to 'Yeladudes' Clinique--------" << endl;
	cout << "Please choose an option from the menu:" << endl;

	for (int i = 0; i < 3; i++)
		cout << endl;

	cout << "[1]- Insert patient" << endl;
	cout << "[2]- Remove patient" << endl;
	cout << "[3]- Remove child" << endl;
	cout << "[4]- Print queue" << endl;
	cout << "[5]- Exit" << endl;

}

void Menu(Queue &q1)
{
	char menu = '0';

	cout << "Tamir Zehavi 308241298" << endl;		  //Names of students
	cout << "Barak Rotshtein 302778014" << endl;	  //
	cout << endl;									  //

	int ID = NULL;//ID for patient initialization 
	int tmp = NULL;

	while (menu != '5')
	{
		PrintMenu();
		cin >> menu;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer

		switch (menu)
		{
		case '1':
			cout << "Insert ID" << endl;
			cin >> ID;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer
			q1.Insert(ID);
			cout << "Thank you!" << endl;
			system("pause");
			system("cls");
			break;

		case '2':
			tmp = q1.front();
			if (!tmp) //if queue is empty print an appropriate message
				cout << "Nothing to remove" << endl;
			else
			{
				cout << "Patient number: " << tmp << " Removed!" << endl;
				q1.Remove();
			}
			system("pause");
			system("cls");
			break;

		case '3':
			tmp = q1.PopChild();
			if (!tmp)
			{
				cout << "No children in the queue!" << endl;
			}
			else
				cout << "Child number: " << tmp << " removed!";
			system("pause");
			system("cls");
			break;

		case '4':
			q1.PrintQ();
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

