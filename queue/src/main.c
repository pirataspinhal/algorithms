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
#include "menu.h"

typedef enum {

	insert_item = 1,
	remove_item,
	size,
	display,
	shutdown,

} MENU;


/*-------------------------------------------------------

	MAIN

---------------------------------------------------------*/

int main(int argc, char const *argv[]) {

	MENU operation;
	QUEUE *data = NULL;
	data = createQueue();
	ITEM *aux_item = NULL;
	aux_item = (ITEM*)malloc(sizeof(ITEM));
	int aux = 0;
	int value = 0;

	do {
		printMainMenu();
		scanf("%d", &aux);
		getchar();
		operation = aux;

		switch(operation) {
			case insert_item:
				printHeader();
				printf("\tINSERT NEW ITEM VALUE: ");
				scanf("%d", &aux_item->content);
				getchar();
				insertItem(data, aux_item);
				break;
			case remove_item:
				printHeader();
				printf("\tREMOVING ITEM\n");
				aux_item = removeItem(data);
				printf("\tREMOVED %d\n", aux_item->content);
				break;
			case size:
				printHeader();
				printf("\tQUEUE SIZE IS: %d\n", size(data));
				break;
			case display:
				printHeader();
				printQueue(data);
				break;
			case shutdown:
				printHeader();
				destroyList(data);
				break;
		}

		printf("\tPRESS ANY KEY ");
		getchar();
		system("clear");

	} while (operation != shutdown);
 
	return 0;
}