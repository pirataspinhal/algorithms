/*-------------------------------------------------------
  ICMC - University of Sao Paulo
   __  __  ____    ____    
  /\ \/\ \/\  _`\ /\  _`\  
  \ \ \ \ \ \,\L\_\ \ \L\ \
   \ \ \ \ \/_\__ \\ \ ,__/
    \ \ \_\ \/\ \L\ \ \ \/ 
     \ \_____\ `\____\ \_\ 
      \/_____/\/_____/\/_/ 
                           
            STACK
  (c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#ifndef __MENU_H__
#define __MENU_H__

/*-------------------------------------------------------

	MENU FUNCTIONS

---------------------------------------------------------*/

void printHeader(void) {
	printf("\tSTACK\n\n");
}

void printMenu(void) {
	printf("\t------------------------------------------------------\n");
	printf("\t1 - Insert a new item\n");
	printf("\t2 - Remove an item\n");
	printf("\t3 - Show size of stack\n");
	printf("\t4 - Exit\n");
	printf("\t------------------------------------------------------\n");
	printf("\n\t>> Press an option (1 - 4): ");
}

void printMainMenu(void) {
	system("clear");
	// WINDOWS:
	// system("cls");
	printHeader();
	printMenu();
}

#endif