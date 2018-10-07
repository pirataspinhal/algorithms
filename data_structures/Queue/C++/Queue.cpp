#include<iostream>
#include<stdio>
#include<conio>

using namespace::std;

class queue
{
	private:
		int no;
	public:
		queue *next;
		void getdata()
		{
			cout << ""enter number;
			cin >>no;
			next = NULL;
		}
		void showdata()
		{
			cout<<"number - " << no;
		}
};

queue *front=NULL, *rear=NULL;

void insert()
{
	queue *newptr=new queue;
	if(!newptr)
	{
		cout << "memory allocation error";
		return;
	}
	newptr->getdata();
	if(rear == NULL)
	{
		front=newptr;
		rear=newptr;
	}
	else
	{
		rear->next=newptr;
		rear=newptr;
	}
}

void delnode()
{
	if(front=NULL)
	{
		cout << "queue is not existing, underflow";
		return;
	}
	queue *ptr=front;
	if(front==rear)
	{
		front=NULL;
		rear=NULL:
	}
	else
	{
		front=front->next;
	}
	cout<<"deleted element - ";
	ptr->showdata();
	delete ptr;
}

void shownode()
{
	if(front=NULL)
	{
		cout << "queue is not existing, underflow";
		return;
	}
	queue *ptr=front;
	while(ptr!=NULL)
	{
		ptr->showdata();
		ptr=ptr->next;
	}
}

int main()
{
	int ch;
	char choice;
	do{
		cout << "1. Insertion \n";
		cout << "2. Deletion \n";
		cout << "3. Show the whole list(traverse) \n";
		cout << "4. exit \n";
		cin >> ch;
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: delnode();
					break;
			case 3: shownode();
					break;
			case 4: exit(0);
		}
		cout << "want to continue(y/n) - ";
		cin >> choice;
	}while(choice!='n');
 	return 0;
}
