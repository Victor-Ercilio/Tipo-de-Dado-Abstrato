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

/* Fun��o que cria a pilha de n tamnho */
Stack stack(unsigned);

/* Fun��o que adiciona itens na pilha */
/* Retorna 1 se bem sucedido e 0 do contr�rio */
Bool push_to_stack(StackItem, Stack);

/* Fun��o que diz se a pilha est� vazia */
Bool stack_is_empty(Stack);

/* Fun��o que diz se a pilha est� cheia */
Bool stack_is_full(Stack);

/* Fun��o que retorna o item no topo da pilha, mas n�o remove */
/* Retorna 1 se bem sucedido e 0 do contr�rio */
Bool stack_top(StackItem*, Stack);

/* Fun��o que retorna o item no topo da pilha e o remove */
/* Retorna 1 se bem sucedido e 0 do contr�rio */
Bool pop_from_stack(StackItem*, Stack);

/* Fun��o que desaloca os recursos utilizados pela pilha*/
void del_stack(Stack*);

#endif

