#include "tests_list.h"

void List_TestAll(void){
	int width = 50;
	test_header("Testing List methods", width);
	test("Node_ValidArguments_ReturnsList", Node_ValidArguments_ReturnsList, width);
	test("Node_ValidItemsAndOtherNode_ReturnsList", Node_ValidItemsAndOtherNode_ReturnsList, width);
	test("Len_EmptyList_ReturnsZero", Len_EmptyList_ReturnsZero, width);
	test("Len_ListWithNode_ReturnsTotalNodes", Len_ListWithNode_ReturnsTotalNodes, width);
	test("Range_NegativeNumberOfItems_ReturnsEmptyList", Range_NegativeNumberOfItems_ReturnsEmptyList, width);
	test("Range_ZeroItems_ReturnsEmptyList", Range_ZeroItems_ReturnsEmptyList, width);
	test("Range_PositiveNumberOfItems_ReturnsList", Range_PositiveNumberOfItems_ReturnsList, width);
	test("RandomList_ValidArguments_ReturnsList", RandomList_ValidArguments_ReturnsList, width);
	// Template: test("", , width);
}

void Node_ValidArguments_ReturnsList(void){
	List l = NULL;
	
	l = node_list(1, l);
	
	assert(l != NULL);
	del_list(&l);
}

void Node_ValidItemsAndOtherNode_ReturnsList(void){
	List other = node_list(0, NULL);
	List actual = NULL;
	
	actual = node_list(0, other);
	
	assert( actual != NULL);
	assert(actual->next == other);
	
	del_list(&actual);
	other = NULL;
}

void Len_EmptyList_ReturnsZero(void){
	List actual = NULL;
	int list_size = -1;
	
	list_size = len_list(actual);
	
	assert(list_size == 0);
}

void Len_ListWithNode_ReturnsTotalNodes(void){
	List actual = node_list(0, node_list(1, NULL));
	const int TOTAL_NODES = 2;
	int list_size = -1;
	
	list_size = len_list(actual);
	
	assert(list_size == TOTAL_NODES);
	del_list(&actual);
}

void Range_NegativeNumberOfItems_ReturnsEmptyList(void){
	List actual = NULL;
	const int ITEMS = -1;
	
	actual = range(ITEMS);
	
	assert(actual == NULL);
}

void Range_ZeroItems_ReturnsEmptyList(void){
	List actual = NULL;
	const int ITEMS = 0;
	
	actual = range(ITEMS);
	
	assert(actual == NULL);
}

void Range_PositiveNumberOfItems_ReturnsList(void){
	List actual = NULL;
	const int ITEMS = 1;
	
	actual = range(ITEMS);
	
	assert(actual != NULL);
	del_list(&actual);
}

void RandomList_ValidArguments_ReturnsList(void){
	List actual = NULL;
	const int TOTAL_ITEMS = 2;
	
	actual = random_list(TOTAL_ITEMS, 2);
	
	assert(actual != NULL);
	assert(len_list(actual) == TOTAL_ITEMS);
	del_list(&actual);
}
