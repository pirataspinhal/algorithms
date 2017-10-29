#include <iostream>
#include <cstdlib>
#define MAX 50
using namespace std;
 
/* 
 * Node Declaration
 */
struct Node
{
    char data;
    unsigned isEndOfString: 1;
    Node *left, *eq, *right;
};
/* 
 * create a new ternary search tree node
 */ 
Node* newNode(char data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
/* 
 * insert a new word in a Ternary Search Tree
 */ 
void insert(Node** root, char *word)
{
    if (!(*root))
        *root = newNode(*word);
    if ((*word) < (*root)->data)
        insert(&((*root)->left), word);
    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word);
    else
    {
        if (*(word + 1))
            insert(&( (*root)->eq ), word + 1);
        else
            (*root)->isEndOfString = 1;
    }
}
/* 
 * traverse Utility function
 */  
void traverseTSTUtil(Node* root, char* buffer, int depth)
{
    if (root)
    {
        traverseTSTUtil(root->left, buffer, depth);
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            cout<<buffer<<endl;
        }
        traverseTSTUtil(root->eq, buffer, depth + 1);
        traverseTSTUtil(root->right, buffer, depth);
    }
}
/* 
 * traverse Ternary Search Tree
 */  
void traverseTST(Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
/* 
 * search a given word in Ternary Search Tree
 */  
int searchTST(Node *root, char *word)
{
    if (!root)
        return 0;
    if (*word < (root)->data)
        return searchTST(root->left, word);
    else if (*word > (root)->data)
        return searchTST(root->right, word);
    else
    {
        if (*(word + 1) == '\0')
            return root->isEndOfString;
        return searchTST(root->eq, word+1);
    }
}
 
/* 
 * Main
 */  
int main()
{
    Node *root = NULL;
    char s[100];
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
    cout<<"Following is traversal of ternary search tree\n";
    traverseTST(root);
    cout<<"Enter string to search: ";
    cin>>s;
    if (searchTST(root, s))
        cout<<s<<" found in Ternary Search Tree"<<endl;
    else
        cout<<s<<" not found in Ternary Search Tree"<<endl;
    return 0;
}
