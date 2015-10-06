/*-------------------------------------------------------
  ICMC - University of Sao Paulo
   __  __  ____    ____    
  /\ \/\ \/\  _`\ /\  _`\  
  \ \ \ \ \ \,\L\_\ \ \L\ \
   \ \ \ \ \/_\__ \\ \ ,__/
    \ \ \_\ \/\ \L\ \ \ \/ 
     \ \_____\ `\____\ \_\ 
      \/_____/\/_____/\/_/ 
                           
        	MERGE SORT
  (c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

int main(int argc, char const *argv[]) {
  
  int *v = NULL;
  int i;
  v = (int*)malloc(sizeof(int) * 100);
  for (i = 0; i < 100; i++) {
    v[i] = i;
  }

  return 0;
}