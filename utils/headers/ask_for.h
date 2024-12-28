#ifndef ASK_FOR_H
#define ASK_FOR_H

#include <stdio.h>

#include "pointers_type.h"
#include "check.h"

Bool ask_for_int(PtrCharConstData, PtrInt);

Bool ask_for_int_between(PtrCharConstData, int, int, PtrInt);

Bool ask_for_double(PtrCharFrozen, double*);

#endif
