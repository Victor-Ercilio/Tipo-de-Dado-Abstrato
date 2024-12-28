#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h> /* free, malloc */

#include "e_boolean.h"

#ifndef QUEUE_ITEM
#define QUEUE_ITEM
/* Define o tipo dos itens da fila */
typedef int QueueItem;
#endif

/* Define a strutura da fila */
/* e um nome para um ponteiro do tipo dela*/
typedef struct queue {
	unsigned max;
	unsigned size;
	unsigned begin;
	unsigned end;
	QueueItem* items;
}* Queue;

/* Fun��o que cria e retorna um fila de tamanho especificado */
Queue queue(unsigned);

/* Insere no final da fila o item fornecido se poss�vel */
/* retorna True de bem sucessido ou False caso contr�rio */
Bool push_to_queue(QueueItem, Queue);

/* Remove um item da fila se houver */
/* retorna True de bem sucessido ou False caso contr�rio */
Bool pop_from_queue(QueueItem*, Queue);

/* Retorna se a fila est� vazia */
Bool queue_is_empty(Queue);

/* Retorna se a fila est� cheia*/
Bool queue_is_full(Queue);

/* Destroi a fila */
void del_queue(Queue*);

#endif
