/*-------------------------------------------------------
	ICMC - University of Sao Paulo
	 __  __  ____    ____    
	/\ \/\ \/\  _`\ /\  _`\  
	\ \ \ \ \ \,\L\_\ \ \L\ \
	 \ \ \ \ \/_\__ \\ \ ,__/
	  \ \ \_\ \/\ \L\ \ \ \/ 
	   \ \_____\ `\____\ \_\ 
	    \/_____/\/_____/\/_/ 
	                         
			CIRCULAR QUEUE
	(c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct queue QUEUE;

typedef struct node {

	int item;
	// A circular list is double linked
	NODE *previous;
	NODE *next;

} NODE;

typedef struct queue {

	NODE *begin;
	NODE *end; 
	int size;

} QUEUE;

QUEUE *createQueue();
int empty(QUEUE *queue);
int insert(QUEUE *queue, int value);
int insert_begin(QUEUE *queue, int value);
NODE *remove_begin(QUEUE *queue);
NODE *remove_end(QUEUE *queue);
int size(QUEUE *queue);
void printQueue(QUEUE *queue);