#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;

int n;
int a[MAX];
int memo[MAX][MAX];

int dp(int idx,int lst){
	if (idx > n) return 0;
	
	int &ret = memo[idx][lst];
	if (ret != -1) return ret;
	
	ret = dp(idx+1,lst);
	if (a[idx] > a[lst]) ret = max(ret, 1 + dp(idx+1,idx));
	
	return ret;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	memset(memo,-1,sizeof memo);
	cout<<dp(1,0)<<endl;
	
	return 0;
}
