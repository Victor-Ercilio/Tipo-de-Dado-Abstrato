#include "tests_tree.h"

void Tree_TestAll(void){
	int width = 70;
	test_header("Testing Tree methods", width);
	
	//    abcdefghijklmnopqrstuvwxyz12345678901234|567890123456
	test("Tree_NotNullLeaves_ReturnTreeWithLeaves", Tree_NotNullLeaves_ReturnTreeWithLeaves, width);
	
	test("DelTree_NotNullTree_TreePointsToNull", DelTree_NotNullTree_TreePointsToNull, width);
	test("DelTree_NullTree_TreePointsToNull", DelTree_NullTree_TreePointsToNull, width);
	
	test("FullTreeOf_SizeZero_ReturnNull", FullTreeOf_SizeZero_ReturnNull, width);
	test("FullTreeOf_SizeOne_ReturnTreeWithRoot", FullTreeOf_SizeOne_ReturnTreeWithRoot, width);
	test("FullTreeOf_SizeTwo_ReturnTreeWithDeepthOfTwo", FullTreeOf_SizeTwo_ReturnTreeWithDeepthOfTwo, width);
	
	test("InsertTree_NullTree_ReturnTrue", InsertTree_NullTree_ReturnTrue, width);
	test("InsertTree_TreeWithRootAndItemNotInTree_ReturnTrue", InsertTree_TreeWithRootAndItemNotInTree_ReturnTrue, width);
	test("InsertTree_TreeWithRootAndItemInTree_ReturnFalse", InsertTree_TreeWithRootAndItemInTree_ReturnFalse, width);
	
	test("BinarySearchTree_EmptyTree_ReturnFalse", BinarySearchTree_EmptyTree_ReturnFalse, width);
	test("BinarySearchTree_TreeHasItem_ReturnTrue", BinarySearchTree_TreeHasItem_ReturnTrue, width);
	test("BinarySearchTree_TreeDoesNotHaveItem_ReturnFalse", BinarySearchTree_TreeDoesNotHaveItem_ReturnFalse, width);
	
	test("RemoveMaxItemTree_EmptyTree_ShouldDoNothing", RemoveMaxItemTree_EmptyTree_ShouldDoNothing, width);
	test("RemoveMaxItemTree_TreeWithOnlyRoot_TreeShouldPointsToNull", RemoveMaxItemTree_TreeWithOnlyRoot_TreeShouldPointsToNull, width);
	test("RemoveMaxItemTree_TreeWithLeaves_ShouldRemoveBiggestRightLeaf", RemoveMaxItemTree_TreeWithLeaves_ShouldRemoveBiggestRightLeaf, width);
	
	test("RemoveRootTree_EmptyTree_ShouldDoNothing", RemoveRootTree_EmptyTree_ShouldDoNothing, width);
	test("RemoveRootTree_TreeWithOnlyRoot_TreeShouldPointsToNull", RemoveRootTree_TreeWithOnlyRoot_TreeShouldPointsToNull, width);
	test("RemoveRootTree_TreeWithLeaves_ShouldReplaceRootItemWithTheBiggestLeftItemAndDeleteBiggestLeftLeaf", RemoveRootTree_TreeWithLeaves_ShouldReplaceRootItemWithTheBiggestLeftItemAndDeleteBiggestLeftLeaf, width);
	
	test("RemoveFromTree_EmptyTree_ShouldDoNoting", RemoveFromTree_EmptyTree_ShouldDoNoting, width);
	test("RemoveFromTree_TreeNotEmptyAndWithoutItem_ShouldDoNothing", RemoveFromTree_TreeNotEmptyAndWithoutItem_ShouldDoNothing, width);
	test("RemoveFromTree_TreeNotEmptyAndWithItem_ShouldDeleteNodeWithItem", RemoveFromTree_TreeNotEmptyAndWithItem_ShouldDeleteNodeWithItem, width);
	
	test("PruneTree_EmptyTree_ShouldDoNothing", PruneTree_EmptyTree_ShouldDoNothing, width);
	test("PruneTree_TreeWithOnlyRoot_ShouldRemoveRoot", PruneTree_TreeWithOnlyRoot_ShouldRemoveRoot, width);
	test("PruneTree_TreeWithLeaves_ShouldRemoveTheLeaves", PruneTree_TreeWithLeaves_ShouldRemoveTheLeaves, width);
	
	test("CountLeavesTree_EmptyTree_ReturnZero", CountLeavesTree_EmptyTree_ReturnZero, width);
	test("CountLeavesTree_TreeWithOnlyRoot_ReturnOne", CountLeavesTree_TreeWithOnlyRoot_ReturnOne, width);
	test("CountLeavesTree_TreeWithLeaves_ReturnTheNumberOfLeaves", CountLeavesTree_TreeWithLeaves_ReturnTheNumberOfLeaves, width);
	
	test("HighTree_EmptyTree_ReturnZero", HighTree_EmptyTree_ReturnZero, width);
	test("HighTree_TreeWithOnlyRoot_ReturnZero", HighTree_TreeWithOnlyRoot_ReturnZero, width);
	test("HighTree_TreeWithHighOne_ReturnOne", HighTree_TreeWithHighOne_ReturnOne, width);
	test("HighTree_IrregularTreeOfHighTwo_ReturnTwo", HighTree_IrregularTreeOfHighTwo_ReturnTwo, width);
	
	test("CountNodesTree_EmptyTree_ReturnZero", CountNodesTree_EmptyTree_ReturnZero, width);
	test("CountNodesTree_TreeWithOnlyRoot_ReturnOne", CountNodesTree_TreeWithOnlyRoot_ReturnOne, width);
	test("CountNodesTree_TreeWithThreeNodes_ReturnThree", CountNodesTree_TreeWithThreeNodes_ReturnThree, width);
	
	test("MirroredTree_EmptyTree_ReturnNULL", MirroredTree_EmptyTree_ReturnNULL, width);
	test("MirroredTree_TreeWithOnlyRoot_ReturnCopyTree", MirroredTree_TreeWithOnlyRoot_ReturnCopyTree, width);
	test("MirroredTree_TreeWithLeaves_ReturnCopyTreeWithSwappedLeaves", MirroredTree_TreeWithLeaves_ReturnCopyTreeWithSwappedLeaves, width);
	
	test("CloneTree_EmptyTree_ReturnNull", CloneTree_EmptyTree_ReturnNull, width);
	test("CloneTree_TreeWithOnlyRoot_ReturnCopyTree", CloneTree_TreeWithOnlyRoot_ReturnCopyTree, width);
	test("CloneTree_TreeWithLeaves_ReturnCopyTree", CloneTree_TreeWithLeaves_ReturnCopyTree, width);
	
	test("HasItemInTree_EmptyTree_ReturnFalse", HasItemInTree_EmptyTree_ReturnFalse, width);
	test("HasItemInTree_TreeWithItem_ReturnTrue", HasItemInTree_TreeWithItem_ReturnTrue, width);
	test("HasItemInTree_TreeWithoutItem_ReturnFalse", HasItemInTree_TreeWithoutItem_ReturnFalse, width);
	// Template: test("", , width);
}

void Tree_NullLeaves_ReturnTree(void){
	Tree actual = NULL;
	
	actual = tree(NULL, 0, NULL);
	
	assert(actual != NULL);
	del_tree(&actual);
}

void Tree_NotNullLeaves_ReturnTreeWithLeaves(void){
	Tree actual = NULL;
	Tree leftLeaf = tree(NULL, 1, NULL);
	Tree rightLeaf = tree(NULL, 2, NULL);
	
	actual = tree(leftLeaf, 0, rightLeaf);
	
	assert(actual != NULL);
	assert(actual->left == leftLeaf);
	assert(actual->right == rightLeaf);
	del_tree(&actual);
}

/* - */

void FullTreeOf_SizeZero_ReturnNull(void){
	Tree actual = NULL;
	int depth = 0;
	
	actual = full_tree_of(depth);
	
	assert(actual == NULL);
}

void FullTreeOf_SizeOne_ReturnTreeWithRoot(void){
	Tree actual = NULL;
	int depth = 1;
	
	actual = full_tree_of(depth);
	
	assert(actual != NULL);
	del_tree(&actual);
}

void FullTreeOf_SizeTwo_ReturnTreeWithDeepthOfTwo(void){
	Tree actual = NULL;
	int depth = 2;
	
	actual = full_tree_of(depth);
	
	assert(actual != NULL);
	assert(actual->left != NULL);
	assert(actual->right != NULL);
	del_tree(&actual);
}

/* - */

void InsertTree_NullTree_ReturnTrue(void){
	Tree actual = NULL;
	TreeItem item = 0;
	Bool inserted = False;
	
	inserted = insert_tree(item, &actual);
	
	assert(inserted == True);
	assert(actual != NULL);
	del_tree(&actual);
}

void InsertTree_TreeWithRootAndItemNotInTree_ReturnTrue(void){
	TreeItem midleItem = 5;
	TreeItem item = midleItem - 1;
	Tree actual = tree(NULL, midleItem, NULL);
	Bool inserted = False;
	
	inserted = insert_tree(item, &actual);
	
	assert(inserted == True);
	assert(actual->left != NULL || actual->right != NULL);
	assert(!(actual->left == actual->right));
	del_tree(&actual);
}

void InsertTree_TreeWithRootAndItemInTree_ReturnFalse(void){
	TreeItem item = 5;
	Tree actual = tree(NULL, item, NULL);
	Bool inserted = False;
	
	inserted = insert_tree(item, &actual);
	
	assert( inserted == False);
	assert(actual->left == NULL);
	assert(actual->left == actual->right);
	del_tree(&actual);
}

/* - */

void BinarySearchTree_EmptyTree_ReturnFalse(void){
	Tree T = NULL;
	Bool actual;
	Bool expected = False;
	
	actual = binary_search_tree(0, T);
	
	assert(actual == expected);
}

void BinarySearchTree_TreeHasItem_ReturnTrue(void){
	TreeItem item = 0;
	Tree T = tree(NULL, item, NULL);
	Bool actual;
	Bool expected = True;
	
	actual = binary_search_tree(item, T);
	
	assert(actual == expected);
	del_tree(&T);
}

void BinarySearchTree_TreeDoesNotHaveItem_ReturnFalse(void){
	TreeItem item = 0;
	TreeItem diferentItem = item + 1;
	Tree T = tree(NULL, item, NULL);
	Bool actual;
	Bool expected = False;
	
	actual = binary_search_tree(diferentItem, T);
	
	assert(actual == expected);
	del_tree(&T);
}

/* - */

void RemoveMaxItemTree_EmptyTree_ShouldDoNothing(void){
	TreeItem item;
	Tree actual = NULL;
	Tree expected = NULL;
	
	remove_max_item_tree(&item, &actual);
	
	assert(actual == expected);
}

void RemoveMaxItemTree_TreeWithOnlyRoot_TreeShouldPointsToNull(void){
	TreeItem item = 0;
	Tree actual = tree(NULL, item, NULL);
	Tree expected = NULL;
	
	remove_max_item_tree(&item, &actual);
	
	assert(actual == expected);
}

void RemoveMaxItemTree_TreeWithLeaves_ShouldRemoveBiggestRightLeaf(void){
	TreeItem item = 5;
	Tree T = 
	tree(
		tree(NULL, item-2, NULL), 
		item, 
		tree(NULL, item+2, NULL)
		);

	/*
					5								5
			3				7		-->		3				NULL
	*/
	
	remove_max_item_tree(&item, &T);
	
	assert(T->right == NULL);
	del_tree(&T);
}

void RemoveRootTree_EmptyTree_ShouldDoNothing(void){
	Tree actual = NULL;
	Tree expected = NULL;
	
	remove_root_tree(&actual);
	
	assert(actual == expected);
}

void RemoveRootTree_TreeWithOnlyRoot_TreeShouldPointsToNull(void){
	Tree actual = tree(NULL, 0, NULL);
	Tree expected = NULL;
	
	remove_root_tree(&actual);
	
	assert(actual == expected);
}

void RemoveRootTree_TreeWithLeaves_ShouldReplaceRootItemWithTheBiggestLeftItemAndDeleteBiggestLeftLeaf(void){
	TreeItem item = 5;
	TreeItem expectedItem = item - 1;
	Tree T = 
	tree(
		tree(
			tree(NULL, item-3, NULL),
			item-2,
			tree(NULL, item-1, NULL)
			), 
		item, 
		tree(
			tree(NULL, item+1, NULL),
			item+2,
			tree(NULL, item+3, NULL)
			)
		);

	/*
					5								4
			3				7		-->		3				7
		2		4		6		8		2		NULL	6		8
	*/
	
	remove_root_tree(&T);
	
	assert(T->item = expectedItem);
	assert(T->left->right == NULL);
	del_tree(&T);
}

void RemoveFromTree_EmptyTree_ShouldDoNoting(void){
	Tree actual = NULL;
	TreeItem item = 0;
	Tree expected = NULL;
	
	remove_from_tree(item, &actual);
	
	assert(actual == expected);
}

void RemoveFromTree_TreeNotEmptyAndWithoutItem_ShouldDoNothing(void){
	TreeItem item = 5;
	TreeItem searched = item - 1;
	Tree actual = tree(tree(NULL, item-2, NULL), item, tree(NULL, item+2, NULL));
	Tree expectedRoot = actual;
	Tree expectedLeftLeaf = actual->left;
	Tree expectedRighttLeaf = actual->right;
	
	remove_from_tree(searched, &actual);
	
	assert(actual == expectedRoot);
	assert(actual->left == expectedLeftLeaf);
	assert(actual->right == expectedRighttLeaf);
	del_tree(&actual);
}

void RemoveFromTree_TreeNotEmptyAndWithItem_ShouldDeleteNodeWithItem(void){
	TreeItem item = 2;
	TreeItem searchItem = 4;
	Tree actual = tree(tree(NULL, item-2, NULL), item, tree(NULL, item+2, NULL));
	Tree expectedRoot = actual;
	Tree expectedLeftLeaf = actual->left;
	Tree expectedRighttLeaf = NULL;
	
	remove_from_tree(searchItem, &actual);
	
	assert(actual == expectedRoot);
	assert(actual->left == expectedLeftLeaf);
	assert(actual->right == expectedRighttLeaf);
	del_tree(&actual);
}

/* - */

void PruneTree_EmptyTree_ShouldDoNothing(void){
	Tree actual = NULL;
	Tree expected = NULL;
	
	prune_tree(&actual);
	
	assert(actual == expected);
}

void PruneTree_TreeWithOnlyRoot_ShouldRemoveRoot(void){
	Tree actual = tree(NULL, 0, NULL);
	Tree expected = NULL;
	
	prune_tree(&actual);
	
	assert(actual == expected);
	del_tree(&actual);
}

void PruneTree_TreeWithLeaves_ShouldRemoveTheLeaves(void){
	Tree actual = tree(tree(NULL, 1, NULL), 0, tree(NULL, 1,NULL));
	Tree expectedRightLeaf = NULL;
	Tree expectedLeftLeaf = NULL;
	
	prune_tree(&actual);
	
	assert(actual->right == expectedRightLeaf);
	assert(actual->left == expectedLeftLeaf);
	del_tree(&actual);
}

/* - */

void CountLeavesTree_EmptyTree_ReturnZero(void){
	Tree T = NULL;
	int actualLeaves;
	int expectedLeaves = 0;
	
	actualLeaves = count_leaves_tree(T);
	
	assert(actualLeaves == expectedLeaves);
}

void CountLeavesTree_TreeWithOnlyRoot_ReturnOne(void){
	Tree T = tree(NULL, 0, NULL);
	int actualLeaves;
	int expectedLeaves = 1;
	
	actualLeaves = count_leaves_tree(T);
	
	assert(actualLeaves == expectedLeaves);
	del_tree(&T);
}

void CountLeavesTree_TreeWithLeaves_ReturnTheNumberOfLeaves(void){
	Tree T = tree(tree(NULL, 1, NULL), 0, tree(NULL, 1, NULL));
	int actualLeaves;
	int expectedLeaves = 2;
	
	actualLeaves = count_leaves_tree(T);
	
	assert(actualLeaves == expectedLeaves);
	del_tree(&T);
}

/* - */

void CountNodesTree_EmptyTree_ReturnZero(void){
	Tree T = NULL;
	int actualNodesNumber;
	int expectedNodesNumber = 0;
	
	actualNodesNumber = count_nodes_tree(T);
	
	assert(actualNodesNumber == expectedNodesNumber);
}

void CountNodesTree_TreeWithOnlyRoot_ReturnOne(void){
	Tree T = tree(NULL, 0,NULL);
	int actualNodesNumber;
	int expectedNodesNumber = 1;
	
	actualNodesNumber = count_nodes_tree(T);
	
	assert(actualNodesNumber == expectedNodesNumber);
	del_tree(&T);
}

void CountNodesTree_TreeWithThreeNodes_ReturnThree(void){
	Tree T = tree(tree(NULL, 1,NULL), 0,tree(NULL, 2,NULL));
	int actualNodesNumber;
	int expectedNodesNumber = 3;
	
	actualNodesNumber = count_nodes_tree(T);
	
	assert(actualNodesNumber == expectedNodesNumber);
	del_tree(&T);
}

/* - */

void HighTree_EmptyTree_ReturnZero(void){
	Tree T = NULL;
	int actualHigh;
	int expectedHigh = 0;
	
	actualHigh = high_tree(T);
	
	assert(actualHigh == expectedHigh);
}

void HighTree_TreeWithOnlyRoot_ReturnZero(void){
	Tree T = tree(NULL, 0, NULL);
	int actualHigh;
	int expectedHigh = 0;
	
	actualHigh = high_tree(T);
	
	assert(actualHigh == expectedHigh);
	del_tree(&T);
}

void HighTree_TreeWithHighOne_ReturnOne(void){
	Tree T = tree(tree(NULL, 1, NULL), 0, tree(NULL, 1, NULL));
	int actualHigh;
	int expectedHigh = 1;
	
	actualHigh = high_tree(T);
	
	assert(actualHigh == expectedHigh);
	del_tree(&T);
}

void HighTree_IrregularTreeOfHighTwo_ReturnTwo(void){
	Tree T = 
	tree(
		tree(NULL, 1, NULL), 
		0, 
		tree(
			tree(NULL, 2, NULL), 
			1, 
			tree(NULL, 2, NULL)
		)
	);
	int actualHigh;
	int expectedHigh = 2;
	
	actualHigh = high_tree(T);
	
	assert(actualHigh == expectedHigh);
	del_tree(&T);
}

/* - */

void MirroredTree_EmptyTree_ReturnNULL(void){
	Tree actual = NULL;
	Tree expected = NULL;
	
	actual = mirrored_tree(expected);
	
	assert(actual == expected);
}

void MirroredTree_TreeWithOnlyRoot_ReturnCopyTree(void){
	Tree actual = NULL;
	Tree expected = tree(NULL, 0, NULL);
	
	actual = mirrored_tree(expected);
	
	assert(actual != NULL);
	assert(actual != expected);
	assert(actual->item == expected->item);
	assert(actual->left == NULL);
	assert(actual->right == NULL);
	del_tree(&actual);
	del_tree(&expected);
}

void MirroredTree_TreeWithLeaves_ReturnCopyTreeWithSwappedLeaves(void){
	Tree actual = NULL;
	Tree expected = tree(tree(NULL, 1, NULL), 0, tree(NULL, 2, NULL));
	
	actual = mirrored_tree(expected);
	
	assert(actual != NULL);
	assert(actual != expected);
	assert(actual->item == expected->item);
	assert(actual->left != NULL);
	assert(actual->right != NULL);
	assert(actual->left != expected->left);
	assert(actual->left != expected->right);
	assert(actual->right != expected->right);
	assert(actual->left->item == expected->right->item);
	assert(actual->right->item == expected->left->item);
	
	del_tree(&actual);
	del_tree(&expected);
}

/* - */

void CloneTree_EmptyTree_ReturnNull(void){
	Tree actual = NULL;
	Tree expected = NULL;
	
	actual = clone_tree(expected);
	
	assert(actual == expected);
}

void CloneTree_TreeWithOnlyRoot_ReturnCopyTree(void){
	Tree actual = NULL;
	Tree expected = tree(NULL, 0, NULL);
	
	actual = clone_tree(expected);
	
	assert(actual != expected);
	assert(actual != NULL);
	assert(actual->item == expected->item);
	
	del_tree(&actual);
	del_tree(&expected);
}

void CloneTree_TreeWithLeaves_ReturnCopyTree(void){
	Tree actual = NULL;
	Tree expected = tree(tree(NULL, 1, NULL), 0, tree(NULL, 2, NULL));
	
	actual = clone_tree(expected);
	
	assert(actual != expected);
	assert(actual != NULL);
	assert(actual->item == expected->item);
	
	assert(actual->left != expected->left);
	assert(actual->left != NULL);
	assert(actual->left->item == expected->left->item);
	
	assert(actual->right != expected->right);
	assert(actual->right != NULL);
	assert(actual->right->item == expected->right->item);
	del_tree(&actual);
	del_tree(&expected);
}

/* - */

void HasItemInTree_EmptyTree_ReturnFalse(void){
	Tree T = NULL;
	TreeItem x;
	Bool actual;
	Bool expected = False;
	
	actual = has_item_in_tree(x, T);
	
	assert(actual == expected);
}

void HasItemInTree_TreeWithItem_ReturnTrue(void){
	TreeItem x = 0;
	Tree T = tree(NULL, x, NULL);
	Bool actual;
	Bool expected = True;
	
	actual = has_item_in_tree(x, T);
	
	assert(actual == expected);
	del_tree(&T);
}

void HasItemInTree_TreeWithoutItem_ReturnFalse(void){
	TreeItem x = 0;
	Tree T = tree(NULL, x, NULL);
	Bool actual;
	Bool expected = False;
	
	actual = has_item_in_tree(x+1, T);
	
	assert(actual == expected);
	del_tree(&T);
}

/* - */

void DelTree_NotNullTree_TreePointsToNull(void){
	Tree actual = tree(NULL, 0, NULL);
	
	del_tree(&actual);
	
	assert(actual == NULL);
}

void DelTree_NullTree_TreePointsToNull(void){
	Tree actual = NULL;
	
	del_tree(&actual);
	
	assert(actual == NULL);
}
