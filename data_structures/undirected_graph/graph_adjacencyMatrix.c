/*
Undirected Graph
Adjacency Matrix
Felipe Scrochio Custódio
*/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

typedef struct graph {
	/* n = vertices m = edges */
	int n;
	int m;
	/* adjacency matrix */
	bool** adjacencyMatrix;
} GRAPH;

GRAPH* initializeGraph(int n_vertices) {

	int i, j;
	GRAPH* g = (GRAPH*)malloc(sizeof(GRAPH));
	g->n = n_vertices;
	g->m = 0;
	g->adjacencyMatrix = (bool**)malloc(sizeof(bool*) * n_vertices);
	for (i = 0; i < n_vertices; i++) {
		g->adjacencyMatrix[i] = (bool*)malloc(sizeof(bool) * n_vertices);
		for (j = 0; j < n_vertices; j++) {
			g->adjacencyMatrix[i][j] = FALSE; 
		}
	}

	return g;

}

void addEdge(GRAPH *g, int i, int j) {
	if (i >= 0 && i <  g->n && j > 0 && j < g->n) {
		g->adjacencyMatrix[i][j] = TRUE;
		/* undirected graph */
		g->adjacencyMatrix[j][i] = TRUE;
	} else {
		printf("Invalid arguments\n");
	}
}

void removeEdge(GRAPH *g, int i, int j) {
	if (i >= 0 && i <  g->n && j > 0 && j < g->n) {
		g->adjacencyMatrix[i][j] = FALSE;
		/* undirected graph */
		g->adjacencyMatrix[j][i] = FALSE;
	} else {
		printf("Invalid arguments\n");
	}
}

bool isEdge(GRAPH* g, int i, int j) {
	if (i >= 0 && i < g->n && j > 0 && j < g->n) {
		return g->adjacencyMatrix[i][j];
	} else {
		return FALSE;
	}
}

void deleteGraph(GRAPH* g) {
	int i;
	for (i = 0; i < g->n; i++) {
		free(g->adjacencyMatrix[i]);
	}
	free(g->adjacencyMatrix);
	free(g);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}