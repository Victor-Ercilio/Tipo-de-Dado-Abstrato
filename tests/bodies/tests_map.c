#include "tests_map.h"

void Map_TestAll(void){
	int width = 73;
	test_header("Testing Map Methods", width);
	test("NodeMap_NextIsNull_ReturnsMapWithOneNode", NodeMap_NextIsNull_ReturnsMapWithOneNode, width);
	test("NodeMap_NextIsOtherMap_ReturnsMapWithOtherMapAppendedToNode", NodeMap_NextIsOtherMap_ReturnsMapWithOtherMapAppendedToNode, width);
	
	test("InsertMap_MapIsNull_ShouldCreateNode", InsertMap_MapIsNull_ShouldCreateNode, width);
	test("InsertMap_KeyIsNotInMapAndMapIsNotNull_SholdInsertNodeInRightOrder", InsertMap_KeyIsNotInMapAndMapIsNotNull_SholdInsertNodeInRightOrder, width);
	test("InsertMap_KeyIsInMapAndValueNotChangeAndMapIsNotNull_ShouldChangeNothing", InsertMap_KeyIsInMapAndValueNotChangeAndMapIsNotNull_ShouldChangeNothing, width);
	test("InsertMap_KeyIsInMapAndValueChangedAndMapIsNotNull_ShouldUpdatedNodeValue", InsertMap_KeyIsInMapAndValueChangedAndMapIsNotNull_ShouldUpdatedNodeValue, width);
	
	test("RemoveFromMap_MapIsNull_ShouldDoNothing", RemoveFromMap_MapIsNull_ShouldDoNothing, width);
	test("RemoveFromMap_MapIsNotNullAndKeyIsNotInMap_ShouldDoNothing", RemoveFromMap_MapIsNotNullAndKeyIsNotInMap_ShouldDoNothing, width);
	test("RemoveFromMap_MapIsNotNullAndKeyIsInMap_ShouldRemoveNode", RemoveFromMap_MapIsNotNullAndKeyIsInMap_ShouldRemoveNode, width);
	
	test("HasKeyMap_MapIsNull_ReturnsFalse", HasKeyMap_MapIsNull_ReturnsFalse, width);
	test("HasKeyMap_MapIsNotNullAndKeyIsNotInMap_ReturnsFalse", HasKeyMap_MapIsNotNullAndKeyIsNotInMap_ReturnsFalse, width);
	test("HasKeyMap_MapIsNullAndKeyIsInMap_ReturnsTrue", HasKeyMap_MapIsNullAndKeyIsInMap_ReturnsTrue, width);
	
	test("DelMap_MapIsNull_ShoudlDoNothing", DelMap_MapIsNull_ShoudlDoNothing, width);
	test("DelMap_MapIsNotNull_ShoudlDeleteAllNodesAndMakeMapPointsToNull", DelMap_MapIsNotNull_ShoudlDeleteAllNodesAndMakeMapPointsToNull, width);
	// Template: test("", , width);
}

void NodeMap_NextIsNull_ReturnsMapWithOneNode(void){
	Map actual = NULL;
	
	actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	
	assert(actual != NULL);
	assert(actual->next == NULL);
	del_map(&actual);
}

void NodeMap_NextIsOtherMap_ReturnsMapWithOtherMapAppendedToNode(void){
	Map actual = NULL;
	
	actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, node_map(VALID_MAP_KEY+1, VALID_MAP_VALUE, NULL));
	
	assert(actual != NULL);
	assert(actual->next != NULL);
	del_map(&actual);
}

void InsertMap_MapIsNull_ShouldCreateNode(void){
	Map actual = NULL;
	
	insert_map(VALID_MAP_KEY, VALID_MAP_VALUE, &actual);
	
	assert(actual != NULL);
	del_map(&actual);
}

void InsertMap_KeyIsNotInMapAndMapIsNotNull_SholdInsertNodeInRightOrder(void){
	Map actual = node_map((VALID_MAP_KEY+1), VALID_MAP_VALUE, NULL);
	Map expectedSecondNode = actual;
	
	insert_map(VALID_MAP_KEY, VALID_MAP_VALUE, &actual);
	
	assert(actual != NULL);
	assert(actual->next == expectedSecondNode);
	assert(actual->key == VALID_MAP_KEY);
	del_map(&actual);
}

void InsertMap_KeyIsInMapAndValueNotChangeAndMapIsNotNull_ShouldChangeNothing(void){
	Map actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	Map expected = actual;
	Map expectedSecondNode = NULL;
	
	insert_map(VALID_MAP_KEY, VALID_MAP_VALUE, &actual);
	
	assert(actual == expected);
	assert(actual->next == expectedSecondNode);
	assert(actual->key == VALID_MAP_KEY);
	del_map(&actual);
}

void InsertMap_KeyIsInMapAndValueChangedAndMapIsNotNull_ShouldUpdatedNodeValue(void){
	Map actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	Map expected = actual;
	Map expectedSecondNode = NULL;
	
	insert_map(VALID_MAP_KEY, VALID_DIFF_VALUE, &actual);
	
	assert(actual == expected);
	assert(actual->next == expectedSecondNode);
	assert(strcmp(actual->value, VALID_DIFF_VALUE) == 0);
	del_map(&actual);
}

void RemoveFromMap_MapIsNull_ShouldDoNothing(void){
	Map actual = NULL;
	
	remove_from_map(VALID_MAP_KEY, &actual);
	
	assert(actual == NULL);
}

void RemoveFromMap_MapIsNotNullAndKeyIsNotInMap_ShouldDoNothing(void){
	Map actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	Map expected = actual;
	
	remove_from_map(VALID_DIFF_MAP_KEY, &actual);

	assert(actual == expected);
	assert(actual->key == VALID_MAP_KEY);
	del_map(&actual);
}

void RemoveFromMap_MapIsNotNullAndKeyIsInMap_ShouldRemoveNode(void){
	Map actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	Map expected = NULL;
	
	remove_from_map(VALID_MAP_KEY, &actual);

	assert(actual == expected);
}

void HasKeyMap_MapIsNull_ReturnsFalse(void){
	Map map = NULL;
	MapValue value;
	Bool actual;
	Bool expected = False;
	
	actual = has_key_map(VALID_MAP_KEY, value, map);
	
	assert(actual == expected);
}

void HasKeyMap_MapIsNotNullAndKeyIsNotInMap_ReturnsFalse(void){
	Map map = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	MapValue value;
	Bool actual;
	Bool expected = False;
	
	actual = has_key_map(VALID_DIFF_MAP_KEY, value, map);
	
	assert(actual == expected);
	del_map(&map);
}

void HasKeyMap_MapIsNullAndKeyIsInMap_ReturnsTrue(void){
	Map map = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	MapValue value;
	Bool actual;
	Bool expected = True;
	
	actual = has_key_map(VALID_MAP_KEY, value, map);
	
	assert(actual == expected);
	assert(strcmp(map->value,value) == 0);
	del_map(&map);
}

void DelMap_MapIsNull_ShoudlDoNothing(void){
	Map actual = NULL;
	Map expected = NULL;
	
	del_map(&actual);
	
	assert(actual == expected);
}

void DelMap_MapIsNotNull_ShoudlDeleteAllNodesAndMakeMapPointsToNull(void){
	Map actual = node_map(VALID_MAP_KEY, VALID_MAP_VALUE, NULL);
	Map expected = NULL;
	
	del_map(&actual);
	
	assert(actual == expected);
}

#undef VALID_MAP_KEY
#undef VALID_DIFF_MAP_KEY
#undef VALID_MAP_VALUE
#undef VALID_DIFF_VALUE
