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

#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

/*-------------------------------------------------------
  MERGESORT
---------------------------------------------------------*/

void mergesort(int *v, int ini, int end) {

	if (end-ini >= 1) {
		int cen = (int)((end+ini)/2.0);

		// divide
		mergesort(v, ini, cen);
		mergesort(v, cen+1, end);

		// conquer
		swap(v, ini, cen, end);
	}

}

void swap(int *v, int ini, int cen, int end) {

	int i, j, k = 0;
	// i -> index set at the smallest element of list 1 (sorted)
	// j -> index set at the smallest element of list 2 (sorted)
	// k -> index of the next element to be swapped

	i = ini;
	j = cen+1;

	// auxiliar vector allocation
	int *aux = (int*)malloc(sizeof(int) * (end-ini+1));	

	// swap
	while ((i <= cen) && (j <= end)) {
		if (v[i] <= v[j]) {
			aux[k] = v[i];
			i++;
		} else {
			aux[k] = v[j];
			j++;
		}

		k++;
	}

	// check if there are elements remaining in the lists
	// list 1
	while (i <= cen) {
		aux[k] = v[i];
		i++; 
		k++;
	}
	// list 2
	while (j <= end) {
		aux[k] = v[j];
		j++; 
		k++;
	}

	for (i = ini; i <= end; i++) {
		v[i] = aux[i-ini];
	}

	free(aux);
}

/*-------------------------------------------------------
  AUXILIAR
---------------------------------------------------------*/

int* createRandomVector(int n, int min, int max) {

	int *v = (int*)malloc(sizeof(int) * n);
	if (v == NULL) return NULL;

	int i;
	for (i = 0 ; i < n; i++) {
		v[i] = rand()%(max-min) + min;
	}

	return v;
}

void printVector(int *v, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", *(v+i));
	}
	printf("\n");
}
