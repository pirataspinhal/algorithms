#include<bits/stdc++.h>
using namespace std;
int LUP[10000];
int fib(int n)
{if(n==0)
	return 0;
if(n==1)
{LUP[1]=1;return 1;}

if(LUP[n]!=0)
return LUP[n];
	

	else if(n==2)
	{LUP[n-1]=n-1; return n-1;}

	LUP[n]= fib(n-1)+fib(n-2);
	return LUP[n];
}
int main()
{	
	int i,n;
for(i=0;i<10000;i++)
	LUP[i]=0;


cin>>n;
cout<<fib(n);
return 0;

}
