#ifndef TREE_H
#define TREE_H

#include <stdlib.h> // malloc e free
#include <stdio.h> // printf

#include "e_boolean.h" // Bool

typedef int TreeItem;

typedef enum treeTraversial {
	PRE_ORDER = 1,
	IN_ORDER,
	POST_ORDER
} TreeTraversial;

typedef struct tree {
	TreeItem item;
	struct tree* left;
	struct tree* right;
} * Tree;

// Construtor dos n�s da �vore
Tree tree(Tree, TreeItem, Tree);

// Exibe a �vore em pr�-ordem, em-ordem ou p�s-ordem
void print_tree(Tree, TreeTraversial);

// Remove as folhas da �rvore
void prune_tree(Tree*);

// Conta a quantidade de folhas
int count_leaves_tree(Tree);

// Conta a quantidade de n�s da �rvore
int count_nodes_tree(Tree);

// Retorna a altura da �vore
int high_tree(Tree);

// Retorna a c�pia espelhada de uma �vore
Tree mirrored_tree(Tree);

// Cria uma �rvore completa dada a altura
Tree full_tree_of(unsigned);

// Cria um clone de uma �rvore
Tree clone_tree(Tree);

// Diz se h� um dado item na �rvore
Bool has_item_in_tree(TreeItem, Tree);

// Insere de forma bin�ria os itens na �rvore
Bool insert_tree(TreeItem, Tree*);

// Diz se h� um dado item na �vore considerando que ela seja bin�ria
Bool binary_search_tree(TreeItem, Tree);

// Remove o n� com o maior item de uma �rvore bin�ria
void remove_max_item_tree(TreeItem*, Tree*);

// Remove a raiz da �rvore
void remove_root_tree(Tree*);

// Remove o n� com o item da �rvore (bin�ria)
void remove_from_tree(TreeItem, Tree*);

// Destr�i a �rvore e libera a mem�ria
void del_tree(Tree*);

#endif
