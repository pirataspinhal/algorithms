#include<iostream>

using namespace std;

struct node{
int data;
node *next;
};

void PrintData(node*S)
{
    while(S!=NULL)
        {   cout<<S->data<<" ";
            S=S->next;
        }
}

void add_begin(node*S,int k)
{
    node*T;
    T=new (node);
    T->data=k;
    T->next=NULL;
    if (S!=NULL) T->next=S;
    S=T;
}



void add_af(node*S,int x, int y)
{
    node*T;
    while (S->data!=x)
        S=S->next;
    T=new(node);
    T->data=y;
    T->next=S->next;
    S->next=T;

}

void add_bef(node*S,int k, int l)
{
    node*T;
    while(S->next->data!=l)
        S=S->next;
    T=new(node);
    T->data=k;
    T->next=S->next;
    S->next=T;
}




void add_end(node*S,node*L,int k)
{
    L=S;
    while(L->next!=NULL)
        L=L->next;
    L->next=new(node);
    L->next->data=k;
    L->next->next=NULL;
}

int main()
{
    int d;
    node*L;
    node*S;
    node*T;
    L=new(node);
    S=new(node);
    cin>>d;
    L->data=d;
    L->next=NULL;
    S=L;
    cin>>d;
      //List Adding
    while(d!=-1)
    {
        T=new(node);
        T->data=d;
        T->next=NULL;
        L->next=T;
        L=T;

        cin>>d;
    }
    PrintData(S);

    cout<<endl;

    add_end(S,L,5);
    PrintData(S);
    add_begin(L,6);
    cout<<endl;
    PrintData(S);
    cout<<endl;
    add_af(S,2,3);
    PrintData(S);
    cout<<endl;
    add_bef(S,45,2);
    PrintData(S);
return 0;
}