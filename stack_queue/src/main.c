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
  display_size,
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

  do {

    printMainMenu();
    scanf("%d", &aux);
    getchar();
    operation = aux;

    switch(operation) {
      case insert_item:
        printHeader();
        newNode(&data);
        break;
      case remove_item:
        printHeader();
        printf("\tINSERT VALUE TO BE REMOVED: ");
        scanf("%d", &value);
        pop(&data, aux_item);
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

int main(int argc, char const *argv[]) {
  
  return 0;

}