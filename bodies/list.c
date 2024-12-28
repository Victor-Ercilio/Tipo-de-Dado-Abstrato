#include "list.h"

List node_list(ListItem item, List list){
	List l = malloc(sizeof(struct node_list));
	l->item = item;
	l->next = list;
	return l;
}

void print_list(List list, ListName name){
	printf("%s -> [", name);
	while(list != NULL){
		printf("%d%s", list->item, (list->next != NULL)?", ":"");
		list = list->next;
	}
	printf("]\n");
}

int len_list(List list){
	int i = 0;
	while(list){
		list = list->next;
		i++;
	}
	
	return i;
}

List range(ListItem number){
	List list = NULL;
	
	while(number > 0)
		list = node_list(number--, list);
	
	return list;
}

List random_list(int total, int max){
	List list = NULL;
	
	while(total > 0){
		list = node_list(rand()%max, list);
		total--;
	}
	
	return list;
}

void append_list(List* a, List b){
	if((b) == NULL){
		return;
	}
	while((*a) != NULL)
		a = &(*a)->next;
	
	*a = b;
}

void del_list(List* list){
	
	while((*list) != NULL){
		List l = (*list);
		(*list)	= l->next;
		free(l);
	}
	(*list) = NULL;
}
