#ifndef TESTS_LIST_H
#define TESTS_LIST_H

#include "tests_utils.h"
#include "list.h"

void List_TestAll(void);

void Node_ValidArguments_ReturnsList(void);

void Node_ValidItemsAndOtherNode_ReturnsList(void);

void Len_EmptyList_ReturnsZero(void);

void Len_ListWithNode_ReturnsTotalNodes(void);

void Range_NegativeNumberOfItems_ReturnsEmptyList(void);

void Range_ZeroItems_ReturnsEmptyList(void);

void Range_PositiveNumberOfItems_ReturnsList(void);

void RandomList_ValidArguments_ReturnsList(void);

#endif
