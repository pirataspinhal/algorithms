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

#include <stdlib.h>
#include <stdio.h>
#include "quicksort.h"

/*-------------------------------------------------------
  QUICKSORT
---------------------------------------------------------*/

void quicksort(int *v, int ini, int end) {

  //printf("tamanho do vetor: %d\n", (end-ini)+1);

  if ((end-ini)+1 <= 1) return; // condicao de parada

  // 1 - pivo sera o primeiro elemento, trocar com o ultimo
  //int pivo = v[ini];

  // 2- pivo como aleatorio #fail
  //int i_pivo = rand()%(end+1);

  // 3 - mediana de 3
  int cen = (int) ((end-ini)/2.0);

  // valores candidatos a pivo
  int vp[3] = {v[ini], v[cen], v[end]};
  // indices relativos aos candidatos
  int ip[3] = {ini, cen, end};

  int i_pivo = mediana3(vp, ip);

  int pivo = v[i_pivo];
  v[i_pivo] = v[end];
  v[end] = pivo;
  
  // 2 - particionar
  int i = ini-1;
  int j = end;

  do {
    // tenta encontrar um par de elementos para trocar
    do { i++; } while (v[i] < pivo);
    do { j--; } while (j >= ini && v[j] >= pivo);
    // se i < j entao deve trocar
    if (i < j) {
      int tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }
  } while (i < j);
  // posiciona o pivo na posicao correta == i
  v[end] = v[i];
  v[i] = pivo;

  // 3 - chama recursivamente
  __quicksort(v, ini, i-1); // lista 1 = ini -> pivo-1
  __quicksort(v, i+1, end); // lista 2 = pivo+1 -> end
}

int mediana3(int *v, int *i) {
  // 0 eh mediana?
  if (v[1] <= v[0] && v[0] <= v[2]) return i[0];
  if (v[2] <= v[0] && v[0] <= v[1]) return i[0];
  
  // 1 eh mediana?
  if (v[0] <= v[1] && v[1] <= v[2]) return i[1];
  if (v[2] <= v[1] && v[1] <= v[0]) return i[1];
  
  // 2 eh mediana?
  if (v[0] <= v[2] && v[2] <= v[1]) return i[2];
  if (v[1] <= v[2] && v[2] <= v[0]) return i[2];
}

/*-------------------------------------------------------
  AUXILIAR
---------------------------------------------------------*/

// cria e retorna vetor aleatorio de tamanho n
int * createRandomVector(int n, int min, int max) {

  int *v = (int *) malloc(sizeof(int) * n);
  if (v == NULL) return NULL;

  int i;
  for (i = 0 ; i < n; i++) {
    v[i] = rand()%(max-min) + min;
  }

  return v;
}

// imprime vetor
void printVector(int *v, int n) {
  int i;
  for (i = 0; i < n ; i++ ) {
    printf("%d ", *(v+i));
  }
  printf("\n");
}