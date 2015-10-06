/*-------------------------------------------------------
	ICMC - University of Sao Paulo
	 __  __  ____    ____    
	/\ \/\ \/\  _`\ /\  _`\  
	\ \ \ \ \ \,\L\_\ \ \L\ \
	 \ \ \ \ \/_\__ \\ \ ,__/
	  \ \ \_\ \/\ \L\ \ \ \/ 
	   \ \_____\ `\____\ \_\ 
	    \/_____/\/_____/\/_/ 
	                         
	LINKED CIRCULAR LIST
	(c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#ifndef __CIRCULAR_H__
#define __CIRCULAR_H__

/*-------------------------------------------------------
	BOOELAN TYPE (Doesn't exist in pure C language)
		FALSE 	= 0
		TRUE 	= 1
---------------------------------------------------------*/

typedef enum {
	false, true
} boolean;

/*-------------------------------------------------------
	
	DEFINITIONS (Abstract Data Type)

---------------------------------------------------------*/

typedef struct node {

	int value;
	struct node *next;
	struct node *previous;

} NODE;

typedef struct list {

	// Linked circular list with header
	NODE *header;
	int size;

} LIST;

/*-------------------------------------------------------

	LIST FUNCTIONS
	
---------------------------------------------------------*/

void createList(LIST **list);
boolean insertNode(LIST *data, NODE* node);
boolean removeNode(LIST **data, NODE *removal);
void newNode(LIST **data);
boolean emptyList(LIST *list);
NODE* searchValue(LIST* list, const int value);
void printNode(NODE *print);
void printList(LIST *data);
void destroyList(LIST* data);

#endif