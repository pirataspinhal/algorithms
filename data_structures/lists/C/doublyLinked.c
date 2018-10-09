#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *ptr;
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
            node->prev = NULL;
            head = node;
            node->next = NULL;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
            node->prev = ptr;
            node->next = NULL;
        }
        printf("Enter num (-1 to end) :");
        scanf("%d",&num);
    }
    return head;
}

struct node* display(struct node* head)
{
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return head;
}

struct node* insertBeg(struct node* head)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter num : ");
    scanf("%d",&num);

    node->data = num;
    node->prev = NULL;
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
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next = NULL;
    node->prev = ptr;
    return head;
}

struct node *insertAfter(struct node *head)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    int num,val;
    printf("Enter num : ");
    scanf("%d",&num);
    printf("Enter after value: ");
    scanf("%d",&val);
    node->data = num;
    ptr = head;
    while(ptr->data != val)
    {
        ptr = ptr->next;
    }
    ptr->next->prev = node;
    node->next = ptr->next;
    ptr->next = node;
    node->prev = ptr;

    return head;
}

struct node *insertBefore(struct node *head)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    int num,val;
    printf("Enter num : ");
    scanf("%d",&num);
    printf("Enter before value: ");
    scanf("%d",&val);
    node->data = num;
    ptr = head;
    while(ptr->data != val)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = node;
    node->prev = ptr->prev;
    node->next = ptr;
    ptr->prev = node;

    return head;
}

struct node *deleteBeg(struct node *head)
{
    ptr = head;
    ptr->next->prev = NULL;
    head = ptr->next;
    free(ptr);
    return head;
}

struct node *deleteEnd(struct node *head)
{
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return head;
}

struct node *deleteNode(struct node *head)
{
    int val;
    printf("Enter value to delete : ");
    scanf("%d",&val);
    ptr = head;
    if(head->data == val)
    {
        head = deleteBeg(head);
        return head;
    }
    else
    {
        while(ptr->data != val)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return head;
    }
}

struct node *deleteList(struct node *head)
{
    if(head != NULL)
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            head = deleteBeg(ptr);
            ptr = head;
        }
        free(ptr);
        head = NULL;
    }
    return head;
}

struct node *sortList(struct node *head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    if(head == NULL)
    {
        return head;
    }
    else
    {
        while(ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while(ptr2 != NULL)
            {
                if(ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
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
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete the entire list");
        printf("\n 11: Sort the list");
        printf("\n 12: EXIT");
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
            case 5: head = insertBefore(head);
            break;
            case 6: head = insertAfter(head);
            break;
            case 7: head = deleteBeg(head);
            break;
            case 8: head = deleteEnd(head);
            break;
            case 9: head = deleteNode(head);
            break;
            case 10: head = deleteList(head);
            printf("\n LINKED LIST DELETED");
            break;
            case 11: head = sortList(head);
            break;
        }
    }while(option!=12);
}
