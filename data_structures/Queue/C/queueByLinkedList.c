#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

//void create_queue();
void enqueue();
void dequeue();
void display();
void peek();



int main()
{
    int option;
    //create_queue(q);
    front = rear = NULL;
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
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
        }
    }while(option != 5);
    return 0;
}

void create_queue()
{
    rear = NULL;
    front = NULL;
}

void enqueue()
{
    int n;
    struct node *node;
    printf("Enter value to insert : ");
    scanf("%d",&n);
    node = (struct node*)malloc(sizeof(struct node));
    node->data = n;
    node->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
};

void dequeue()
{
    int rem;
    struct node *temp;
    if(front == NULL)
    {
        printf("Empty");
        return;
    }
    else
    {
        rem = front->data;
        temp = front;
        front = front->next;
        free(temp);
    }
    printf("Removed : %d\n",rem);
};

void display()
{
    struct node *ptr;
    ptr = front;
    while(ptr != rear)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->data);

};

void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d\n",front->data);
    }
};
