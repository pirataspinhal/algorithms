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

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*-------------------------------------------------------

  STACK FUNCTIONS

---------------------------------------------------------*/

/*-------------------------------------------------------
  createStack: 
    allocates a stack in heap memory
-------------------------------------------------------*/

STACK *createStack(void) {

    STACK *stack = (STACK *)malloc(sizeof(STACK));

    if (stack != NULL) {
      stack->top = -1;
    }
    return (stack);
}

/*-------------------------------------------------------
  empty: 
    checks if a stack is empty
-------------------------------------------------------*/

 int empty(STACK *stack) {
   return (stack->top == -1);
}

/*-------------------------------------------------------
  full: 
    checks if a stack is full (static)
-------------------------------------------------------*/

 int full(STACK *stack) {
   return (stack->top == SIZE-1);
 }

 /*-------------------------------------------------------
  size: 
    returns the size of a stack
-------------------------------------------------------*/

 int size(STACK *stack) {
   return (stack->top+1);
}

/*-------------------------------------------------------
  top: 
    returns the item at the top, without removing it
-------------------------------------------------------*/

int top(STACK *stack) {
	
  if(!empty(stack))
		return (stack->value[stack->top]);
	
  return (0);

}

/*-------------------------------------------------------
  push:
    inserts a new item at the top
    of the stack
-------------------------------------------------------*/

int push(STACK *stack, ITEM item) {
    if (!full(stack)) {
      stack->top++;
      stack->value[stack->top] = item;
      return (1);
    }

    return (0);

}

/*-------------------------------------------------------
  pop:
    removes and returns the top item
    of the stack
-------------------------------------------------------*/

ITEM pop(STACK *stack) {
  if (!empty(stack)) {
    ITEM i; 
    i = stack->value[stack->top];
    stack->top--;
    return (i);
  } else {
   return (0);
  }
 }


