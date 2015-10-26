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

#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

/*-------------------------------------------------------

	createList(LIST **database)

		DESCRIPTION:
		
			Allocates a list pointer in heap memory,
			setting the header's next' and 'previous' pointers
			to itself.
		
		PARAMETERS:
			
			@LIST **database: 
				Pointer to a LIST*
			
---------------------------------------------------------*/

void createList(LIST **database) {

	(*database) = (LIST*)malloc(sizeof(LIST));

	if (database != NULL) {

		NODE *sentinel = (NODE*)malloc(sizeof(NODE));
		(*database)->header = sentinel;
		(*database)->header->next = sentinel;
		(*database)->header->previous = sentinel;
		(*database)->size = 0;

	}
}

/*-------------------------------------------------------

	insertNode(LIST *data, NODE *node)

		DESCRIPTION:
		
			Inserts a new node in a list, already in
			it's sorted position. 
		
		PARAMETERS:
			
			@LIST *data: list where node will be inserted
			@NODE *node: new node (already allocated)

---------------------------------------------------------*/

boolean insertNode(LIST *data, NODE* node) {
	
	NODE *position = NULL;
	NODE *previous = NULL;
	NODE *aux = NULL;
	position = data->header->next;
	previous = data->header;	
	node->next = NULL;
	node->previous = NULL;

	// Searches for the correct position in the list
	while(position->value < node->value && position != data->header) {

		previous = position;
		position = position->next;

	}

	// Inserts element in the list
	if(data->header->next == data->header) {
		
		// Insertion at the beginning
		data->header->next = node;
		data->header->previous = node;
		node->next = data->header;
		node->previous = data->header;
		(data)->size++;

	} else {

		// Insertion at the middle/end
		previous->next = node;
		node->previous = previous;
		node->next = position;
		position->previous = node;
		(data)->size++;

	}

	return true;

}

/*-------------------------------------------------------

	removeNode

		DESCRIPTION:
			Removes a node from the list

		PARAMETERS:
			@ LIST **data: address of the list
			@ NODE *removal: node to be removed
			
---------------------------------------------------------*/

boolean removeNode(LIST **data, NODE *removal) {

	if (removal != NULL) { 
		NODE *aux = removal;
		removal->previous->next = removal->next;
		removal->next->previous = removal->previous;	
		free(removal);
		return true;
	} else {
		return false;
	}
}


/*-------------------------------------------------------
	
		newNode

			DESCRIPTION:
				User inputs a value to a new node, which
				is allocated in heap memory and inserted
				into the list with insertNode()
	
			PARAMETERS:
				@ LIST **data: address of the list 

---------------------------------------------------------*/

void newNode(LIST **data) {

	int i;
	int keytotal = 0;
	NODE *new = NULL;
	new = (NODE*)malloc(sizeof(NODE));
	new->value = 0;

	printf("\tINSERT NODE INFORMATIONS:\n");
	printf("\tVALUE: ");
	scanf("%d", &new->value);
	getchar();

	new->next = NULL;
	new->previous = NULL;

	insertNode(*data, new);

}


/*-------------------------------------------------------

	emptyList	

		DESCRIPTION:
			Checks if a list has nodes.
		
		PARAMETERS:
			@ LIST *database: list to be checked
			
---------------------------------------------------------*/

boolean emptyList(LIST *database) {

	if(database->header->next == database->header) {
		return true;
	} else {
		return false;
	}
}

/*-------------------------------------------------------

	searchValue

		DESCRIPTION:
			Searches for a node using its value. If found,
			returns a pointer to the node.
		
		PARAMETERS:
			@ LIST *database: list to search
			@ const int value: wanted node
			
---------------------------------------------------------*/

NODE* searchValue(LIST* database, const int value) {
	NODE* aux = database->header->next;

	while (aux != database->header) {
		if (aux->value == value) {
			return aux;
		}
		aux = aux->next;
	}

	aux = NULL;
	return aux;
}

/*-------------------------------------------------------

	printNode

		DESCRIPTION:
			Prints the informations on a node.

		PARAMETERS:
			
			@NODE *print: node to be printed

---------------------------------------------------------*/

void printNode(NODE *print) {

	int i;
	printf("\tNODE[%d]\n", print->value);
	printf("\n");

}

/*-------------------------------------------------------

	printList

		DESCRIPTION:
			Prints all nodes in a list

		PARAMETERS:
			
			@LIST *data

---------------------------------------------------------*/

void printList(LIST *data) {

	NODE *aux = NULL;
	aux = data->header->next;
	while (aux != data->header) {
		printNode(aux);
		aux = aux->next;
	}
}

/*-------------------------------------------------------

	FUNCTIONS TO FREE HEAP MEMORY

---------------------------------------------------------*/

void destroyList(LIST* data) {

	NODE* aux = data->header->next;

	int i;
	while (aux != data->header) {
		// If node has something allocated in memory, free here
		aux = aux->next; 
	}

	free(aux);
	free(data);
	
}