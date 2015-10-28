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
  int n, min, max;
  printf("\tMERGESORT\n");
  printf("\tVECTOR SIZE: ");
  scanf("%d", &n);
  printf("\tMIN: ");
  scanf("%d", &min);
  printf("\tMAX: ");
  scanf("%d", &max);
  printf("\tGENERATING VECTOR\n\t");
  v = createRandomVector(n, min, max);
  printVector(v, n);
  printf("\tSORTING\n");
  mergesort(v, 0, n-1);
  printf("\tVECTOR SORTED\n\t");
  printVector(v, n);

  return 0;
  
}