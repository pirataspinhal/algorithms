#ifndef ITEM_H
#define ITEM_H

typedef int TIPO_CHAVE; /*tipo da chave – deve admitir comparações*/

typedef struct{ /*tipo registro*/
        int valor;
        // ...
}TIPO_INFO;

typedef struct{ /*item (nó) da lista*/
        TIPO_CHAVE chave;
        TIPO_INFO info;
}TIPO_ITEM;

TIPO_ITEM *criar_item(TIPO_CHAVE chave, int valor);
void apagar_item(TIPO_ITEM *item);
void imprimir_item(TIPO_ITEM *item);

#endif
