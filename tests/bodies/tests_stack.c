#include "tests_stack.h"

void Stack_TestAll(void){
	int width = 50;
	test_header("Testing Stack methods", width);
	test("Stack_EmptyStack_ReturnsEmptyStack", Stack_EmptyStack_ReturnsEmptyStack, width);
	test("PushToStack_SingleItem_ReturnsTrue", PushToStack_SingleItem_ReturnsTrue, width);
	test("PushToStack_SingleItemInStackFull_ReturnsFalse", PushToStack_SingleItemInStackFull_ReturnsFalse, width);
	test("PopFromStack_SingleItemIn_ReturnsTrueAndItem", PopFromStack_SingleItemIn_ReturnsTrueAndItem, width);
	test("PopFromStack_SingleItemFromEmptyStack_ReturnsFalse", PopFromStack_SingleItemFromEmptyStack_ReturnsFalse, width);
	test("StackTop_SingleItemIn_ReturnsTrueAndItem", StackTop_SingleItemIn_ReturnsTrueAndItem, width);
	test("StackTop_SingleItemFromEmptyStack_ReturnsFalse", StackTop_SingleItemFromEmptyStack_ReturnsFalse, width);
	test("StackIsEmpty_EmptyStack_ReturnsTrue", StackIsEmpty_EmptyStack_ReturnsTrue, width);
	test("StackIsEmpty_SingleItemInStack_ReturnsFalse", StackIsEmpty_SingleItemInStack_ReturnsFalse, width);
	test("StackIsFull_EmptyStack_ReturnsFalse", StackIsFull_EmptyStack_ReturnsFalse, width);
	test("StackIsFull_SingleItemInStack_ReturnsTrue", StackIsFull_SingleItemInStack_ReturnsTrue, width);
	test("DelStack_EmptyStack_StackPonitsToNull", DelStack_EmptyStack_StackPonitsToNull, width);
	test("DelStack_StackPointsToNull_StackPonitsToNull", DelStack_StackPointsToNull_StackPonitsToNull, width);
}

void Stack_EmptyStack_ReturnsEmptyStack(void){
	Stack s = NULL;
	
	s = stack(1);
	
	assert( s != NULL );
	del_stack(&s);
}

void PushToStack_SingleItem_ReturnsTrue(void){
	Stack s = stack(1);
	StackItem item = 0;
	Bool push_result = False;
	
	push_result = push_to_stack(item, s);
	
	assert( push_result == True );
	del_stack(&s);
}

void PushToStack_SingleItemInStackFull_ReturnsFalse(void){
	Stack s = stack(1);
	StackItem item = 0;
	Bool push1_result = push_to_stack(item, s);
	Bool push2_result = True;
	
	push2_result = push_to_stack(item, s);
	
	assert( push1_result == True );
	assert( push2_result == False );
	
	del_stack(&s);
}

void PopFromStack_SingleItemIn_ReturnsTrueAndItem(void){
	Stack s = stack(1);
	StackItem item = 0;
	StackItem x = 1;
	Bool push_result = push_to_stack(item, s);
	Bool pop_result;
	
	pop_result = pop_from_stack(&x, s);
	
	assert( push_result == True );
	assert( pop_result == True );
	assert( x == item );
	
	del_stack(&s);
}

void PopFromStack_SingleItemFromEmptyStack_ReturnsFalse(void){
	Stack s = stack(1);
	StackItem x = 1;
	Bool pop_result = True;
	
	pop_result = pop_from_stack(&x, s);
	
	assert( pop_result == False );
	del_stack(&s);
}

void StackTop_SingleItemIn_ReturnsTrueAndItem(void){
	Stack s = stack(1);
	StackItem item = 0;
	StackItem x = 1;
	Bool push_result = push_to_stack(item, s);
	Bool pop_result = False;
	
	pop_result = pop_from_stack(&x, s);
	
	assert( push_result == True );
	assert( pop_result == True );
	assert( x == item );
	
	del_stack(&s);
}

void StackTop_SingleItemFromEmptyStack_ReturnsFalse(void){
	Stack s = stack(1);
	StackItem x = 1;
	Bool pop_result = True;
	
	pop_result = pop_from_stack(&x, s);
	
	assert( pop_result == False );
	assert( x == 1 );
	
	del_stack(&s);
}

void StackIsEmpty_EmptyStack_ReturnsTrue(void){
	Stack s = stack(1);
	Bool is_empty_result = False;
	
	is_empty_result = stack_is_empty(s);
	
	assert( is_empty_result == True );
	
	del_stack(&s);
}

void StackIsEmpty_SingleItemInStack_ReturnsFalse(void){
	Stack s = stack(1);
	Bool push_result = push_to_stack( 0, s);
	Bool is_empty_result = True;
	
	is_empty_result = stack_is_empty(s);
	
	assert( push_result == True );
	assert( is_empty_result == False );
	
	del_stack(&s);
}

void StackIsFull_EmptyStack_ReturnsFalse(void){
	Stack s = stack(1);
	Bool is_full_result = True;
	
	is_full_result = stack_is_full(s);
	
	assert( is_full_result == False );
	
	del_stack(&s);
}

void StackIsFull_SingleItemInStack_ReturnsTrue(void){
	Stack s = stack(1);
	StackItem x = 0;
	Bool push_result = push_to_stack( x, s);
	Bool is_full_result = False;
	
	is_full_result = stack_is_full(s);
	
	assert( push_result == True );
	assert( is_full_result == True );
	
	del_stack(&s);
}

void DelStack_EmptyStack_StackPonitsToNull(void){
	Stack s = NULL;
	s = stack(1);
	
	del_stack(&s);
	
	assert( s == NULL );
}

void DelStack_StackPointsToNull_StackPonitsToNull(void){
	Stack s = NULL;
	
	del_stack(&s);
	
	assert( s == NULL );
}

