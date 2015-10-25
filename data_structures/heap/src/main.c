/*-------------------------------------------------------
	ICMC - University of Sao Paulo
	 __  __  ____    ____    
	/\ \/\ \/\  _`\ /\  _`\  
	\ \ \ \ \ \,\L\_\ \ \L\ \
	 \ \ \ \ \/_\__ \\ \ ,__/
	  \ \ \_\ \/\ \L\ \ \ \/ 
	   \ \_____\ `\____\ \_\ 
	    \/_____/\/_____/\/_/ 
	                         
				HEAP
	(c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char const *argv[]) {
	
	HEAP *tree = NULL;
	NODE *root = NULL;
	NODE *aux = NULL;

	printf("\tPRESS ANY BUTTON TO CREATE HEAP ");
	getchar();
	tree = createHeap();
	root = createRoot(tree, 0);
	printf("\tHEAP CREATED ");
	getchar();


	return 0;
}