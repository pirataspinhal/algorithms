#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNewNode(int num)
{
    struct node* node;
    node = (struct node*)malloc(sizeof(struct node));
    node->left = NULL;
    node->data = num;
    node->right = NULL;
    return node;
};

struct node* insertNode(struct node* root, int num)
{
    if(root == NULL)
    {
        root = createNewNode(num);
    }
    else if(num <= root->data)
    {
        root->left = insertNode(root->left,num);
    }
    else
    {
        root->right = insertNode(root->right,num);
    }

    return root;
};

int maxElement(struct node* root)
{
    if(root == NULL)
        return 0;
    else if(root->right != NULL)
        maxElement(root->right);
    else
        return (root->data);
}

int minElement(struct node* root)
{
    if(root == NULL)
        return 0;
    else if(root->left != NULL)
        minElement(root->left);
    else
        return (root->data);
}

int findHeight(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root != NULL)
    {
        int lheight = findHeight(root->left);
        int rheight = findHeight(root->right);

        if(lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

int searchNode(struct node* root, int num)
{
    if(root == NULL)
        return 0;
    else if(root->data == num)
        return 1;
    else if(num <= root->data)
        return searchNode(root->left,num);
    else
        return searchNode(root->right,num);
}

void printLevel(struct node* root, int level)
{
    if(root == NULL)
        return;
    else if(level == 1)
        printf("%d\n",root->data);
    else if(level>1)
    {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

void printGivenLevel(struct node* root)
{
    int h = findHeight(root);
    int i;
    for(i=1;i<=h;i++)
        printLevel(root,i);
}



//dfs
//pre-order
void preorderTraverse(struct node* root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d\n",root->data);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

//in-order
void inorderTraverse(struct node* root)
{
    if(root==NULL)
        return;
    else
    {
        inorderTraverse(root->left);
        printf("%d\n",root->data);
        inorderTraverse(root->right);
    }
}

//post-order
void postorderTraverse(struct node* root)
{
    if(root==NULL)
        return;
    else
    {
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        printf("%d\n",root->data);
    }
}

//chk if binary tree is present or not
int isSubtreeLesser(struct node* root, int value)
{
    if(root==NULL)
        return 0;
    if(root->data <= value && isSubtreeLesser(root->left,value) &&
       isSubtreeLesser(root->right,value))
        return 1;
    else
        return 0;
}

int isSubtreeGreater(struct node* root, int value)
{
    if(root==NULL)
        return 0;
    if(root->data > value && isSubtreeGreater(root->left,value) &&
       isSubtreeGreater(root->right,value))
        return 1;
    else
        return 0;
}

int isBinarySearchTree(struct node* root)
{
    if(root==NULL)
        return 0;

    if(isSubtreeLesser(root->left,root->data) && isSubtreeGreater(root->right,root->data) &&
       isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//checking BST by finding max/min
int chkBST(struct node* root)
{
    int min = minElement(root->left);
    int max = maxElement(root->right);
    if(min <= root->data && max > root->data)
        return 1;
    else
        return 0;
}

struct node* findMin(struct node* root)
{
    if(root == NULL)
        return root;
    else if(root->left != NULL)
        minElement(root->left);
    else
        return root;
}

struct node* deleteNode(struct node* root, int data)
{
    if(root==NULL)
        return root;
    else if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else
    {
        //1. leaf node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        //2. one child
        else if(root->left == NULL)
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        //3. two children
        else
        {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
};

//inorder successor
struct node* find(struct node* root, int data)
{
    if(root==NULL)
        return;
    else if(data < root->data)
    {
        find(root->left,data);
    }
    else if(data > root->data)
    {
        find(root->right,data);
    }
    else
    {
        return root;
    }
};

struct node *getSuccessor(struct node* root, int data)
{
    struct node* current = find(root,data);
    if(root == NULL)
        return NULL;
    else if(current->right != NULL)
    {
        return findMin(current->right);
    }
    else
    {
        struct node* successor = NULL;
        struct node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
};

//count nodes
int countNodes(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
            return 1;
        else
            return(1 + (countNodes(root->left) + countNodes(root->right)));
    }
}

//checking BST by inorder
int chkBstInorder(struct node* root)
{
  printf("Under Const");
}

int main()
{
    struct node* root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,10);
    root = insertNode(root,20);
    root = insertNode(root,25);
    root = insertNode(root,8);
    root = insertNode(root,12);
    root = insertNode(root,11);

//    root = insertNode(root,5);
//    root = insertNode(root,3);
//    root = insertNode(root,10);
//    root = insertNode(root,1);
//    root = insertNode(root,4);
//    root = insertNode(root,11);


    //search
    printf("\n:: Finding Element in Tree :: \n");
    int flag = searchNode(root,21);
    if(flag == 1)
        printf("True\n");
    else
        printf("False\n");

    //min/max
    printf("\n:: Min/Max in Tree :: \n");
    printf("Max : %d\n",maxElement(root));
    printf("Min : %d\n",minElement(root));

    //height
    printf("\n:: Height of Tree :: \n");
    printf("Height : %d\n",findHeight(root));

    //bfs
    printf("\n:: BFS :: \n");
    printGivenLevel(root);

    //pre-order
    printf("\n:: Pre-order Traversal :: \n");
    preorderTraverse(root);

    //in-order
    printf("\n:: In-order Traversal :: \n");
    inorderTraverse(root);

    //post-order
    printf("\n:: Post-order Traversal :: \n");
    postorderTraverse(root);

    //checking BST or not by min/max
    printf("\n:: Checking BST by Min/Max :: \n");
    if(chkBST(root))
        printf("It's BST.\n");
    else
        printf("It's Not BST.\n");

    //checking BST or not by Inorder
    printf("\n:: Checking BST by Inorder :: \n");

    //deleting node
    printf("\n:: Node Deleted ::\n");
    root = deleteNode(root,21);

    printf("\n :: After Node Deletion ::\n");
    printGivenLevel(root);

    //getting successor
    printf("\n :: Inorder Successor  ::\n");
    struct node* successor;
    successor = getSuccessor(root,12);
    printf("Successor : %d\n",successor->data);


}
