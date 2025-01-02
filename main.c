#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"
#include "list.h"
#include "map.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

#include "tests_stack.h"
#include "tests_queue.h"
#include "tests_list.h"
#include "tests_map.h"
#include "tests_tree.h"
#include "tests_dictionary.h"


int main(int argc, char *argv[]) {
	
	//Stack_TestAll();
	//Queue_TestAll();
	//List_TestAll();
	//Map_TestAll();
	//Tree_TestAll();
	Dictionary_TestAll();
	
	//Dictionary d = dict(5);
	//d->array[0] = node_map(1, "Banana", NULL);
	//d->array[1] = node_map(1, "Laranja", NULL);
	//d->array[2] = node_map(1, "Pera", NULL);
	//d->array[3] = node_map(1, "Maca", NULL);
	//d->array[4] = node_map(1, "Limao", NULL);
	
	//print_dict(d);

	//del_dict(&d);
	return 0;
}
