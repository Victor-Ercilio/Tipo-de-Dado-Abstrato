#include "tree.h"

Tree tree(Tree left, TreeItem item, Tree right){
	Tree T = malloc(sizeof(struct tree));
	T->item = item;
	T->left = left;
	T->right = right;
	return T;
}

void print_tree(Tree T, TreeTraversial order){
	static int level = 1;
	if(T == NULL) return;
	
	switch(order){
		case PRE_ORDER:
			printf("%*s%d\n", level, " ", T->item);
			level++;
			print_tree(T->left, order);
			print_tree(T->right, order);
			level--;
			break;
		case IN_ORDER:
			level++;
			print_tree(T->left, order);
			level--;
			printf("%*s%d\n", level, " ", T->item);
			level++;
			print_tree(T->right, order);
			level--;
			break;
		case POST_ORDER:
			level++;
			print_tree(T->left, order);
			print_tree(T->right, order);
			level--;
			printf("%*s%d\n", level, " ", T->item);
			break;
	}
}

void prune_tree(Tree* T){
	if(*T == NULL) return;
	if((*T)->left == NULL && (*T)->right==NULL){
		free(*T);
		*T = NULL;
		return;
	}
	prune_tree(&(*T)->left);
	prune_tree(&(*T)->right);
}

int count_leaves_tree(Tree T){
	if(T == NULL) return 0;
	if(T->left == NULL && T->right == NULL)
		return 1;
	return count_leaves_tree(T->left) + count_leaves_tree(T->right);
}

int count_nodes_tree(Tree T){
	if(T == NULL) return 0;
	return 1  + count_nodes_tree(T->left) + count_nodes_tree(T->right);
}

int high_tree(Tree T){
	if(T == NULL) return 0;
	if(T->left == NULL && T->right == NULL) return 0;
	return 1 + high_tree(T->left) + high_tree(T->right);
}

Tree mirrored_tree(Tree T){
	if(T == NULL) return NULL;
	return tree(mirrored_tree(T->right), T->item, mirrored_tree(T->left));
}

Tree full_tree_of(unsigned deepth){
	if(deepth == 0)
		return NULL;
	return tree(full_tree_of(deepth-1), deepth, full_tree_of(deepth-1));
}

Tree clone_tree(Tree T){
	if(T == NULL) return NULL;
	return tree(clone_tree(T->left), T->item, clone_tree(T->right));
}

Bool has_item_in_tree(TreeItem item, Tree T){
	if(T == NULL) return False;
	if(item == T->item) return True;
	return has_item_in_tree(item, T->left) || has_item_in_tree(item, T->right);
}

Bool insert_tree(TreeItem item, Tree* T){
	if((*T) == NULL){
		*T = tree(NULL, item, NULL);
		return True;
	}
	if((*T)->item == item) 
		return False;
	
	if((*T)->item < item) 
		insert_tree(item, &(*T)->left);
	else
		insert_tree(item, &(*T)->right);
}

Bool binary_search_tree(TreeItem item, Tree T){
	if(T == NULL) return False;
	if(T->item == item) return True;
	if(item > T->item) return binary_search_tree(item, T->right);
	else return binary_search_tree(item, T->left);
}

void remove_max_item_tree(TreeItem* item, Tree* T){
	if(*T == NULL) return;
	if((*T)->right == NULL){
		Tree node = *T;
		*item = node->item;
		*T = node->left;
		free(node);
		return;
	}
	remove_max_item_tree(item, &(*T)->right);
}

void remove_root_tree(Tree* T){
	if(*T == NULL) 
		return;
	
	Tree node = *T;
	if(node->left == NULL)
		*T = node->right;
	else if(node->right == NULL)
		*T = node->left;
	else{
		TreeItem x;
		remove_max_item_tree(&x, &(*T)->left);
		(*T)->item = x;
	}
	if(node != *T)
		free(node);
	
	return;
}

void remove_from_tree(TreeItem item, Tree* T){
	if(*T == NULL) return;
	if((*T)->item == item){
		remove_root_tree(T);	
	} 
	else if(item < (*T)->item){
		remove_from_tree(item, &(*T)->left);
	}
	else{
		remove_from_tree(item, &(*T)->right);
	}
}

void del_tree(Tree* T){
	if( *T == NULL ) return;
	if((*T)->left != NULL )
		del_tree(&(*T)->left);
	if((*T)->right != NULL )
		del_tree(&(*T)->right);
	free(*T);
	*T = NULL;
}
