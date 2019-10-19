// For problem statement and I/O Format, visit: https://practice.geeksforgeeks.org/problems/maximum-sum-path-in-two-arrays/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int test,m,n;
     cin>>test;
     while(test--){
         cin>>n>>m;
         int a1[n], a2[m];
         for(int i=0;i<n;i++)
         cin>>a1[i];
         for(int i=0;i<m;i++)
         cin>>a2[i];
         int count=0,i=0,j=0,sum1=0,sum2=0;
         while(i<n && j<m){
             if(a1[i]==a2[j]){
                 while (i < n &&  j < m && a1[i] == a2[j]){
                     count = count + a1[i++];
                     j++; 
                 }
                 count += max(sum1,sum2);
                 sum1 = 0;
                 sum2 = 0;
             }
             else if(a1[i]<a2[j]){
                 sum1+=a1[i];
                 i++;
             }
             else if(a1[i]>a2[j]){
                 sum2+=a2[j];
                 j++;
             }
         }
         if(i<n || j<m){
         if(i<n){
             while(i<n){
                 sum1+=a1[i++];
             }
         }
         if(j<m){
             while(j<m){
                 sum2+=a2[j++];
             }
         }
         count += max(sum1,sum2);
         }
         cout<<count<<endl;
     }
	//code
	return 0;
}
