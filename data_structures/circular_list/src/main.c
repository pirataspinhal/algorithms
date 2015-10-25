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
#include "menu.h"

typedef enum {

	insert_node = 1,
	remove_node,
	display,
	shutdown,

} MENU;


/*-------------------------------------------------------

	MAIN

---------------------------------------------------------*/

int main(int argc, char const *argv[]) {

	MENU operation;
	LIST *data = NULL;
	createList(&data);
	NODE *aux_node = NULL;
	aux_node = (NODE*)malloc(sizeof(NODE));
	int aux = 0;
	int value = 0;

	do {
		printMainMenu();
		scanf("%d", &aux);
		getchar();
		operation = aux;

		switch(operation) {
			case insert_node:
				printHeader();
				newNode(&data);
				break;
			case remove_node:
				printHeader();
				printf("\tINSERT VALUE TO BE REMOVED: ");
				scanf("%d", &value);
				aux_node = searchValue(data, value);
				removeNode(&data, aux_node);
				break;
			case display:
				printHeader();
				printList(data);
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