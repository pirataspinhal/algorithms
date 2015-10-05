#include <stdio.h>
#include <stdlib.h>

#include "listadinamica.h"

int main(int argc, char *argv[]){
    
    LISTA_DINAMICA *lista;
    TIPO_ITEM item, *it;
    
    lista = criar_lista();
    
    item.chave = 111;
    item.info.valor = 1;
    inserir_item_inicio (lista, &item);
    
    item.chave = 2;
    item.info.valor = 20;
    inserir_item_fim (lista, &item);    
    
    item.chave = 31;
    item.info.valor = 11;
    inserir_item_fim (lista, &item);
    
    item.chave = 12;
    item.info.valor = 122;
    inserir_item_fim (lista, &item);
    
    item.chave = 21;
    item.info.valor = 221;
    inserir_item_fim (lista, &item);
    
    item.chave = 222;
    item.info.valor = 222;
    inserir_item_inicio (lista, &item);
    
    imprimir_lista(lista);
    
    printf("\n Tamanho: %d\n", lista->tamanho);
    
    it = recuperar_item(lista, 12);
    if (it != NULL)
        printf("\n Chave: %d, Valor: %d\n", it->chave, it->info.valor);
    else
        printf("\n Chave não encontrada!\n");
    
    
    remover_item2(lista, 31); // remove item do meio da lista
    imprimir_lista(lista);
    
    remover_item2(lista, 222); //remove 1o item da lista
    imprimir_lista(lista);
    
    remover_item2(lista, 21); //remove último item da lista
    imprimir_lista(lista);
    
    printf("\n Tamanho: %d\n", lista->tamanho);
    
    
    apagar_lista(lista);
    lista = NULL;
             
    
    
    if (!vazia(lista)) 
       imprimir_lista(lista);
    else
        printf("VAZIA!!!");
    

    
              
    system("PAUSE");	
    return 0;
}


