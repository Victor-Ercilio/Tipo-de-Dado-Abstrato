#include "tests_queue.h"

void Queue_TestAll(void){
	int width = 50;
	test_header("Testing Queue methods", width);
	test("Queue_EmptyQueue_ReturnsEmptyQueue", Queue_EmptyQueue_ReturnsEmptyQueue, width);
	test("PushToQueue_SingleItem_ReturnsTrue", PushToQueue_SingleItem_ReturnsTrue, width);
	test("PushToQueue_SingleItemInQueueFull_ReturnsFalse", PushToQueue_SingleItemInQueueFull_ReturnsFalse, width);
	test("PopFromQueue_SingleItemIn_ReturnsTrueAndItem", PopFromQueue_SingleItemIn_ReturnsTrueAndItem, width);
	test("PopFromQueue_SingleItemFromEmptyQueue_ReturnsFalse", PopFromQueue_SingleItemFromEmptyQueue_ReturnsFalse, width);
	test("QueueIsEmpty_EmptyQueue_ReturnsTrue", QueueIsEmpty_EmptyQueue_ReturnsTrue, width);
	test("QueueIsEmpty_SingleItemInQueue_ReturnsFalse", QueueIsEmpty_SingleItemInQueue_ReturnsFalse, width);
	test("QueueIsFull_EmptyQueue_ReturnsFalse", QueueIsFull_EmptyQueue_ReturnsFalse, width);
	test("QueueIsFull_SingleItemInQueue_ReturnsTrue", QueueIsFull_SingleItemInQueue_ReturnsTrue, width);
	test("DelQueue_EmptyQueue_QueuePonitsToNull", DelQueue_EmptyQueue_QueuePonitsToNull, width);
	test("DelQueue_QueuePointsToNull_QueuePonitsToNull", DelQueue_QueuePointsToNull_QueuePonitsToNull, width);
}

void Queue_EmptyQueue_ReturnsEmptyQueue(void){
	Queue q = NULL;
	
	q = queue(1);
	
	assert( q != NULL);
	del_queue(&q);
}

void PushToQueue_SingleItem_ReturnsTrue(void){
	Queue q = queue(1);
	QueueItem x = 0;
	Bool result = False;
	
	result = push_to_queue(x, q);
	
	assert( result == True );
	del_queue(&q);
}

void PushToQueue_SingleItemInQueueFull_ReturnsFalse(void){
	Queue q = queue(1);
	QueueItem x = 0;
	Bool push1_result = push_to_queue(x, q);
	Bool push2_result = True;
	
	push2_result = push_to_queue(x, q);
	
	assert( push1_result == True );
	assert( push2_result == False );
	del_queue(&q);
}

void PopFromQueue_SingleItemIn_ReturnsTrueAndItem(void){
	Queue q = queue(1);
	QueueItem item = 0;
	QueueItem x = 1;
	Bool push_result = push_to_queue(item, q);
	Bool pop_result = False;
	
	pop_result = pop_from_queue(&x, q);
	
	assert( push_result == True );
	assert( pop_result == True );
	assert( x == item );
	del_queue(&q);
}

void PopFromQueue_SingleItemFromEmptyQueue_ReturnsFalse(void){
	Queue q = queue(1);
	QueueItem x;
	Bool result = True;
	
	result = pop_from_queue(&x, q);
	
	assert( result == False);
	assert( x == x );
	del_queue(&q);
}

void QueueIsEmpty_EmptyQueue_ReturnsTrue(void){
	Queue q = queue(1);
	Bool result = False;
	
	result = queue_is_empty(q);
	
	assert( result == True );

	del_queue(&q);
}

void QueueIsEmpty_SingleItemInQueue_ReturnsFalse(void){
	Queue q = queue(1);
	QueueItem x = 0;
	Bool push_result = push_to_queue(x, q);
	Bool empty_result = True;
	
	empty_result = queue_is_empty(q);
	
	assert( push_result == True );
	assert( empty_result == False );

	del_queue(&q);
}

void QueueIsFull_EmptyQueue_ReturnsFalse(void){
	Queue q = queue(1);
	Bool result = True;
	
	result = queue_is_full(q);
	
	assert( result == False );

	del_queue(&q);
}

void QueueIsFull_SingleItemInQueue_ReturnsTrue(void){
	Queue q = queue(1);
	QueueItem x = 0;
	Bool push_result = push_to_queue(x, q);
	Bool is_full_result = False;
	
	is_full_result = queue_is_full(q);
	
	assert( push_result == True );
	assert( is_full_result == True );

	del_queue(&q);
}

void DelQueue_EmptyQueue_QueuePonitsToNull(void){
	Queue q = queue(1);
	
	del_queue(&q);
	
	assert( q == NULL );
}

void DelQueue_QueuePointsToNull_QueuePonitsToNull(void){
	Queue q = NULL;
	
	del_queue(&q);
	
	assert( q == NULL );
}


