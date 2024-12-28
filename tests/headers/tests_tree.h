#ifndef TESTS_TREE_H
#define TESTS_TREE_H

#include "tests_utils.h"
#include "tree.h"

void Tree_TestAll(void);

void Tree_NullLeaves_ReturnTree(void);

void Tree_NotNullLeaves_ReturnTreeWithLeaves(void);

void FullTreeOf_SizeZero_ReturnNull(void);

void FullTreeOf_SizeOne_ReturnTreeWithRoot(void);

void FullTreeOf_SizeTwo_ReturnTreeWithDeepthOfTwo(void);

void InsertTree_NullTree_ReturnTrue(void);

void InsertTree_TreeWithRootAndItemNotInTree_ReturnTrue(void);

void InsertTree_TreeWithRootAndItemInTree_ReturnFalse(void);

void BinarySearchTree_EmptyTree_ReturnFalse(void);

void BinarySearchTree_TreeHasItem_ReturnTrue(void);

void BinarySearchTree_TreeDoesNotHaveItem_ReturnFalse(void);

void RemoveMaxItemTree_EmptyTree_ShouldDoNothing(void);

void RemoveMaxItemTree_TreeWithOnlyRoot_TreeShouldPointsToNull(void);

void RemoveMaxItemTree_TreeWithLeaves_ShouldRemoveBiggestRightLeaf(void);

void RemoveRootTree_EmptyTree_ShouldDoNothing(void);

void RemoveRootTree_TreeWithOnlyRoot_TreeShouldPointsToNull(void);

void RemoveRootTree_TreeWithLeaves_ShouldReplaceRootItemWithTheBiggestLeftItemAndDeleteBiggestLeftLeaf(void);

void RemoveFromTree_EmptyTree_ShouldDoNoting(void);

void RemoveFromTree_TreeNotEmptyAndWithoutItem_ShouldDoNothing(void);

void RemoveFromTree_TreeNotEmptyAndWithItem_ShouldDeleteNodeWithItem(void);

void PruneTree_EmptyTree_ShouldDoNothing(void);

void PruneTree_TreeWithOnlyRoot_ShouldRemoveRoot(void);

void PruneTree_TreeWithLeaves_ShouldRemoveTheLeaves(void);

void CountLeavesTree_EmptyTree_ReturnZero(void);

void CountLeavesTree_TreeWithOnlyRoot_ReturnOne(void);

void CountLeavesTree_TreeWithLeaves_ReturnTheNumberOfLeaves(void);

void CountNodesTree_EmptyTree_ReturnZero(void);

void CountNodesTree_TreeWithOnlyRoot_ReturnOne(void);

void CountNodesTree_TreeWithThreeNodes_ReturnThree(void);

void HighTree_EmptyTree_ReturnZero(void);

void HighTree_TreeWithOnlyRoot_ReturnZero(void);

void HighTree_TreeWithHighOne_ReturnOne(void);

void HighTree_IrregularTreeOfHighTwo_ReturnTwo(void);

void MirroredTree_EmptyTree_ReturnNULL(void);

void MirroredTree_TreeWithOnlyRoot_ReturnCopyTree(void);

void MirroredTree_TreeWithLeaves_ReturnCopyTreeWithSwappedLeaves(void);

void CloneTree_EmptyTree_ReturnNull(void);

void CloneTree_TreeWithOnlyRoot_ReturnCopyTree(void);

void CloneTree_TreeWithLeaves_ReturnCopyTree(void);

void HasItemInTree_EmptyTree_ReturnFalse(void);

void HasItemInTree_TreeWithItem_ReturnTrue(void);

void HasItemInTree_TreeWithoutItem_ReturnFalse(void);

void DelTree_NotNullTree_TreePointsToNull(void);

void DelTree_NullTree_TreePointsToNull(void);

#endif
