#include <stdio.h>
#include <stdlib.h>


struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* newNode()
{
    int n;
    printf("enter number : ");
    scanf("%d",&n);
    struct node *node = (struct node*)malloc(sizeof(struct node));

    node->data = n;
    node->left = NULL;
    node->right = NULL;

    return node;
};

//BFS
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for(i=1;i<=h;i++)
        printGivenLevel(root,i);
}

int height(struct node* node)
{
    if(node==NULL)
        return;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

void printGivenLevel(struct node *root, int level)
{
    if(root == NULL)
        return;
    else if(level == 1)
        printf("%d\n",root->data);
    else if(level > 1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

//DFS
void printPostorder(struct node* node)
{
    if(node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d\n",node->data);
}

void printPreorder(struct node* node)
{
    if(node == NULL)
        return;

    printf("%d\n",node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct node* node)
{
    if(node == NULL)
        return;

    printInorder(node->left);
    printf("%d\n",node->data);
    printInorder(node->right);
}

int main()
{
    struct node* root;

    root = newNode();

    root->left = newNode();
    root->right = newNode();

    root->left->left = newNode();
    root->left->right = newNode();

    printf("\n\n\t Post Order\n");
    printPostorder(root);

    printf("\n\n\t Pre Order\n");
    printPreorder(root);

    printf("\n\n\t In Order\n");
    printInorder(root);

    printf("\n\n\t Breadth First Traversal Order\n");
    printLevelOrder(root);

}
