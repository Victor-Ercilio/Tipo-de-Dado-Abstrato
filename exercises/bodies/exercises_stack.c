#include "exercises_stack.h"

/* Exercício 1: */
/* Dado um número em natural decimal (base 10), */
/* exibi-lo em binário */
void show_decimal_to_bin(unsigned number){
	Stack s = stack(50);
	StackItem x;
	
	while(number > 0){
		push_to_stack(number%2, s);
		number /= 2;
	}
	
	printf("Bin: ");
	while( pop_from_stack( &x, s) )
		printf("%d%s", x, (stack_is_empty(s))?"\n":"");
	
	del_stack(&s);
}

/* Exercício 2: */
/* Dado um cadeia, */
/* mostrala na ordem inversa */
void show_reverse_string(ConstStr string){
	Stack s = stack(500);
	int i;
	
	while( *string ){
		if(push_to_stack((StackItem) *string, s))
			string++;
		else
			break;
	}
	
	printf("Reversa: ");
	while( !stack_is_empty(s) ){
		StackItem x;
		if(pop_from_stack(&x, s))
			printf("%c%s", x, (stack_is_empty(s)?"\n":""));
	}
	
	del_stack(&s);	
}

/* Exercício 3: */
/* Dado uma sequencia com n número, */
/* exiba em ordem crescente */
void show_ordered_int(int size){
	Stack A = stack(size);
	Stack B = stack(size);
	StackItem item;
	int i, x;
	
	for(i = 0; i < size; i++){
		while(!ask_for_int("num:", &x));
		
		while(stack_top(&item, A) && x > item){
			pop_from_stack(&item, A);
			push_to_stack(item, B);
		}
			
		push_to_stack(x, A);
		
		while(!stack_is_empty(B)){
			pop_from_stack(&item, B);
			push_to_stack(item, A);
		}		
	}
	
	while(pop_from_stack(&item, A))
		printf("%d%s", item, (stack_is_empty(A) ? "\n" : " "));
	
	del_stack(&A);
	del_stack(&B);
}

/* Exercício 4: */
/* Verificar se uma expressão composta por (), {}, [] */
/* está balanceada */
Bool is_exp_balanced(ConstStr exp){
	Stack s = stack(20);
	StackItem x;
	Bool ExpretionValid = False;
	
	for(; *exp; exp++){
		switch(*exp){
			case '(':
				push_to_stack(')', s);
				break;
			case '{':
				push_to_stack('}', s);
				break;
			case '[':
				push_to_stack(']', s);
				break;
			default:
				if(pop_from_stack(&x, s) && x == (*exp)){
						continue;
				}else{
					del_stack(&s);
					return False;
				}
		}
	}
	
	if(stack_is_empty(s))
		ExpretionValid = True;
	else
		ExpretionValid = False;
	
	del_stack(&s);
	return ExpretionValid;
}

/* Exercício 6: */
void show_next_bigger_int(PtrIntConstData vetor, unsigned size){
	Stack A = stack(size);
	StackItem x;
	int i;
	
	printf("Proximo Maior Numero(n) = pmi(n)\n\n");
	for(i = 0; i < size; i++){
		if(stack_is_empty(A))
			push_to_stack(vetor[i], A);
		else{
			while(stack_top(&x, A) && x < vetor[i]){
				pop_from_stack(&x, A);
				printf("pmi(%d) = %d\n", x, vetor[i]);
			}
			push_to_stack(vetor[i], A);

		}
	}
	
	while(!stack_is_empty(A)){
		if(pop_from_stack(&x, A))
			printf("pmi(%d) = infinito\n", x);
	}
	
	del_stack(&A);
}
