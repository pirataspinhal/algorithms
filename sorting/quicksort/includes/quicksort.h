/*-------------------------------------------------------
  ICMC - University of Sao Paulo
   __  __  ____    ____    
  /\ \/\ \/\  _`\ /\  _`\  
  \ \ \ \ \ \,\L\_\ \ \L\ \
   \ \ \ \ \/_\__ \\ \ ,__/
    \ \ \_\ \/\ \L\ \ \ \/ 
     \ \_____\ `\____\ \_\ 
      \/_____/\/_____/\/_/ 
                           
            QUICKSORT
  (c) Felipe Scrochio Custódio
---------------------------------------------------------*/

#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

/*-------------------------------------------------------
  QUICKSORT
---------------------------------------------------------*/

void quicksort(int *v, int ini, int end);
int mediana3(int *v, int *i);

/*-------------------------------------------------------
  AUXILIAR
---------------------------------------------------------*/

int * createRandomVector(int n, int min, int max);
void printVector(int *v, int n);

#endif