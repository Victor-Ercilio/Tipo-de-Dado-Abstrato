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

// Construtor dos nós da ávore
Tree tree(Tree, TreeItem, Tree);

// Exibe a ávore em pré-ordem, em-ordem ou pós-ordem
void print_tree(Tree, TreeTraversial);

// Remove as folhas da árvore
void prune_tree(Tree*);

// Conta a quantidade de folhas
int count_leaves_tree(Tree);

// Conta a quantidade de nós da árvore
int count_nodes_tree(Tree);

// Retorna a altura da ávore
int high_tree(Tree);

// Retorna a cópia espelhada de uma ávore
Tree mirrored_tree(Tree);

// Cria uma árvore completa dada a altura
Tree full_tree_of(unsigned);

// Cria um clone de uma árvore
Tree clone_tree(Tree);

// Diz se há um dado item na árvore
Bool has_item_in_tree(TreeItem, Tree);

// Insere de forma binária os itens na árvore
Bool insert_tree(TreeItem, Tree*);

// Diz se há um dado item na ávore considerando que ela seja binária
Bool binary_search_tree(TreeItem, Tree);

// Remove o nó com o maior item de uma árvore binária
void remove_max_item_tree(TreeItem*, Tree*);

// Remove a raiz da árvore
void remove_root_tree(Tree*);

// Remove o nó com o item da árvore (binária)
void remove_from_tree(TreeItem, Tree*);

// Destrói a árvore e libera a memória
void del_tree(Tree*);

#endif
