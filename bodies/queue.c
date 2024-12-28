#include "queue.h"

Queue queue(unsigned size){
	if(size > 0){
		Queue q = malloc(sizeof(struct queue));
		q->begin = 0;
		q->end = 0;
		q->size = 0;
		q->max = size;
		q->items = malloc(sizeof(QueueItem) * size);
		return q;
	}
	return NULL;
}

Bool push_to_queue(QueueItem item, Queue queue){
	if( queue_is_full(queue) ){
		return False;
	}
	queue->items[queue->end] = item;
	queue->end = (queue->end + 1) % queue->max;
	queue->size++;
	return True;
}

Bool pop_from_queue(QueueItem* item, Queue queue){
	if( queue_is_empty(queue) ){
		return False;
	}
	*item = queue->items[queue->begin];
	queue->begin = (queue->begin + 1) % queue->max;
	queue->size--;
	return True;
}

Bool queue_is_empty(Queue queue){
	return (queue->size == 0);
}

Bool queue_is_full(Queue queue){
	return (queue->size == queue->max);
}

void del_queue(Queue* queue){
	if((*queue) != NULL){
		free((*queue)->items);
		free(*queue);
	}
	*queue = NULL;
}

