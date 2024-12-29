#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "e_boolean.h"
#include "pointers_type.h"

typedef MapKey DicKey;
typedef MapValue DicValue;

typedef struct dictionary {
	int size;
	Map *array;
} * Dictionary;

Dictionary dict(int);

unsigned hash(int, int);

void print_dict(Dictionary);

Bool insert_to_dict(DicKey, DicValue, Dictionary);

Bool remove_from_dict(DicKey, Dictionary);

Bool dict_has_key(DicKey, Dictionary);

void del_dict(Dictionary*);

#endif
