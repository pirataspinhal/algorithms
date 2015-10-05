/*TAD Lista implementado como uma lista dinâmica duplamente encadeada*/
#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include "item.h"

#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define boolean int //define um tipo booleano


typedef struct node{
    TIPO_ITEM item;
    struct node *proximo;
    struct node *anterior;
}NO;

typedef struct { 
    NO *inicio;
    NO *fim;    
    int tamanho;  //tamanho da fila
}LISTA_DINAMICA;

LISTA_DINAMICA *criar_lista(void);
void apagar_lista_rec(NO *lista);
void apagar_lista(LISTA_DINAMICA *lista);
boolean inserir_item_inicio(LISTA_DINAMICA *lista, TIPO_ITEM *item);
boolean inserir_item_fim(LISTA_DINAMICA *lista, TIPO_ITEM *item);
boolean remover_item(LISTA_DINAMICA *lista, int chave);
boolean inserir_ordenado(LISTA_DINAMICA *lista, TIPO_ITEM *item);
TIPO_ITEM *recuperar_item(LISTA_DINAMICA *lista, int chave);
int tamanho(LISTA_DINAMICA *lista);
boolean vazia(LISTA_DINAMICA *lista);
boolean cheia(LISTA_DINAMICA *lista);
void imprimir_lista(LISTA_DINAMICA *lista);

int remover_item2(LISTA_DINAMICA *lista, int chave);
  
#endif
