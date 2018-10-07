#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;

int n,m;
string s,t;
int memo[MAX][MAX];

int dp(int i,int j){
	if (i == n) return 0;
	if (j == m) return 0;
	
	int &ret = memo[i][j];
	if (ret != -1) return ret;
	
	ret = dp(i+1,j);
	ret = max(ret,dp(i,j+1));
	if (s[i] == t[j]) ret = max(ret,dp(i+1,j+1)+1);

	return ret;
}


int main(){
	cin>>s>>t;
	n = s.size();
	m = t.size();
	
	memset(memo,-1,sizeof memo);
	cout<<dp(0,0)<<endl;
	
	return 0;
}
