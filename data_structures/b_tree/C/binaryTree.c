#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *newNode()
{
    int num;
    struct node *node;
    printf("Enter num (-1 to end): ");
    scanf("%d",&num);

    node = (struct node*)malloc(sizeof(struct node));
    node->data = num;
    node->right = NULL;
    node->left = NULL;

    return node;
}


int main()
{
    struct node* node;
    node = newNode();
    node->left = newNode();
    node->right = newNode();

    node->left->left = newNode();
    node->left->right = newNode();
}
