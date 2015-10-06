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

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "menu.h"

typedef enum {

  insert_item = 1,
  remove_item,
  display,
  shutdown,

} MENU;


/*-------------------------------------------------------

  MAIN

---------------------------------------------------------*/

int main(int argc, char const *argv[]) {

  MENU operation;
  STACK *data = NULL;
  ITEM aux_item;
  data = createStack();

  int aux = 0;
  int value = 0;
  int stack_size = 0;

  do {

    printMainMenu();
    scanf("%d", &aux);
    getchar();
    operation = aux;

    switch(operation) {
      case insert_item:
        printHeader();
        printf("\tINSERT VALUE: ");
        scanf("%d", &aux_item);
        getchar();
        push(data, aux_item);
        break;
      case remove_item:
        printHeader();
        printf("\tREMOVE TOP VALUE\n");
        aux_item = pop(data);
        printf("\tVALUE REMOVED: %d\n", aux_item);
        break;
      case display:
        printHeader();
        stack_size = size(data);
        printf("\tSTACK SIZE IS %d\n", stack_size);
        break;
      case shutdown:
        printHeader();
        printf("\tEXIT\n");
        break;
    }

    printf("\tPRESS ANY KEY ");
    getchar();
    system("clear");

  } while (operation != shutdown);
 
  return 0;
}