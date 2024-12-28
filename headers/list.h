#ifndef LIST_H
#define LIST_H

#include <stdlib.h> /* free e malloc */
#include <stdio.h>

#include "e_boolean.h"
#include "pointers_type.h"

/* String para o nome de uma lista */
typedef PtrCharConstData ListName;

/* Define o tipo dos itens do lista*/
typedef int ListItem;

/* Defina a estrutura e ponteiro para uma lista*/
typedef struct node_list {
	ListItem item;
	struct node_list *next;	
} * List;

/* Cria um nó da lista*/
List node_list(ListItem, List);

/* Exibe a lista formatda */
void print_list(List, ListName);

/* Diz o tamanho de uma lista */
int len_list(List);

/* Cria uma lista de tamanho n, cujos */
/* os itens em ordem crescente de 0 até n */
List range(ListItem);

/* Cria uma lista de tamanho n com os */
/* valores dos itens variando de 0 até m-1*/
List random_list(int, int);

/* Insere uma lista no final de outra */
void append_list(List*, List);

/* Limpa todos os nós da lista */
void del_list(List*);


#endif
