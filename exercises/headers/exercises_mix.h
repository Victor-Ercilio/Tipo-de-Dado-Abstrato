#ifndef EXERCISES_MIX_H
#define EXERCISES_MIX_H

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"
#include "ask_for.h"
#include "e_boolean.h"
#include "pointers_type.h"

/* Exercício de Recursão 1: */
/* Crie a função recursiva que devolve a soma dos */
/* dígitos que compõe o numero natural n. */
/* ex: f(7859) = 7+8+5+9 = 29*/
int soma_digitos(int);

/* Exercício de Recursão 2: */
/* Usando a função soma_digito, crie a função */
/* recursiva super_digito */
int super_digito(int);

/* Exercício de Recursão 3: */
/* Usando as funções a seguir: */
int suc(int); // sucessor
int pred(int); //  predecessor
/* e nenhum operador aritméticio, crie as */
/* funções recursivas: */

/* a - A soma de dois números naturais */
int soma(int, int);
/* b - A subtração de dois números naturais */
int subtracao(int, int);
/* c - O dobro de um número natural */
int dobro(int);
/* d - A metade inteira de um número natural */
int metade_inteira(int);
/* e - O mínimo entre dois números naturais */
int minimo(int, int);
/* f - O máximo entre dois números naturais */
int maximo(int, int);
/* g - Se um número natural é par */
int eh_par(int);
/* h - Se um número natural é ímpar */
int eh_impar(int);


#endif
