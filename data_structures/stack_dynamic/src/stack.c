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

STACK *createStack() {
  STACK *stack = (STACK*)malloc(sizeof(STACK));
  if (stack != NULL) {
    stack->top = NULL;
    stack->size = 0;
  }
  return stack;
}

/*-------------------------------------------------------
  empty: 
    checks if a stack is empty
-------------------------------------------------------*/

int empty(STACK *stack) {
  return (stack->top == NULL);
}

/*-------------------------------------------------------
  size: 
    returns the size of a stack
-------------------------------------------------------*/

int size(STACK *stack) {
  return (stack->size);
}

/*-------------------------------------------------------
  top: 
    returns a pointer to the top
    node, without removing it
-------------------------------------------------------*/

ITEM *top(STACK *stack) {

  if (!empty(stack)) {
    return (stack->top);
  }
  return (NULL);

}

/*-------------------------------------------------------
  push:
    inserts a new node at the top
    of the stack
-------------------------------------------------------*/

int push(STACK *stack, ITEM item) {
  NODE *new = (NODE*)malloc(sizeof(NODE));
  if (new != NULL) {
    new->item = item;
    new->previous = stack->top;
    stack->top = new;
    stack->size++;
    return (1);
  } else {
    return (0);
  }
}

/*-------------------------------------------------------
  pop:
    removes and returns the top node
    of the stack
-------------------------------------------------------*/

ITEM pop(STACK *stack) {
  if (!empty(stack)) {
    NODE *node = stack->top;
    ITEM item = stack->top->item;
    stack->top = stack->top->previous;
    node->previous = NULL;
    free(node);
    node = NULL;
    stack->size--;
    return (item);
  }
  return (0);
}

/*-------------------------------------------------------

  FREE MEMORY FUNCTIONS

---------------------------------------------------------*/

void destroyNode(NODE *node) {
  free(node->previous);
  node->previous = NULL;
  node->item = 0;
}

void destroyStack(STACK **stack) {

  if(!empty(*stack)) {
    NODE *aux = (*stack)->top;
    while(aux != NULL) {
      NODE *removal = aux;
      aux = aux->previous;
      destroyNode(removal);
    }
  }

  free(*stack);
  *stack = NULL;

}