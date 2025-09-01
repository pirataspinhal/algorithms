/*Problem description
This problem states that if we have a value x and we want to make change of x Rs. with an infinite supply of denominations(user defined),
we should use minimum number of coins to make the change.
Example: suppose we want change of Rs.153. This can be done in two ways:
A) 153=50+50+50+2+1 (5 coins used)
B) 153=100+50+2+1   (4 coins used)
According to algorithm, to make change of Rs. 153, option B is the best as less number of coins are used.
*/
#include <bits/stdc++.h>
 using namespace std;
 int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; //user defined denominations
int n = sizeof(deno)/sizeof(deno[0]);
 void minChange(int m)
{
     vector<int> v;
     for (int i=n-1; i>=0; i--)
    {
         while (m>=deno[i])
        {
           m-=deno[i];
           v.push_back(deno[i]);
        }
    }
     for (int i = 0; i < v.size(); i++)
           cout << v[i] << "  ";
}
 int main()
{
   int n;
   cout<<"Enter a value n for which you want minimal number of change: "<<'\n';
   cin>>n;
   cout << "Minimal number of change for " << n << " is: ";
   minChange(n);
   return 0;
}
