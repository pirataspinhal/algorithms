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
            node->next = NULL;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
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
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = node;
    node->next = ptr;
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
    preptr=ptr;
    while(preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = node;
    node->next = ptr;
    return head;
}

struct node *deleteBeg(struct node *head)
{
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteEnd(struct node *head)
{
    ptr = head;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
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
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

struct node *deleteList(struct node *head)
{
    if(head != NULL)
    {
        ptr = head;
        while(ptr != NULL)
        {
            head = deleteBeg(ptr);
            ptr = head;
        }
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

struct node* swapNodes(struct node* head)
{
    struct node *ptr1, *ptr2, *pre1, *pre2, *temp;
    int val1, val2;
    ptr1 = head;
    ptr2 = head;
    pre1 = NULL;
    pre2 = NULL;

    printf("Enter first value : ");
    scanf("%d",&val1);
    printf("Enter second value : ");
    scanf("%d",&val2);

    //if values are same, no need to swap
    if(val1 == val2)
        return;

    while(ptr1->data != val1)
    {
        pre1 = ptr1;
        ptr1 = ptr1->next;
    }

    while(ptr2->data != val2)
    {
        pre2 = ptr2;
        ptr2 = ptr2->next;
    }

    //if there are no nodes present
    if(ptr1 == NULL || ptr2 == NULL)
    {
        return;
    }

    //checking if the swapping nodes are head or not
    if(pre1 != NULL)
        pre1->next = ptr2;
    else
        head = ptr2;

    if(pre2 != NULL)
        pre2->next = ptr1;
    else
        head = ptr1;

    //swapping
    temp = ptr2->next;
    ptr2->next = ptr1->next;
    ptr1->next = temp;

    return head;
}

struct node* reverseList(struct node* head)
{
    struct node *prev = NULL, *curr = head, *nxt;
    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
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
        printf("\n 12: Swap nodes");
        printf("\n 13: Reverse List");
        printf("\n 14: EXIT");
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
            case 12: head = swapNodes(head);
            break;
            case 13: head = reverseList(head);
            break;
        }
    }while(option!=14);
}
