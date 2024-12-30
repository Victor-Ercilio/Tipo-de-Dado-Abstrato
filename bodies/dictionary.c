#include "dictionary.h"

Dictionary dict(int size){
	if(size <= 0) return NULL;
	
	Dictionary dic = malloc(sizeof(struct dictionary));
	dic->size = size;
	dic->array = malloc(sizeof(Map)*size);
	int i;
	for(i = 0; i < size; i++)
		dic->array[i]  = NULL;

	return dic;
}

void del_dict(Dictionary* dict){
	if(dict == NULL || *dict == NULL) return;
	
	int i;
	Dictionary temp = *dict;
	for(i = 0; i < temp->size; i++)
		del_map(&temp->array[i]);
	
	free(temp->array);
	free(*dict);
	*dict = NULL;
	return;
}
