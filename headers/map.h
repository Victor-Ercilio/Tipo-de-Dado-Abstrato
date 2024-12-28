#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pointers_type.h"
#include "e_boolean.h"

typedef int MapKey;

typedef char MapValue[21];

typedef struct map {
	MapValue value;
	MapKey key;
	struct map* next;
} * Map;

Map node_map(MapKey, MapValue, Map);

void insert_map(MapKey, MapValue, Map*);

void print_map(Map);

void remove_from_map(MapKey, Map*);

Bool has_key_map(MapKey, MapValue, Map);

void del_map(Map*);

#endif
