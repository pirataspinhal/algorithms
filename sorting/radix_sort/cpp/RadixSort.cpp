#include <bits/stdc++.h>
using namespace std;

int Max(int *a,int n)
{
int k=a[0];
for(int i=1;i<n;i++)
{
if(a[i]>k)
k=a[i];
}
return k;

}
int counting(int *a, int exp, int n)
{
int b[n];
int c[10]={0};
int i,j;
for(i=0;i<n;i++)
c[(a[i]/exp)%10]++;
for(i=1;i<10;i++)
c[i]=c[i-1]+c[i];
for(i=n-1;i>=0;i--)
{
b[c[(a[i]/exp)%10]-1]=a[i];
c[(a[i]/exp)%10]--;
}

for(i=0;i<n;i++)
a[i]=b[i];
}

int radixsort(int *a, int n)
{
int exp,k;
k=Max(a,n);
for(exp=1;(k/exp)>0;exp=exp*10)
counting(a,exp,n);
//cout<<k;
}

int main()
{
int n,i,k;
//Enter the amount of numbers to sort
cin>>n;
int a[n],b[n];

//Input
for(i=0;i<n;i++)
cin>>a[i];

//radix sort
radixsort(a,n);

//Output
for(i=0;i<n;i++)
cout<<a[i]<<" ";

}
