#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *start = NULL;

void insertbeg(int ele)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=ele;
    p->next=start;
    start=p;
}

void insertend(int ele)
{
    node *p,*q;
    p=(node*)malloc(sizeof(node));
    p->data=ele;
    p->next=NULL;
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}

int count()
{
    int c;
    node *q=start;
    while(q!=NULL)
    {
        c++;
        q=q->next;
    }
    return c;
}

int search(int ele)
{
    node *q=start;
    while(q!=NULL)
    {
        if(q->data==ele)
            return 1;
        else
            q=q->next;
    }
    return 0;
}

void reverse()
{
    node*p=start,*q=NULL,*r;
    while(p!=NULL)
    {
        r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    start=q;
}

void display()
{
    node *q;
    if(start==NULL)
    {
        printf("Linked List empty\n");
        return;
    }
    q=start;
    while(q!=NULL)
    {
        printf("%d ", q->data);
        q=q->next;
    }
}

int deleteele(int ele)
{
    node *p, *q;
    if(start==NULL)
    {
        printf("Linked List empty\n");
        return -1;
    }
    if(start->data==ele)
    {
        start=start->next;
        return;
    }
    q=start;
    while(q->next!=NULL)
    {
        if(q->next->data==ele)
            break;
        else
            q=q->next;
    }
    if(q==NULL)
        printf("Element not found\n");
    else
        q->next=q->next->next;
}

void main()
{
    int ch,ele,z;
    while(1)
    {
        printf("Enter choice: 1. Insertbeg 2. Insertend 3. Delete ele 4. Count 5. Search 6. Reverse 7. Display 8. Exit - ");
        scanf("%d", &ch);
        if(ch==8)
            break;
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted\n");
                scanf("%d",&ele);
                insertbeg(ele);
                display();
                break;
            case 2:
                printf("Enter element to be inserted\n");
                scanf("%d",&ele);
                insertend(ele);
                display();
                break;
            case 3:
                printf("Enter element to be deleted\n");
                scanf("%d",&ele);
                deleteele(ele);
                display();
                break;
            case 4:
                z=count();
                printf("Count = %d", z);
                break;
            case 5:
                printf("Enter element to be searched\n");
                scanf("%d",&ele);
                z=search(ele);
                if(z==1)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 6:
                reverse();
                display();
                break;
            case 7:
                display();
                break;
        }
    }
}
