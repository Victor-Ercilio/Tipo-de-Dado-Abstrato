#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "e_boolean.h"
#include "pointers_type.h"

typedef MapKey DictKey;
typedef MapValue DictValue;

typedef struct dictionary {
	int size;
	Map *array;
} * Dictionary;

Dictionary dict(int);

unsigned hash(int, int);

void print_dict(Dictionary);

Bool insert_to_dict(DictKey, DictValue, Dictionary);

void remove_from_dict(DictKey, Dictionary);

Bool dict_has_key(DictKey, Dictionary);

void del_dict(Dictionary*);

#endif
