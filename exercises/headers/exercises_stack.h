#ifndef EXERCISES_STACK_H
#define EXERCISES_STACK_H

#include <stdio.h>
#include "stack.h"
#include "ask_for.h"
#include "pointers_type.h"

/* Tipos para maior legibilidade */
typedef PtrCharConstData ConstStr;

/* Exercício 1: */
/* Dado um número em natural decimal (base 10), */
/* exibi-lo em binário */
void show_decimal_to_bin(unsigned);

/* Exercício 2: */
/* Dado um cadeia, */
/* mostrala na ordem inversa */
void show_reverse_string(ConstStr);

/* Exercício 3: */
/* Dado uma sequencia com n número, */
/* exiba em ordem crescente */
void show_ordered_int(int);

/* Exercício 4: */
/* Verificar se uma expressão composta por (), {}, [] */
/* está balanceada */
Bool is_exp_balanced(ConstStr);

/* Exercício 5: */
/* ... */
/* ... */

/* Exercício 6: */
/* Dado um vetor v com n itens, use uma pilha para exibir
/* o próximo maior item para cada item de v. */
/* Caso não haja um número maior, deve-se exibir infinito */
void show_next_bigger_int(PtrIntConstData, unsigned);

#endif
