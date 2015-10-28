/*-------------------------------------------------------
  ICMC - University of Sao Paulo
   __  __  ____    ____    
  /\ \/\ \/\  _`\ /\  _`\  
  \ \ \ \ \ \,\L\_\ \ \L\ \
   \ \ \ \ \/_\__ \\ \ ,__/
    \ \ \_\ \/\ \L\ \ \ \/ 
     \ \_____\ `\____\ \_\ 
      \/_____/\/_____/\/_/ 
                           
        BINARY SEARCH
  (c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

int main(int argc, char const *argv[]) {
  
  int *v = NULL;
  int n, min, max, key;
  printf("\tBINARY SEARCH\n");
  printf("\tVECTOR SIZE: ");
  scanf("%d", &n);
  printf("\tMIN: ");
  scanf("%d", &min);
  printf("\tMAX: ");
  scanf("%d", &max);
  printf("\tGENERATING VECTOR\n\t");
  v = createRandomVector(n, min, max);

  printf("\tSEARCH KEY: ");
  scanf("%d", &key);

  

  return 0;
  
}