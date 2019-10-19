#include<iostream>
using namespace std;

int bin_search(int arr[],int low, int high, int x)
{
    int mid;
    while(low<=high)
    {
        mid = (low + high)/2;
        if( arr[mid] == x)
        {
        return mid;
        }
        else if(x < arr[mid])
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -99;
}
int main()
{
    int *arr,i,j,n,item,flag;
    cout<<"Enter the no. of elements:";
    cin>>n;
    cout<<"Enter the elements(in ascending order):\n";
    arr=new int[n];
    for(i=0;i<n;i++)
    {
        cout<<"["<<i<<"]:";
        cin>>arr[i];
    }
    cout<<"original array:\n";
    for(i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }

    cout<<"\nEnter the element to be searched:";
    cin>>item;

    flag = bin_search(arr,0,n-1,item);
    if(flag == -99)
    {
        cout<<"\nElement not found";
    }
    else
    {
        cout<<"\nElement found at "<<flag + 1<<" position!!!";
    }
}
