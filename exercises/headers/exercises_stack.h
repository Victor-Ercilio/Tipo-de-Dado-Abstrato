#ifndef EXERCISES_STACK_H
#define EXERCISES_STACK_H

#include <stdio.h>
#include "stack.h"
#include "ask_for.h"
#include "pointers_type.h"

/* Tipos para maior legibilidade */
typedef PtrCharConstData ConstStr;

/* Exerc�cio 1: */
/* Dado um n�mero em natural decimal (base 10), */
/* exibi-lo em bin�rio */
void show_decimal_to_bin(unsigned);

/* Exerc�cio 2: */
/* Dado um cadeia, */
/* mostrala na ordem inversa */
void show_reverse_string(ConstStr);

/* Exerc�cio 3: */
/* Dado uma sequencia com n n�mero, */
/* exiba em ordem crescente */
void show_ordered_int(int);

/* Exerc�cio 4: */
/* Verificar se uma express�o composta por (), {}, [] */
/* est� balanceada */
Bool is_exp_balanced(ConstStr);

/* Exerc�cio 5: */
/* ... */
/* ... */

/* Exerc�cio 6: */
/* Dado um vetor v com n itens, use uma pilha para exibir
/* o pr�ximo maior item para cada item de v. */
/* Caso n�o haja um n�mero maior, deve-se exibir infinito */
void show_next_bigger_int(PtrIntConstData, unsigned);

#endif
