#include <iostream>
using namespace std;
int main()
{
    int n, N;
    cout << "Enter the number of coins available: ";
    cin >> n;
    int * arr = new int[n];
    cout << "Enter the values of coins.. \n";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the amount to be paid: ";
    cin >> N;
    int C[n][N+1];
    for(int i=0; i<n; i++)
    {
        C[i][0] = 0;
        for(int j=1; j<=N; j++)
        {
            if(j<arr[i] && i==0)
                C[i][j] = 9999;
            else if(j>=arr[i] && i==0)
                C[i][j] = 1 + C[i][j-arr[i]];
            else if(j<arr[i])
                C[i][j] = C[i-1][j];
            else if(j>=arr[i])
                C[i][j] = min( C[i-1][j],1+C[i][j-arr[i]]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=N; j++)
        {
            cout << C[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "The minimum no. of coins needed to pay the amount " << N << " is Rs. " << C[n-1][N];
    return 0;
}
