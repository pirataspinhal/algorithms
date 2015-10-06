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
 
 #define TAM 100
 #define ITEM int

typedef struct stack STACK;

STACK *createStack(void);
int empty(STACK *stack);
int full(STACK *stack);
int size(STACK *stack);
int push(STACK *stack, ITEM item);
ITEM pop(STACK *stack);

#endif
