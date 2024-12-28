#include "exercises_queue.h"

/* Exercício 1: */
void show_alphabet(void){
	int TOTAL_LETTERS = 26;
	Queue q = queue(TOTAL_LETTERS);
	
	{
		int i;
		for(i = 0; i < TOTAL_LETTERS; i++)
			push_to_queue('A'+i, q);
	}
	
	printf("Alphabet: ");
	while(!queue_is_empty(q)){
		QueueItem x;
		pop_from_queue(&x, q);
		printf("%c ", x);
	}
	printf("\n");
	
	del_queue(&q);
}

/* Exemplo 1: */
void show_process_flow(void){
	int timeslice = 3; // tempo máximo de uso ininterrupto de CPU
	Queue q = queue(5);
	push_to_queue(17, q); // 1º processo requer 7s para concluir sua execução
	push_to_queue(25, q);
	push_to_queue(39, q);
	push_to_queue(46, q);
	
	while(!queue_is_empty(q)){
		QueueItem x;
		pop_from_queue(&x, q);
		int p = x/10;
		int t = x%10;
		if(t > 3) {
			push_to_queue(p * 10+(t - timeslice), q);
			printf("Processando... (%d)\n", p * 10+(t - timeslice));
		}
		else printf("Processo %d concluido\n", p);
	}
	
	del_queue(&q);
}

/* Exercício 2: */
void filter_even_number_queue(Queue q){
	QueueItem endQueue = 0;
	if(push_to_queue(endQueue, q)){
		QueueItem x = -1;
		while(x != 0)
			if(pop_from_queue(&x, q))
				if(x%2==0 && x != 0) push_to_queue(x, q);
	}
}
