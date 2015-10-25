/*-------------------------------------------------------
	ICMC - University of Sao Paulo
	 __  __  ____    ____    
	/\ \/\ \/\  _`\ /\  _`\  
	\ \ \ \ \ \,\L\_\ \ \L\ \
	 \ \ \ \ \/_\__ \\ \ ,__/
	  \ \ \_\ \/\ \L\ \ \ \/ 
	   \ \_____\ `\____\ \_\ 
	    \/_____/\/_____/\/_/ 
	                         
			QUEUE
	(c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE *createQueue() {

	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue != NULL) {
		queue->end = 0;
		queue->begin = 0;
		queue->size = 0;
	}
	return queue;
}

int empty(QUEUE *queue) {
	return (queue->size == 0); // true->empty
}

int insertItem(QUEUE *queue, ITEM new) {

	// Allocate a new ITEM at the queue
	queue->vector = (ITEM*)realloc(queue->vector, sizeof(ITEM) * queue->size + 1);
	if(queue->vector != NULL) {
		// Adds new item at the end of the queue
		queue->vector[queue->size] = new;
		// Increases size of queue, changes the end index
		queue->end = queue->end + 1;
		queue->size++;
		return 1;
	} else {
		// realloc failed: no memory
		printf("\tNO MEMORY AVAIABLE\n");
		return 0;
	}
}

ITEM removeItem(QUEUE *queue) {

	if(!empty(queue)) {
		// Removes the item at beginning of the queue
		// FIFO - First In, First Out
		ITEM rm = queue->vector[queue->begin];
		// Moves the begin index to the next item
		queue->begin = (queue->begin) + 1;
		queue->size--;
		return rm;
	} 
}

int size(QUEUE *queue) {
	return (queue->size);
}

void printQueue(QUEUE *queue) {
	int i;
	printf("\n\t");
	for (i = 0; i < queue->size - 1; i++) {
		printf("%d -> ", queue->vector[i].content);
	}
	printf("%d\n", queue->vector[i].content);
}

void destroyQueue(QUEUE *queue) {
	free(queue->vector);
	free(queue);
}