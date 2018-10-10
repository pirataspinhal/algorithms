#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *ptr;
struct node *preptr;
struct node *head = NULL;

struct node *createList(struct node *head)
{
    int num;
    struct node *ptr, *node;
    printf("Enter num (-1 to end): ");
    scanf("%d",&num);
    while(num!=-1)
    {
        ptr = head;
        node = (struct node*)malloc(sizeof(struct node));
        node->data = num;
        if(ptr == NULL)
        {
            head = node;
            node->next = head;
        }
        else
        {
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
            node->next = head;
        }
        printf("Enter num (-1 to end) :");
        scanf("%d",&num);
    }
    return head;
}

struct node* display(struct node* head)
{
    ptr = head;
    while(ptr->next != head)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
    return head;
}

struct node *insertBeg(struct node* head)
{
    int num;
    struct node* node = (struct node*)malloc(sizeof(struct node));
    printf("Enter num : ");
    scanf("%d",&num);
    node->data = num;
    ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next = head;
    head = node;
    return head;
}

struct node *insertEnd(struct node *head)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter num : ");
    scanf("%d",&num);
    node->data = num;
    ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next = head;
    return head;
}

struct node *deleteBeg(struct node *head)
{
    ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;
}

struct node *deleteEnd(struct node *head)
{
    ptr = head;
    while(ptr->next != head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}

struct node *deleteList(struct node *head)
{

        ptr = head;
        while(ptr->next != head)
        {
            head = deleteEnd(head);
        }
        free(head);

    return head;
}

int main()
{
    int option;
    do
    {
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");


        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");

        printf("\n 7: Delete the entire list");

        printf("\n 8: EXIT");
        printf("\n Enter option :");
        scanf("%d", &option);

        switch(option)
        {
            case 1: head = createList(head);
            break;
            case 2: head = display(head);
            break;
            case 3: head = insertBeg(head);
            break;
            case 4: head = insertEnd(head);
            break;
            case 5: head = deleteBeg(head);
            break;
            case 6: head = deleteEnd(head);
            break;
            case 7: head = deleteList(head);
            printf("\n LINKED LIST DELETED");
            break;
        }
    }while(option!=8);
}
