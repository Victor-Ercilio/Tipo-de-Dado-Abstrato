#ifndef TESTS_DICTIONARY_H
#define TESTS_DICTIONARY_H

#include "tests_utils.h"
#include "dictionary.h"

void Dictionary_TestAll(void);

void Dict_SizeIsNegativeValue_ReturnsNull(void);

void Dict_SizeIsZero_ReturnsNull(void);

void Dict_SizeIsPositiveValue_ReturnsDictionary(void);

void Hash_TwoNotZeroPositiveValues_ReturnsRemainderOfTheFirstByTheSecond(void);

void InsertToDict_DictIsNull_ReturnsFalse(void);

void InsertToDict_DictIsEmpty_ReturnsTrue(void);

void InsertToDict_DictKeyIsNotInDict_ReturnsTrue(void);

void InsertToDict_DictKeyIsInDictAndDictValueIsDifferent_ReturnsTrueAndShouldReplaceDictValue(void);

void InsertToDict_DictKeyIsInDictAndDictValueNotChange_ReturnsFalse(void);

void RemoveFromDict_DictIsNull_ShouldChangeNothing(void);

void RemoveFromDict_DictIsEmpty_ShouldChangeNothing(void);

void RemoveFromDict_DictKeyIsInDict_ShouldRemoveTheKey(void);

void RemoveFromDict_DictKeyIsNotInDict_ShouldChangeNothing(void);

void DictHasKey_DictIsNUll_ReturnsFalse (void);

void DictHasKey_DictKeyIsInDict_ReturnsTrue (void);

void DictHasKey_DictKeyIsNotInDict_ReturnsFalse (void);

void DelDict_DictIsNUll_ShouldDoNothing (void);

void DelDict_DictIsNotNull_ShouldFreeAllStructures (void);
#endif
