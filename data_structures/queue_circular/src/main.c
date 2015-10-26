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
#include "menu.h"

typedef enum {

	insert_item = 1,
	remove_item,
	print_size,
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
	int aux_item;
	aux_item = 0;
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
				scanf("%d", &aux_item);
				getchar();
				insert(data, aux_item);
				break;
			case remove_item:
				printHeader();
				printf("\tREMOVING ITEM\n");
				printf("\tREMOVE AT END (0) OR BEGINNING? (1) ");
				int remove_option;
				scanf("%d", remove_option);
				getchar();
				if(remove_option) {
					aux_item = remove_begin(data);
				} else {
					aux_item = remove_end(data);
				}
				printf("\tREMOVED %d\n", aux_item);
				break;
			case print_size:
				printHeader();
				printf("\tQUEUE SIZE IS: %d\n", size(data));
				break;
			case display:
				printHeader();
				printf("\tQUEUE:\n");
				printQueue(data);
				break;
			case shutdown:
				printHeader();
				printf("\tDESTROYING...\n");
				exit(0);
				//destroyQueue(data);
				break;
		}

		printf("\n\tPRESS ANY KEY ");
		getchar();
		system("clear");

	} while (operation != shutdown);
 
	return 0;
}