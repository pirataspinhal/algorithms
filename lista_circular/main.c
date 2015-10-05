/*-------------------------------------------------------
ICMC - USP
BCC - 2015

TAD Lista Dinâmica Circular

Aluno	:	Felipe Scrochio Custodio
Nº USP	:	9442688
---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------
	TIPO BOOLEANO (Não existe como padrão na linguagem C)
		FALSE 	= 0
		TRUE 	= 1
---------------------------------------------------------*/

typedef enum {
	false, true
} boolean;

/*-------------------------------------------------------
	
	DEFINIÇÕES

---------------------------------------------------------*/

typedef struct node {

	int value;
	struct node *next;
	struct node *previous;

} NODE;

typedef struct list {

	// Lista circular com cabeçalho
	NODE *header;
	int size;

} LIST;

typedef enum {

	insert_node = 1,
	remove_node,
	display,
	shutdown,

} MENU;

/*-------------------------------------------------------

	FUNÇÕES DA LISTA
	
---------------------------------------------------------*/

void createList(LIST **list);
boolean insertNode(LIST *data, NODE* node);
boolean removeNode(LIST **data, NODE *removal);
void newNode(LIST **data);
boolean emptyList(LIST *list);
NODE* searchID(LIST* list, const int id);
void printNode(NODE *print);
void printList(LIST *data);
void destroyList(LIST* data);

/*-------------------------------------------------------

	FUNÇÕES DO MENU
	
---------------------------------------------------------*/

void printHeader(void); 
void printMenu(void);
void printMainMenu(void);

/*-------------------------------------------------------

	MAIN
	
---------------------------------------------------------*/

int main(int argc, char const *argv[]) {

	MENU operation;
	LIST *data = NULL;
	createList(&data);
	NODE *aux_node = NULL;
	aux_node = (NODE*)malloc(sizeof(NODE));
	int aux = 0;

	do
	{
		printMainMenu();
		scanf("%d", &aux);
		getchar();
		operation = aux;

		switch(operation) {
			case insert_node:
				printHeader();
				newNode(&data);
				insertNode(data, aux_node);
				break;
			case remove_node:
				printHeader();
				removeNode(&data, aux_node);
				break;
			case display:
				printHeader();
				printList(data);
				break;
			case shutdown:
				printHeader();
				destroyList(data);
				break;
		}

		printf("\tPRESSIONE QUALQUER TECLA PARA CONTINUAR ");
		getchar();
		system("clear");

	} while (operation != shutdown);
 
	return 0;
}

/*-------------------------------------------------------

	createList(LIST **database)

		DESCRIÇÃO:
		
			Aloca um LIST* na memória, setando
			o cabeçalho com ponteiros de próximo e
			anterior para ele mesmo.
		
		PARÂMETROS:
			
			@LIST **database: 
				Ponteiro para um LIST* na main.
			
---------------------------------------------------------*/

void createList(LIST **database)
{
	(*database) = (LIST*)malloc(sizeof(LIST));

	if (database != NULL) {

		NODE *sentinel = (NODE*)malloc(sizeof(NODE));
		(*database)->header = sentinel;
		(*database)->header->next = sentinel;
		(*database)->header->previous = sentinel;
		(*database)->size = 0;

	}
}

/*-------------------------------------------------------

	insertNode(LIST *data, NODE *node)

		DESCRIÇÃO:
		
			Insere um novo nó na lista circular
			LIST *data, de forma ordenada.
		
		PARÂMETROS:
			
			@LIST *data: 
				Lista dinâmica.
			@NODE *node:
				Novo nó a ser inserido (previamente alocado)

---------------------------------------------------------*/

boolean insertNode(LIST *data, NODE* node) {
	
	NODE *position = NULL;
	NODE *previous = NULL;
	NODE *aux = NULL;
	position = data->header->next;
	previous = data->header;	
	node->next = NULL;
	node->previous = NULL;

	// Procura posição correta na lista
	while(position->value < node->value && position != data->header) {

		previous = position;
		position = position->next;

	}

	// Insere elemento na lista
	if(data->header->next == data->header) {
		// Inserção no início
		data->header->next = node;
		data->header->previous = node;
		node->next = data->header;
		node->previous = data->header;
		(data)->size++;

	} else {

		// Inserção no meio/fim
		previous->next = node;
		node->previous = previous;
		node->next = position;
		position->previous = node;
		(data)->size++;

	}

	return true;

}

/*-------------------------------------------------------

	removeNode

		DESCRIÇÃO:
			Remove um nó da lista

		PARÂMETROS:
			@ LIST **data: ponteiro para a lista dinâmica data
			@ NODE *removal: nó a ser removido da lista
			
---------------------------------------------------------*/

boolean removeNode(LIST **data, NODE *removal)
{

	if (removal != NULL) { 
		NODE *aux = removal;
		removal->previous->next = removal->next;
		removal->next->previous = removal->previous;	
		free(removal);
		return true;

	} else {

		return false;
		
	}
}


/*-------------------------------------------------------
	
		newNode

			DESCRIÇÃO:
				O usuário insere os dados de um novo
				nó que será colocado na lista pela
				insertNode (inserção ordenada)
	
			PARÂMETROS:
				@ LIST **data: 
					Endereço da lista em que o nó será 
					inserido. 

---------------------------------------------------------*/

void newNode(LIST **data) {

	int i;
	int keytotal = 0;
	NODE *new = NULL;
	new = (NODE*)malloc(sizeof(NODE));
	new->value = 0;

	printf("\tINSIRA OS DADOS DO NOVO NODE:\n");
	printf("\tINSIRA O VALOR: ");
	scanf("%d", &new->value);
	getchar();

	new->next = NULL;
	new->previous = NULL;

	insertNode(*data, new);

}


/*-------------------------------------------------------

	emptyList	

		DESCRIÇÃO:
			Verifica se a lista possui nós.
		
		PARÂMETROS:
			LIST *database: lista a ser verificada
			
---------------------------------------------------------*/

boolean emptyList(LIST *database) {

	if(database->header->next == database->header) {
		return true;
	} else {
		return false;
	}
}

/*-------------------------------------------------------

	printNode

		DESCRIÇÃO:
			Imprime as informações de um nó website

		PARÂMETROS:
			
			@NODE *print: nó website a ser impresso na tela

---------------------------------------------------------*/

void printNode(NODE *print) {

	int i;
	printf("\tNODE = %d\n", print->value);
	printf("\n");

}

/*-------------------------------------------------------

	printList

		DESCRIÇÃO:
			Imprime todos os nós armazenados na memória

		PARÂMETROS:
			
			@LIST *data: lista de sites

---------------------------------------------------------*/

void printList(LIST *data) {

	NODE *aux = NULL;
	aux = data->header->next;
	while (aux != data->header) {
		printNode(aux);
		aux = aux->next;
	}
}

/*-------------------------------------------------------

	FUNÇÕES DE LIBERAÇÃO DE MEMÓRIA ALOCADA

---------------------------------------------------------*/

void destroyList(LIST* data) {

	NODE* aux = data->header->next;

	int i;
	while (aux != data->header) {

		aux = aux->next; 

	}

	free(aux);
	free(data);
}

/*-------------------------------------------------------

	FUNÇÕES DE MENU

---------------------------------------------------------*/

void printHeader(void) {
	printf("\tLISTA DINÂMICA CIRCULAR\n");
}

void printMenu(void) {
	printf("\t------------------------------------------------------\n");
	printf("\t1 - Inserir novo nó\n");
	printf("\t2 - Remover um nó\n");
	printf("\t3 - Exibir lista\n");
	printf("\t4 - Liberar memoria e finalizar o programa\n");
	printf("\t------------------------------------------------------\n");
	printf("\n\t>> Digite uma opção (1 - 4): ");
}

void printMainMenu(void) {
	system("clear");
	// WINDOWS:
	// system("cls");
	printHeader();
	printMenu();
}