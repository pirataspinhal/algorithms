/*TAD Lista implementado como uma lista duplamente encadeada*/

#include <stdlib.h>
#include <stdio.h>
#include "listadinamica.h"
 

/*Cria logicamente uma lista, inicialmente vazia*/
LISTA_DINAMICA *criar_lista(void){
/*pré-condição: existir espaço na memória.*/
          
    LISTA_DINAMICA *lista = (LISTA_DINAMICA *) malloc(sizeof(LISTA_DINAMICA));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

   return (lista);
}

/*============ REver implementação passando ponteiro para ponteiro =====*/
void apagar_no(NO *no) {
  //apagar_item(&no->item);
  no->item.chave = 0;
  no->item.info.valor = 0;                         
  free(no);
  no = NULL;
}

/*============ REver implementação passando ponteiro para ponteiro =====*/
void apagar_lista(LISTA_DINAMICA *lista) {
  NO *p = lista->inicio;
  NO *aux = NULL;

  while(p != NULL) {

    aux = p;
    p = p->proximo;
    apagar_no(aux);
  }

  free(lista);
  lista = NULL;
}

/*============ REver implementação passando ponteiro para ponteiro =====*/
/*Apaga recursivamente a lista. O parâmetro de entrada deve ser o ponteiro para o início da lista*/
void apagar_lista_rec(NO *lista){
     if(lista != NULL)
         apagar_lista_rec(lista->proximo);
     free(lista);
     lista = NULL;
}

    
/*Verifica se a lista está vazia. Retorna TRUE em caso positivo e FALSE
caso contrário*/    
boolean vazia(LISTA_DINAMICA *lista){
    if(lista == NULL)
        return(TRUE);
    return(FALSE);
}

/*Verifica se a lista está cheia. Retorna TRUE em caso positivo e FALSE
caso contrário*/
boolean cheia(LISTA_DINAMICA *lista){
    /*...*/
    return(FALSE);
}

int tamanho(LISTA_DINAMICA *lista){
    return(lista->tamanho);
}

/*Insere um novo nó no fim da lista duplamente encadeada. PARA LISTAS NÃO ORDENADAS*/
boolean inserir_item_fim(LISTA_DINAMICA *lista, TIPO_ITEM *item){
   
    NO *pnovo = (NO *) malloc(sizeof (NO));
   
    if (pnovo != NULL) {
        pnovo->item = *item;
        pnovo->proximo = NULL;
        pnovo->anterior = lista->fim;

        if (lista->inicio == NULL) 
           lista->inicio = pnovo;
        else 
           lista->fim->proximo = pnovo;
    
        lista->fim = pnovo;
        lista->tamanho++;
      
        return (TRUE);
    } else 
       return (FALSE);
}

/*Insere um novo nó no início (1a posição)da lista duplamente encadeada. PARA LISTAS NÃO ORDENADAS*/
boolean inserir_item_inicio(LISTA_DINAMICA *lista, TIPO_ITEM *item){
   
    NO *pnovo = (NO *) malloc(sizeof (NO));
   
    if (pnovo != NULL) {
        pnovo->item = *item;
        pnovo->proximo = lista->inicio;
        pnovo->anterior = NULL;

        if (lista->inicio == NULL) 
           lista->fim = pnovo;
        else 
           lista->inicio->anterior = pnovo;
    
        lista->inicio = pnovo;
        lista->tamanho++;
      
        return (TRUE);
    }  
    return (FALSE);
}

/*Insere um novo nó na lista. PARA LISTAS ORDENADAS. Ordem crescente. Sem nó cabeça. Listas simplesmente encadeadas.*/
boolean inserir_ordenado(LISTA_DINAMICA *lista, TIPO_ITEM *item){
   
    NO *no_novo,*p,*aux;
    
    p = lista->inicio;
    no_novo = (NO *) malloc(sizeof (NO));
   
    if (no_novo != NULL) {
        no_novo->item = *item;
        no_novo->proximo = NULL;
        
        if (lista->inicio == NULL){
           lista->inicio = no_novo;
           lista->tamanho++;
           return(TRUE);
        }

        if (lista->inicio->item.chave > item->chave){ 
           aux = lista->inicio;
           lista->inicio = no_novo;
           lista->inicio->proximo = aux;
           lista->tamanho++;
           return(TRUE);
        }
        else {
           while((p->proximo->item.chave < item->chave) &&
                 (p->proximo != NULL) ){
               p = p->proximo;
           }
           aux = p->proximo;
           p->proximo = no_novo;
           no_novo->proximo = aux;
           if (no_novo->proximo == NULL)
              lista->fim = no_novo;
        }
        lista->tamanho++;
        return (TRUE);
    }  
    return (FALSE);
}

/*Remover item em qualquer posição da lista, dada uma chave. Implementação didática*/
boolean remover_item(LISTA_DINAMICA *lista, int chave){
    NO *p, *aux;
    
    p = lista->inicio;
    aux = lista->inicio;
    
    if (p == NULL) //lista vazia
       return(FALSE);
    else if (p->item.chave == chave){ // chave está no 1o nó
         lista->inicio = p->proximo;
         lista->tamanho --; //diminui em 1 a contagem de nós da lista
         free(p);
         return(TRUE);
    }
    while(p->proximo != NULL){
        if (p->proximo->item.chave == chave){ 
            aux = p->proximo; //guarda posição a ser removida
            p->proximo = aux->proximo;
            aux->proximo = NULL;
            lista->tamanho --; //diminui em 1 a contagem de nós da lista
            
            if(p->proximo == NULL) // nó eliminado estava na útima posição 
                lista->fim = p;    // Ajusta novo último (fim)
             
            
            free(aux);
            return(TRUE);
        }
        p = p->proximo; // avança para o próximo nó na lista
    }
    return(FALSE); //elemento (chave) não está na lista
}

/*Remover item em qualquer posição da lista, dada uma chave. Implementação melhorada. Lista duplamente ligada*/
boolean remover_item2(LISTA_DINAMICA *lista, int chave) {
   
   if(!vazia(lista)){
      NO *p = lista->inicio;
      
      while(p != NULL && p->item.chave != chave)  // procura até achar chave ou chegar ao fim da lista
         p = p->proximo;                     

      if(p != NULL) {                         
         if(p != lista->inicio)             //se a chave não está no 1o nó 
            p->anterior->proximo = p->proximo;
         else 
            lista->inicio = p->proximo;
         if(p != lista->fim)              //se chave não está no último nó
            p->proximo->anterior = p->anterior;
         else
            lista->fim = p->anterior;
         
         lista->tamanho--;
         free(p);
         return (TRUE);
      }
   }
   return (FALSE);
}

TIPO_ITEM *recuperar_item(LISTA_DINAMICA *lista, int chave){
    NO *aux;
   
    aux = lista->inicio;

    while (aux != NULL) {
       if (aux->item.chave == chave)
          return (&aux->item);
       aux = aux->proximo;
    }
    return(NULL);
}



void imprimir_lista(LISTA_DINAMICA *lista){
     NO *p;
     p = lista->inicio; //lista vem por referencia. usamos p como auxiliar para nao alterar a lista
     printf("\n");
     while(p != NULL){
         printf("[%d: %d]; ", p->item.chave,p->item.info.valor);
         p = p->proximo;
     } 
     
     return;
}

