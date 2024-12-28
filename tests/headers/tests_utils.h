#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "pointers_type.h"
#include "e_boolean.h"

/* Ponteiro para uma função de teste */
typedef PtrFuncAllVoid TestFunc;

/* Tipos para maior legibilidade */
typedef PtrCharFrozen TestTitle;
typedef int TestTitleWidth;

/* Exibir um cabeçalho, geralmente */
/* na execução de todos os testes */
void test_header(TestTitle, TestTitleWidth);

/* Exibir o nome da função e executar a */
/* função de teste que foi passada */
void test(TestTitle, TestFunc, TestTitleWidth);

#endif
