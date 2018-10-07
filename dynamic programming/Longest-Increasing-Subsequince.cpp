/*
 * A Solution to the classical LIS problem in dynamic programming. 
 * Time Complexity O(N^2)
 * Memory Copmlexity O(N^2)
 */
 
#include<bits/stdc++.h>
using namespace std;

// Setting up Maximum limit
const int MAX = 1010;

// Pre-defining all needed variables
int n;
int a[MAX];
int memo[MAX][MAX];


// The Main solution
int dp(int idx,int lst){
	// Setting up base case
	if (idx > n) return 0;
	
	// return memoized info (if possible).
	int &ret = memo[idx][lst];
	if (ret != -1) return ret;
	
	// Choise one do not add this element
	ret = dp(idx+1,lst);
	// Choise two if possible get the maximum between leaving or adding this element
	if (a[idx] > a[lst]) ret = max(ret, 1 + dp(idx+1,idx));
	
	// Return best value
	return ret;
}

int main(){
	// Getting input
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	// Erase all data before memoization
	memset(memo,-1,sizeof memo);
	
	// Get the answer
	cout<<dp(1,0)<<endl;
	
	return 0;
}
