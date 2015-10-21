/*-------------------------------------------------------
	ICMC - University of Sao Paulo
	 __  __  ____    ____    
	/\ \/\ \/\  _`\ /\  _`\  
	\ \ \ \ \ \,\L\_\ \ \L\ \
	 \ \ \ \ \/_\__ \\ \ ,__/
	  \ \ \_\ \/\ \L\ \ \ \/ 
	   \ \_____\ `\____\ \_\ 
	    \/_____/\/_____/\/_/ 
	                         
				HEAP
	(c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP* createHeap() {

	HEAP* tree = (HEAP*)malloc(sizeof(TREE));
	
	if (tree != NULL) {
		tree->root = NULL;
	}

	return tree;

}

NODE* createRoot(HEAP* tree, int content) {

	tree->root = (NODE*)malloc(sizeof(NODE));
	if(tree->root != NULL) {
		tree->root->right = NULL;
		tree->root->left = NULL;
		tree->root->value = content;
	}

	return (tree->root);

}

NODE* insertChild(int child, NODE *node, int content) {

	NODE *new = (NODE*)malloc(sizeof(NODE));

	if(new != NULL) {

		new->right = NULL;
		new->left = NULL;
		new->value = content;

		if (child == left_child) {
			node->left = new;
		} else {
			node->right = new;
		}

	}

	return new;

}

/*-------------------------------------------------------
	HEAP TRAVERSING FUNCTIONS
---------------------------------------------------------*/

void __pre_order(NODE *root) {

	if(root != NULL) {
		printNode(root);
		__pre_order(root->left);
		__pre_order(root->right);
	}
}

void pre_order(HEAP* tree) {

	__pre_order(tree->root);

}

void __in_order(NODE *root) {

	if(root != NULL) {
		__in_order(root->left);
		printNode(root);
		__in_order(root->right);
	}
}

void in_order(HEAP *tree) {
	__in_order(tree->root);
}

void __post_order(NODE *root) {
	if(root != NULL) {
		__post_order(root->left);
		__post_order(root->right);
		printNode(root);
	}
}

void post_order(HEAP *tree) {
	__post_order(tree->root);
}

/*-------------------------------------------------------
	AUXILIAR FUNCTIONS
---------------------------------------------------------*/

void printNode(NODE *node) {
	printf("\t[ %d ]\n", node->value);
}

void __delete_tree(NODE *root) {
	if(root != NULL) {
		__delete_tree(root->left);
		__delete_tree(root->right);
		// erase content
		free(root);
	}
}

void delete_tree(HEAP **tree) {
	__delete_tree((*tree)->root);
	free(*tree);
	*tree = NULL;
}

int __height(NODE *node) {
	if (node == NULL) return -1;
	int left = __height(node->left);
	int right = __height(node->right);
	return ((left > right) ? left : right) + 1;
}

int height(HEAP *tree) {
	return __height(tree->root);
}