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