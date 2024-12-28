#ifndef STACK_H
#define STACK_H

#include <stdlib.h> /* free, malloc */
#include "e_boolean.h"

#ifndef STACK_ITEM
#define STACK_ITEM
/* Define o tipo dos itens da pilha */
typedef int StackItem;
#endif

/* Define a estrutura da pilha e um nome para um ponteiro para ela */
typedef struct stack{
	unsigned max;
	int top;
	StackItem *items;
} * Stack;

/* Função que cria a pilha de n tamnho */
Stack stack(unsigned);

/* Função que adiciona itens na pilha */
/* Retorna 1 se bem sucedido e 0 do contrário */
Bool push_to_stack(StackItem, Stack);

/* Função que diz se a pilha está vazia */
Bool stack_is_empty(Stack);

/* Função que diz se a pilha está cheia */
Bool stack_is_full(Stack);

/* Função que retorna o item no topo da pilha, mas não remove */
/* Retorna 1 se bem sucedido e 0 do contrário */
Bool stack_top(StackItem*, Stack);

/* Função que retorna o item no topo da pilha e o remove */
/* Retorna 1 se bem sucedido e 0 do contrário */
Bool pop_from_stack(StackItem*, Stack);

/* Função que desaloca os recursos utilizados pela pilha*/
void del_stack(Stack*);

#endif

