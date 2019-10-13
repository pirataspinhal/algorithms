#include <bits/stdc++.h>
using namespace std;

int main()
{
int n,i,k;

//Enter the amount of numbers to sort
cin>>n;
int a[n],b[n];

//Input
for(i=0;i<n;i++)
cin>>a[i];

//Counting Sort
k=a[0];
for(i=1;i<n;i++)
{
if(k<a[i])
k=a[i];
}

int c[k+1]={0};

for(i=0;i<n;i++)
{
c[a[i]]++;
}

for(i=1;i<=k;i++)
{
c[i]=c[i-1]+c[i];
}

for(i=n-1;i>=0;i--)
{
b[c[a[i]]-1]=a[i];
c[a[i]]--;
}

//Output
for(i=0;i<n;i++)
{
cout<<b[i]<<" ";
}



}
