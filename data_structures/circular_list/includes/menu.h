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

#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>

/*-------------------------------------------------------

	MENU FUNCTIONS

---------------------------------------------------------*/

void printHeader(void) {
	printf("\tLINKED CIRCULAR LIST\n\n");
}

void printMenu(void) {
	printf("\t------------------------------------------------------\n");
	printf("\t1 - Insert a new node\n");
	printf("\t2 - Remove a node\n");
	printf("\t3 - Show list\n");
	printf("\t4 - Exit\n");
	printf("\t------------------------------------------------------\n");
	printf("\n\t>> Insert an option (1 - 4): ");
}

void printMainMenu(void) {
	system("clear");
	// WINDOWS:
	// system("cls");
	printHeader();
	printMenu();
}

#endif