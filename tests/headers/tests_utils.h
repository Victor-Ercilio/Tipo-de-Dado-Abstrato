#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "pointers_type.h"
#include "e_boolean.h"

/* Ponteiro para uma fun��o de teste */
typedef PtrFuncAllVoid TestFunc;

/* Tipos para maior legibilidade */
typedef PtrCharFrozen TestTitle;
typedef int TestTitleWidth;

/* Exibir um cabe�alho, geralmente */
/* na execu��o de todos os testes */
void test_header(TestTitle, TestTitleWidth);

/* Exibir o nome da fun��o e executar a */
/* fun��o de teste que foi passada */
void test(TestTitle, TestFunc, TestTitleWidth);

#endif
