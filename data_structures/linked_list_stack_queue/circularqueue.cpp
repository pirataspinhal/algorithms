//circular queue algo
//muskan09
#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};
node *start;
void insert(int x)
{
	node *tm=start;
	
	if (start!=NULL)
	{
		while(tm->next!=start)
		{
			tm=tm->next;
		}
		node *n= new node;
		tm->next=n;
		n->value=x;
		n->next=start;
	}
	else
	{
		node *n= new node;
		n->value=x;
		start=n;
		n->next=start;
	}
}
void remove(int x)
{
	node *tm=start;
	node *p;
	while(tm->value!=x)
	{
		p=tm;
		tm=tm->next;
	}
	p->next=tm->next;
	delete tm;
}
void search(int x)
{
	node *tm= start;
	int found =0;
	while(tm->next!=start)
	{
		if(tm->value==x)
		{
			cout<<"\nFound";
			found=1;
			break;
		}
		tm=tm->next;
	}
	if(found==0)
	{
		cout<<"\nNot Found";
	}
}
void show()
{
	node *tm=start;
	do
	{
		cout<<tm->value<<"\t";
		tm=tm->next;
	}
	while(tm!=start);
}
int main()
{
	int choice, x;
	do
	{
		cout<<"\n1. Insert";
		cout<<"\n2. Delete";
		cout<<"\n3. Search";
		cout<<"\n4. Print";
		cout<<"\n\nEnter you choice : ";
		cin>>choice; 
		switch (choice)
		{
			case 1 : 	cout<<"\nEnter the element to be inserted : ";
					 	cin>>x;
					 	insert(x);	break;
			case 2 : 	cout<<"\nEnter the element to be removed : ";
						cin>>x;
						remove(x); 	break;
			case 3 : 	cout<<"\nEnter the element to be searched : ";
						cin>>x;
						search(x); 	break;
			case 4 : show();	break;
		}
	}
	while(choice!=0);
	return 0;
}
