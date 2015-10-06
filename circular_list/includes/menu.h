#ifndef __MENU_H__
#define __MENU_H__

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
	printf("\n\t>> Digite uma opção (1 - 4): ");
}

void printMainMenu(void) {
	system("clear");
	// WINDOWS:
	// system("cls");
	printHeader();
	printMenu();
}

#endif