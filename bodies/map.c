#include "map.h"

Map node_map(MapKey key, MapValue value, Map map){
	Map m = malloc(sizeof(struct map));
	m->key = key;
	strcpy(m->value, value);
	m->next = map;
	return m;
}

void insert_map(MapKey key, MapValue value, Map* map){
	if(map == NULL) return;
	
	while((*map) != NULL && key > (*map)->key){
		map = &(*map)->next;
	}
	
	Map temp = *map;
	if(temp == NULL){
		*map = node_map(key, value, *map);
	}else if(key == temp->key){
		strcpy(temp->value, value);
	}else{
		*map = node_map(key, value, temp);
	}
}

void print_map(Map map){
	printf("[");
	while(map != NULL){
		printf("%d: %s", map->key, map->value);
		map = map->next;
		if(map != NULL)
			printf(", ");
	}
	printf("]\n");
}

void remove_from_map(MapKey key, Map* map){
	if(map == NULL) return;
	
	while(*map != NULL && key > (*map)->key)
		map = &(*map)->next;

	
	if(*map != NULL && key == (*map)->key){
		Map aux = *map;
		*map = aux->next;
		free(aux);	
	}
}

Bool has_key_map(MapKey key, MapValue value, Map map){
	while(map != NULL && key > map->key)
		map = map->next;
	if(map != NULL && key == map->key){
		strcpy(value, map->value);
		return True;
	}
	return False;
}

void del_map(Map* map){
	if(*map == NULL) return;
	while((*map) != NULL){
		Map m = *map;
		*map = m->next;
		free(m);
	}
}
