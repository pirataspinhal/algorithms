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

#define left_child 0
#define right_child 1

typedef struct node {

	int value;
	NODE *left;
	NODE *right;

} NODE;

typedef struct heap {

	NODE *root;

} HEAP;

HEAP* createHeap();
NODE* createRoot(HEAP* tree, int content);
NODE* insertChild(int child, NODE *node, int content);

