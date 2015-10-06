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

STACK *createStack(void) {

    STACK *stack = (STACK *)malloc(sizeof(STACK));

    if (stack != NULL) {
      stack->top = -1;
    }
    return (stack);
}

 int empty(STACK *stack) {
   return (stack->top == -1);
}

 int full(STACK *stack) {
   return (stack->top == SIZE-1);
 }

 int size(STACK *stack) {
   return (stack->top+1);
}

int top(STACK *stack) {
	
  if(!empty(stack))
		return (stack->value[stack->top]);
	
  return (0);

}

int push(STACK *stack, ITEM item) {
    if (!full(stack)) {
      stack->top++;
      stack->value[stack->top] = item;
      return (1);
    }

    return (0);

}

 ITEM pop(STACK *stack) {
   if (!empty(stack)) {
      ITEM i; 
      i = stack->value[stack->top];
      stack->top--; return (i);
   }
   return (0);
 }


