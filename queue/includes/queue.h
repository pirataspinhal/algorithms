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

typedef struct item {

	int content;

} ITEM;


typedef struct queue {
	
	ITEM *vector;
	int begin;
	int end;
	int size;

} QUEUE;

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

	return (queue->size == 0);

}

int insert(QUEUE *queue, ITEM new) {

	queue->vector = (ITEM*)realloc(queue->vector, sizeof(ITEM) * queue->size + 1);
	if(queue->vector != NULL) {
		queue->vector[queue->size] = new;
		queue->end = queue->end + 1;
		queue->size++;
		return 1;
	} else {
		printf("\tNO MEMORY AVAIABLE\n");
		return 0;
	}
}

ITEM remove(QUEUE *queue) {

	if(!empty(queue)) {
		ITEM rm = queue->vector[queue->begin];
		queue->begin = (queue->begin) + 1;
		queue->size--;
		return rm;
	}
}