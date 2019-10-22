#include<iostream>
using namespace std;
int main()
{
    cout<<"<--------170410107026-------->"<<endl<<endl;
    int n,indx=0,i,lalpha=0,cindx=0,lindx=1;
    char ss[10],alpha[10],temp[10];
    cout<<"Enter no. of sub production:";
    cin>>n;
    char sp[n][10],beta[n][10],c[n][10];
    cout<<"Enter special symbol:";
    cin>>ss;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter production "<<i+1<<":";
        cin>>sp[i];
    }
    for(i=0;sp[0][i]!='\0';i++)
    {
        alpha[i]=sp[0][i];
    }
    alpha[i]='\0';
    while(lindx<n)
    {
        if(alpha[indx]!=sp[lindx][indx] || alpha[indx]=='\0' || sp[lindx][indx]=='\0')
        {
                temp[indx]='\0';
                if(temp[0]!='\0')
                {
                     for(i=0;temp[i]!='\0';i++)
                     {
                        alpha[i]=temp[i];
                     }
                     alpha[i]='\0';
                }
                else
                {
                    for(i=0;sp[lindx][i]!='\0';i++)
                    {
                        c[cindx][i]=sp[lindx][i];
                    }
                    c[cindx][i]='\0';
                    cindx++;
                }
                lindx++;
                indx=0;
        }
        else
        {
            temp[indx]=sp[lindx][indx];
            indx++;
        }
    }
    for(int i=0;alpha[i]!='\0';i++)
    {
        lalpha++;
    }
    for(int i=0;i<n-cindx;i++)
    {
        indx=0;
        for(int j=lalpha;sp[i][j]!='\0';j++)
        {
            beta[i][indx++]=sp[i][j];
        }
        beta[i][indx]='\0';
    }
    for(int i=0;i<n-cindx;i++)
    {
        if(beta[i][0]=='\0')
        {
            beta[i][0]='$';
            beta[i][1]='\0';
        }
    }
    cout<<"\nAfter removing left Factor"<<endl<<endl;
    cout<<ss<<" -> "<<alpha<<ss<<"1 ";
    for(int i=0;i<cindx;i++)
    {
        cout<<" / "<<c[i];
    }
    cout<<endl;
    cout<<ss<<"1-> ";
    for(int i=0;i<n-cindx;i++)
    {
        if(i==0)
        {
            cout<<beta[i];
        }
        else
        {
            cout<<" / "<<beta[i];
        }
    }
    return 0;
}
