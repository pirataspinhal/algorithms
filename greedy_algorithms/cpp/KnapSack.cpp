#include <iostream>
using namespace std;
float *w,*w1,*v,*v1,W, *v_w,*x;
int n;

int max_value(float* v_w)
{
    float maxx=0;
    int index;
    for(int i=0;i<n;i++)
    {
        if(maxx < v_w[i] && x[i] == 0)
        {
            maxx = v_w[i];
            index = i;
        }
    }

    return index;
}

int main()
{
    float value=0,weight = 0;
    int index;
    cout<<"Enter no. of weights: ";
    cin>>n;

    w = new float[n];
    v = new float[n];
    v_w = new float[n];
    x = new float[n];

    for(int i=0;i<n;i++)
    {
        x[i] = 0;
    }
    cout<<"Enter the Weights:\n";
    for(int i=0; i<n;i++)
    {
        cin>>w[i];
    }

    cout<<"Enter the values:\n";
    for(int i=0; i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        v_w[i] = v[i] / w[i];
    }
    cout<<"Enter the knapsack Capacity: ";
    cin>>W;

    cout<<"The given data are:\n";
    cout<<"w[]: ";
    for(int i=0;i<n;i++)
        cout<<w[i]<<" ";
    cout<<"\nv[]: ";
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<"\nv/w[]: ";
    for(int i=0;i<n;i++)
        cout<<v_w[i]<<" ";
    while(weight<W){
        index = max_value(v_w);
        if(weight + w[index] <= W ) {
            x[index]  = 1;
            weight = weight + w[index];
        } else {
            x[index] = (W - weight)/w[index];
            weight = W;
        }
    }
    cout<<"\nOutput:";
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
