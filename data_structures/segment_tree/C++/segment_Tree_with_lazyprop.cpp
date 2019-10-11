#include<bits/stdc++.h>
#define MAX 1000 
using namespace std;
int tree[MAX] = {0}; // To store segment tree 
int lazy[MAX] = {0}; // To store pending updates 

void updateRangeUtil(int si, int ss, int se, int us, 
					int ue, int diff) 
{ 
	if (lazy[si] != 0) 
	{ 
		tree[si] += (se-ss+1)*lazy[si]; 

		if (ss != se) 
		{  
			lazy[si*2 + 1] += lazy[si]; 
			lazy[si*2 + 2] += lazy[si]; 
		} 
		lazy[si] = 0; 
	} 

	if (ss>se || ss>ue || se<us) 
		return ; 
	if (ss>=us && se<=ue) 
	{  
		tree[si] += (se-ss+1)*diff; 
		if (ss != se) 
		{ 
			lazy[si*2 + 1] += diff; 
			lazy[si*2 + 2] += diff; 
		} 
		return; 
	} 

	int mid = (ss+se)/2; 
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
	tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 

void updateRange(int n, int us, int ue, int diff) 
{ 
updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 

int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
	if (lazy[si] != 0) 
	{ 
		tree[si] += (se-ss+1)*lazy[si]; 
		if (ss != se) 
		{ 
			// Since we are not yet updating children os si, 
			// we need to set lazy values for the children 
			lazy[si*2+1] += lazy[si]; 
			lazy[si*2+2] += lazy[si]; 
		} 

		// unset the lazy value for current node as it has 
		// been updated 
		lazy[si] = 0; 
	} 
	if (ss>se || ss>qe || se<qs) 
		return 0; 
	if (ss>=qs && se<=qe) 
		return tree[si]; 
	int mid = (ss + se)/2; 
	return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
		getSumUtil(mid+1, se, qs, qe, 2*si+2); 
}  
int getSum(int n, int qs, int qe) 
{ 
	// Check for erroneous input values 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		printf("Invalid Input"); 
		return -1; 
	} 

	return getSumUtil(0, n-1, qs, qe, 0); 
} 

// A recursive function that constructs Segment Tree for 
// array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtil(int arr[], int ss, int se, int si) 
{ 
	// out of range as ss can never be greater than se 
	if (ss > se) 
		return ; 

	// If there is one element in array, store it in 
	// current node of segment tree and return 
	if (ss == se) 
	{ 
		tree[si] = arr[ss]; 
		return; 
	} 

	// If there are more than one elements, then recur 
	// for left and right subtrees and store the sum 
	// of values in this node 
	int mid = (ss + se)/2; 
	constructSTUtil(arr, ss, mid, si*2+1); 
	constructSTUtil(arr, mid+1, se, si*2+2); 

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 

/* Function to construct segment tree from given array. 
This function allocates memory for segment tree and 
calls constructSTUtil() to fill the allocated memory */
void constructST(int arr[], int n) 
{ 
	constructSTUtil(arr, 0, n-1, 0); 
}  
int main() 
{ 	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	constructST(arr, n); 
	cout<<"\nEnter the range for which sum is to be computed ";
	int l,h;
	cin>>l>>h;
	printf("Sum of values in given range = %d\n", 
		getSum(n, l, h));
	int val;	 
	cout<<"\nEnter the range for which value is to be updated and also enter the value to be added ";
	cin>>l>>h>>val;	
	updateRange(n, l, h, val); 
	printf("Updated sum of values in given range = %d\n", 
			getSum( n, l, h)); 

	return 0; 
} 

