/*-------------------------------------------------------
  ICMC - University of Sao Paulo
   __  __  ____    ____    
  /\ \/\ \/\  _`\ /\  _`\  
  \ \ \ \ \ \,\L\_\ \ \L\ \
   \ \ \ \ \/_\__ \\ \ ,__/
    \ \ \_\ \/\ \L\ \ \ \/ 
     \ \_____\ `\____\ \_\ 
      \/_____/\/_____/\/_/ 
                           
          DYNAMIC STACK
  (c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------

  DEFINITIONS

---------------------------------------------------------*/

#define ITEM int

typedef struct node NODE;
typedef struct stack STACK;

typedef struct node {

  ITEM item;
  NODE *previous;

} NODE;

typedef struct stack {

  NODE *top;
  int size;

} STACK; 

/*-------------------------------------------------------

  STACK FUNCTIONS

---------------------------------------------------------*/

STACK *createStack();
int empty(STACK *stack);
int size(STACK *stack);
ITEM *top(STACK *stack);
int push(STACK *stack, ITEM item);
ITEM pop(STACK *stack);

/*-------------------------------------------------------

  FREE MEMORY FUNCTIONS

---------------------------------------------------------*/

void destroyNode(NODE *node);
void destroyStack(STACK **stack);

#endif