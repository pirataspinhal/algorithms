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

#ifndef __MENU_H__
#define __MENU_H__

/*-------------------------------------------------------

	MENU FUNCTIONS

---------------------------------------------------------*/

void printHeader(void) {
	printf("\n\tQUEUE\n");
}

void printMenu(void) {
	printf("\t------------------------------------------------------\n");
	printf("\t1 - Insert a new item\n");
	printf("\t2 - Remove an item\n");
	printf("\t3 - Show size\n");
	printf("\t4 - Show queue\n");
	printf("\t5 - Exit\n");
	printf("\t------------------------------------------------------\n");
	printf("\n\t>> Insert an option (1 - 5): ");
}

void printMainMenu(void) {
	system("clear");
	// WINDOWS:
	// system("cls");
	printHeader();
	printMenu();
}

#endif