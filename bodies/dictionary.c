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

unsigned hash(DictKey key, int size){
	if(key < 0 || size <= 0){
		return 0;
	}
	return key % size;
}

void print_dict(Dictionary dict){
	printf("{");
	int i;
	for(i = 0; i < dict->size; i++){
		printf("\n\t%02d: ", i);
		print_map(dict->array[i]);
		
		if(i+1 == dict->size)
			printf("\n");
	}
	printf("}\n");
}

Bool insert_to_dict(DictKey key, DictValue value, Dictionary dict){
	if(dict == NULL)
		return False;
	
	int index = hash(key, dict->size);
	
	insert_map(key, value, &(dict->array[index]));
	return True;
}
