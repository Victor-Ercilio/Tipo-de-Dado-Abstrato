#ifndef TESTS_STACK_H
#define TESTS_STACK_H

#include "tests_utils.h"
#include "stack.h"

void Stack_TestAll(void);

void Stack_EmptyStack_ReturnsEmptyStack(void);

void PushToStack_SingleItem_ReturnsTrue(void);

void PushToStack_SingleItemInStackFull_ReturnsFalse(void);

void PopFromStack_SingleItemIn_ReturnsTrueAndItem(void);

void PopFromStack_SingleItemFromEmptyStack_ReturnsFalse(void);

void StackTop_SingleItemIn_ReturnsTrueAndItem(void);

void StackTop_SingleItemFromEmptyStack_ReturnsFalse(void);

void StackIsEmpty_EmptyStack_ReturnsTrue(void);

void StackIsEmpty_SingleItemInStack_ReturnsFalse(void);

void StackIsFull_EmptyStack_ReturnsFalse(void);

void StackIsFull_SingleItemInStack_ReturnsTrue(void);

void DelStack_EmptyStack_StackPonitsToNull(void);

void DelStack_StackPointsToNull_StackPonitsToNull(void);

#endif

