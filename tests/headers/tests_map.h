#ifndef TESTS_MAP_H
#define TESTS_MAP_H

#include "tests_utils.h"
#include "map.h"

#define VALID_MAP_KEY 0
#define VALID_DIFF_MAP_KEY 1
#define VALID_MAP_VALUE "ok"
#define VALID_DIFF_VALUE "ko"

void Map_TestAll(void);

void NodeMap_NextIsNull_ReturnsMapWithOneNode(void);

void NodeMap_NextIsOtherMap_ReturnsMapWithOtherMapAppendedToNode(void);

void InsertMap_MapIsNull_ShouldCreateNode(void);

void InsertMap_KeyIsNotInMapAndMapIsNotNull_SholdInsertNodeInRightOrder(void);

void InsertMap_KeyIsInMapAndValueNotChangeAndMapIsNotNull_ShouldChangeNothing(void);

void InsertMap_KeyIsInMapAndValueChangedAndMapIsNotNull_ShouldUpdatedNodeValue(void);

void RemoveFromMap_MapIsNull_ShouldDoNothing(void);

void RemoveFromMap_MapIsNotNullAndKeyIsNotInMap_ShouldDoNothing(void);

void RemoveFromMap_MapIsNotNullAndKeyIsInMap_ShouldRemoveNode(void);

void HasKeyMap_MapIsNull_ReturnsFalse(void);

void HasKeyMap_MapIsNotNullAndKeyIsNotInMap_ReturnsFalse(void);

void HasKeyMap_MapIsNullAndKeyIsInMap_ReturnsTrue(void);

void DelMap_MapIsNull_ShoudlDoNothing(void);

void DelMap_MapIsNotNull_ShoudlDeleteAllNodesAndMakeMapPointsToNull(void);


#endif

