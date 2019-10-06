#include<bits/stdc++.h>

using namespace std;

int a[100000]={0};

long long fib(int n){
	if(n==0 || n==1){
		a[n]=n;
		return a[n];
	}
	else if(a[n]){
		return a[n];
	}
	else{
		a[n]=fib(n-1)+fib(n-2);
		return a[n];
	}
}

int main(){
	int n;
	cin>>n;
	long long ans=fib(n);
	cout<<ans<<endl;
	return 0;
}
