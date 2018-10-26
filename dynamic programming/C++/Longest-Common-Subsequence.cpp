/*
 * A Solution to the classical LCS problem in dynamic programming. 
 * Time Complexity O(N^2)
 * Memory Copmlexity O(N^2)
 */

#include<bits/stdc++.h>
using namespace std;


// Setting up Maximum Limit
const int MAX = 1010;


// Pre-defining all needed variables
int n,m;
string s,t;
int memo[MAX][MAX];

// The main solution
int dp(int i,int j){
	
	// Setting up DP base case
	if (i == n) return 0;
	if (j == m) return 0;
	
	// return memoized info (if possible).
	int &ret = memo[i][j];
	if (ret != -1) return ret;
	
	// leave string s
	ret = dp(i+1,j);
	// Maximize with the state of leaving string t
	ret = max(ret,dp(i,j+1));
	// If ith letter in s equals to jth in t the maximize with the state of taking both letters
	if (s[i] == t[j]) ret = max(ret,dp(i+1,j+1)+1);

	// return best value
	return ret;
}


int main(){
	
	// Getting input
	cin>>s>>t;
	n = s.size();
	m = t.size();
	
	// Erase all data before memoization
	memset(memo,-1,sizeof memo);
	
	// Get the answer
	cout<<dp(0,0)<<endl;
	
	return 0;
}
