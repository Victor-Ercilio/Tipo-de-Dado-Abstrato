#ifndef EXERCISES_MIX_H
#define EXERCISES_MIX_H

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"
#include "ask_for.h"
#include "e_boolean.h"
#include "pointers_type.h"

/* Exerc�cio de Recurs�o 1: */
/* Crie a fun��o recursiva que devolve a soma dos */
/* d�gitos que comp�e o numero natural n. */
/* ex: f(7859) = 7+8+5+9 = 29*/
int soma_digitos(int);

/* Exerc�cio de Recurs�o 2: */
/* Usando a fun��o soma_digito, crie a fun��o */
/* recursiva super_digito */
int super_digito(int);

/* Exerc�cio de Recurs�o 3: */
/* Usando as fun��es a seguir: */
int suc(int); // sucessor
int pred(int); //  predecessor
/* e nenhum operador aritm�ticio, crie as */
/* fun��es recursivas: */

/* a - A soma de dois n�meros naturais */
int soma(int, int);
/* b - A subtra��o de dois n�meros naturais */
int subtracao(int, int);
/* c - O dobro de um n�mero natural */
int dobro(int);
/* d - A metade inteira de um n�mero natural */
int metade_inteira(int);
/* e - O m�nimo entre dois n�meros naturais */
int minimo(int, int);
/* f - O m�ximo entre dois n�meros naturais */
int maximo(int, int);
/* g - Se um n�mero natural � par */
int eh_par(int);
/* h - Se um n�mero natural � �mpar */
int eh_impar(int);


#endif
