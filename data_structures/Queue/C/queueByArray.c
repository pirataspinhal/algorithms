#include <stdio.h>

#define MAX 10

int front = -1, rear = -1;

void enqueue(int a[]);
void dequeue(int a[]);
void display(int a[]);
void peek(int a[]);

void main()
{
    int ar[MAX];
    int option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: enqueue(ar);
            break;
            case 2: dequeue(ar);
            break;
            case 3: peek(ar);
            break;
            case 4: display(ar);
            break;
        }
    }while(option != 5);
    return 0;
}

void enqueue(int a[])
{
    int n;
    if(rear >= MAX-1)
    {
        printf("Full");
        return;
    }
    printf("Enter number : ");
    scanf("%d",&n);
    if(front==-1 && rear == -1)
    {
        front=rear=0;
    }
    else
    {
        rear += 1;
    }
    a[rear] = n;
}

void dequeue(int a[])
{
    int del;
    if(front == -1 || front > rear)
    {
        printf("Empty");
        return;
    }
    else
    {
        del = a[front];
        front+=1;
    }
    printf("Deleted element : %d",del);
}

void display(int a[])
{
    int i;
    for(i=front; i<=rear;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("\n");
}

void peek(int a[])
{
    if(front == -1)
        printf("Empty");
    else
        printf("Element on front : %d\n",a[front]);
}
