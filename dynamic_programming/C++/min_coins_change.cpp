#include<iostream>
using namespace std;
int main()
 {
	int test,n,amount;
	cin>>test;
	while(test--){
	    cin>>amount>>n;
	    int coin[n];
	    for(int i=0;i<n;i++)
	    cin>>coin[i];
	    int am = amount+1;
	    int a[n][am];
	    
	    for(int i=0;i<n;i++)
	    a[i][0]=0;
	    
	    for(int i=1;i<am;i++)
	    a[0][i] = (i%coin[0]==0 ? i/coin[0] : -1 );
	    
	    for(int i=1;i<n;i++){
	        for(int j=1;j<am;j++){
	            
	            if(j<coin[i])
	            a[i][j] = a[i-1][j] ;
	            
	            else if(j==coin[i])
	            a[i][j]=1;
	            
	            else{
	                
	                if(a[i-1][j] == -1 && a[i][j-coin[i]] == -1)
	                a[i][j] = -1;
	                
	                else if(a[i-1][j] == -1)
	                a[i][j] = 1 + a[i][j-coin[i]] ;
	                
	                else if(a[i][j-coin[i]] == -1)
	                a[i][j] = a[i-1][j];
	                
	                else
	                a[i][j] = min(1 + a[i][j-coin[i]] , a[i-1][j]);
	                
	            }
	        }
	    }
	    cout<<a[n-1][am-1]<<endl;
	}
	return 0;
}
