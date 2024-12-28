#include "stack.h"

/* Função que cria a pilha de n tamnho */
Stack stack(unsigned size){
	if( size > 0 ){
		Stack s = malloc(sizeof(struct stack));
		s->max = size;
		s->top = -1;
		s->items = malloc(sizeof(StackItem) * size);
		return s;
	}
	return NULL;
}

/* Função que adiciona itens na pilha */
Bool push_to_stack(StackItem item, Stack stack){
	if( !stack_is_full(stack) ){
		stack->items[++stack->top] = item;
		return True;
	}
	return False;
}

/* Função que diz se a pilha está vazia */
Bool stack_is_empty(Stack stack){
	return (stack->top == -1);
}

/* Função que diz se a pilha está cheia */
Bool stack_is_full(Stack stack){
	return (stack->top + 1 == stack->max);
}

/* Função que retorna o item no topo da pilha, mas não remove */
/* Retorna 1 se bem sucedido e 0 do contrário */
Bool stack_top(StackItem* item, Stack stack){
	if( stack_is_empty(stack) )
		return False;
	else{
		*item = stack->items[stack->top];
		return True;
	}
}

/* Função que retorna o item no topo da pilha e o remove */
/* Retorna 1 se bem sucedido e 0 do contrário */
Bool pop_from_stack(StackItem* item, Stack stack){
	if( stack_is_empty(stack) )
		return False;
	else{
		*item = stack->items[stack->top--];
		return True;
	}
}

/* Função que desaloca os recursos utilizados pela pilha*/
void del_stack(Stack* stack){
	if( (*stack) != NULL ){
		free((*stack)->items);
		free(*stack);
	}
	*stack = NULL;
}

