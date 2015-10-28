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

#ifndef __MERGE_H__
#define __MERGE_H__

/*-------------------------------------------------------
  AUXILIAR
---------------------------------------------------------*/

int* createRandomVector(int n, int min, int max);
void printVector(int *v, int n);

/*-------------------------------------------------------
  MERGESORT
---------------------------------------------------------*/

void mergesort(int *v, int ini, int end);
void swap(int *v, int ini, int cen, int end);

#endif