#ifndef TESTS_QUEUE_H
#define TESTS_QUEUE_H

#include "tests_utils.h"
#include "queue.h"

void Queue_TestAll(void);

void Queue_EmptyQueue_ReturnsEmptyQueue(void);

void PushToQueue_SingleItem_ReturnsTrue(void);

void PushToQueue_SingleItemInQueueFull_ReturnsFalse(void);

void PopFromQueue_SingleItemIn_ReturnsTrueAndItem(void);

void PopFromQueue_SingleItemFromEmptyQueue_ReturnsFalse(void);

void QueueIsEmpty_EmptyQueue_ReturnsTrue(void);

void QueueIsEmpty_SingleItemInQueue_ReturnsFalse(void);

void QueueIsFull_EmptyQueue_ReturnsFalse(void);

void QueueIsFull_SingleItemInQueue_ReturnsTrue(void);

void DelQueue_EmptyQueue_QueuePonitsToNull(void);

void DelQueue_QueuePointsToNull_QueuePonitsToNull(void);

#endif

