#include <iostream>

using namespace std;

int main()
{
    int a[10], len = 10, beg, end, mid, n,val=0;
    beg=0;
    end = len-1;

    cout<<"Enter Sorted Numbers : "<<endl;
    for(int i=0;i<10;i++)
    {
        a[i] = ++val;
    }
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"Enter number to find : "<<endl;
    cin>>n;

    while(beg<=end)
    {
        mid = (beg+end)/2;

        if(n == a[mid])
        {
            cout<<"Found at Index : "<<mid<<endl;
            break;
        }



        if(a[mid] < n)
        {
            beg = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }

    if(beg>end)
    {
        cout<<"Not Found"<<endl;
    }
}
