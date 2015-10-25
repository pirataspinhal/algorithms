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

#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------

  DEFINITIONS

---------------------------------------------------------*/

#define SIZE 100
#define ITEM int

typedef struct stack {
    ITEM value[SIZE];
    int top;
} STACK;

/*-------------------------------------------------------

  STACK FUNCTIONS

---------------------------------------------------------*/

STACK *createStack(void);
int empty(STACK *stack);
int full(STACK *stack);
int size(STACK *stack);
int top(STACK *stack);
int push(STACK *stack, ITEM item);
ITEM pop(STACK *stack);

#endif
