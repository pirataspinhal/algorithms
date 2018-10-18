#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	int i=10;
	int &a=i;
	a=100;
	i=2000;
	cout<<i;
}
