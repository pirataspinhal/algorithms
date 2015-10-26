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
#include "queue.h"

/*-------------------------------------------------------
  createQueue: 
    allocates a queue in heap memory
-------------------------------------------------------*/

QUEUE *createQueue() {

	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));

	if (queue != NULL) {
		queue->end = NULL;
		queue->begin = NULL;
		queue->size = 0;
	}

	return queue;

}

/*-------------------------------------------------------
  empty: 
    checks if queue is empty
-------------------------------------------------------*/

int empty(QUEUE *queue) {
	return (queue->size == 0);
}

/*-------------------------------------------------------
  insert: 
    inserts new item at the end of the queue
-------------------------------------------------------*/

int insert(QUEUE *queue, int value) {

	NODE *new = (NODE*)malloc(sizeof(NODE));
	if (new != NULL) {
		NODE *aux = queue->end;
		new->item = value;
		new->previous = aux;
		new->next = queue->begin;
		queue->end = new;
		queue->size++;
		return(1);
	} else {
		return (0);
	}

}

/*-------------------------------------------------------
  insert_begin: 
    inserts new item at the beginning of the queue
-------------------------------------------------------*/

int insert_begin(QUEUE *queue, int value) {
	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->item = value;
	if (new != NULL) {
		new->next = queue->end;
		new->previous = queue->begin->previous;
		queue->begin = new;
		queue->size++;
		return (1);
	} else {
		return (0);
	}
}

/*-------------------------------------------------------
  remove_begin: 
    removes an item from the beginning of the queue 
    (FIFO): First in, First Out
-------------------------------------------------------*/

NODE *remove_begin(QUEUE *queue) {

	if (!empty(queue)) {
		NODE *removal = queue->begin;
		queue->begin = queue->begin->previous;
		queue->size--;
		return (removal);
	} else {
		return (NULL);
	}
}

/*-------------------------------------------------------
  remove_end: 
    removes an item from the end of the queue 
    (LIFO): Last in, First Out
-------------------------------------------------------*/

NODE *remove_end(QUEUE *queue) {
	if (!empty(queue)) {
		NODE *removal = queue->end;
		queue->end = queue->end->previous;
		queue->end->previous->next = queue->begin;
		return (removal);
	} else {
		return (NULL);
	}
}

/*-------------------------------------------------------
  size: 
    returns the size of the queue
-------------------------------------------------------*/

int size(QUEUE *queue) {
	return (queue->size);
}

/*-------------------------------------------------------
  printQueue: 
    prints every item in the queue
-------------------------------------------------------*/

void printQueue(QUEUE *queue) {

	printf("\n\t");
	if (!empty(queue)) {
		NODE *aux = queue->begin;
		printf("[%d] ", aux->item);
		aux = aux->next;
		while(aux != queue->begin) {
			printf("[%d] ", aux->item);
			aux = aux->next;
		}
	} else {
		printf("QUEUE IS EMPTY\n");
	}
}