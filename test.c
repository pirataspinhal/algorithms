#include <stdio.h>
#include <stdlib.h>

typedef int** matrix;

int main(void) {

 int i, j;
 matrix mat = NULL;
 // malloc matrix
 mat = (int**)malloc(sizeof(int*) * 5);
 for(i = 0; i < 5; i++) {
     mat[i] = (int*)malloc(sizeof(int) * 5);
     for(j = 0; j < 5; j++) {
     	mat[i][j] = i+j;
     }
 }

 // print matrix
 for(i = 0; i < 5; i++) {
     for(j = 0; j < 5; j++) {
         printf("[%d]", mat[i][j]);
     }
     printf("\n");
 }

 return 0;

}
