#include "tests_dictionary.h"

#define DICT_SIZE_NEGATIVE -1
#define DICT_SIZE_ZERO 0
#define DICT_SIZE_POSITIVE 1 
#define KEY_SIZE_NEGATIVE -1
#define KEY_SIZE_ZERO 0
#define KEY_SIZE_POSITIVE 1 

void Dictionary_TestAll(void){
	int width = 70;
	test_header("Testing Dictionary methods\n", width);
	test("Dict_SizeIsNegativeValue_ReturnsNull", 
		  Dict_SizeIsNegativeValue_ReturnsNull, width);
	test("Dict_SizeIsZero_ReturnsNull", 
		  Dict_SizeIsZero_ReturnsNull, width);
	test("Dict_SizeIsPositiveValue_ReturnsDictionary", 
		  Dict_SizeIsPositiveValue_ReturnsDictionary, width);
	
	test("DelDict_DictIsNUll_ShouldDoNothing", 
		  DelDict_DictIsNUll_ShouldDoNothing, width);
	test("DelDict_DictIsNotNull_ShouldFreeAllStructures", 
		  DelDict_DictIsNotNull_ShouldFreeAllStructures, width);
	
	test("Hash_NegativeValues_ReturnsZero", 
		  Hash_NegativeValues_ReturnsZero, width);
	test("Hash_KeyIsPositiveAndSizeIsZero_ReturnsReturnsZero", 
		  Hash_KeyIsPositiveAndSizeIsZero_ReturnsReturnsZero, width);
	test("Hash_KeyAndSizeArePositiveNotZeroValues_ReturnsRemainderOfTheKeyByTheSize", 
		  Hash_KeyAndSizeArePositiveNotZeroValues_ReturnsRemainderOfTheKeyByTheSize, width);
	
	test("InsertToDict_DictIsNull_ReturnsFalse", 
		  InsertToDict_DictIsNull_ReturnsFalse, width);
	test("InsertToDict_DictIsEmpty_ReturnsTrue", 
		  InsertToDict_DictIsEmpty_ReturnsTrue, width);
	test("InsertToDict_DictKeyIsInDictAndDictValueIsDifferent_ReturnsTrueAndShouldReplaceDictValue", 
		  InsertToDict_DictKeyIsInDictAndDictValueIsDifferent_ReturnsTrueAndShouldReplaceDictValue, width);
	
	
	test("RemoveFromDict_DictIsNull_ShouldChangeNothing", 
		  RemoveFromDict_DictIsNull_ShouldChangeNothing, width);
	test("RemoveFromDict_DictIsEmpty_ShouldChangeNothing", 
		  RemoveFromDict_DictIsEmpty_ShouldChangeNothing, width);
	test("RemoveFromDict_DictKeyIsInDict_ShouldRemoveTheKey", 
		  RemoveFromDict_DictKeyIsInDict_ShouldRemoveTheKey, width);
	test("RemoveFromDict_DictKeyIsNotInDict_ShouldChangeNothing", 
		  RemoveFromDict_DictKeyIsNotInDict_ShouldChangeNothing, width);
	
	test("DictHasKey_DictIsNUll_ReturnsFalse", 
		  DictHasKey_DictIsNUll_ReturnsFalse, width);
	test("DictHasKey_DictKeyIsInDict_ReturnsTrue", 
	 	  DictHasKey_DictKeyIsInDict_ReturnsTrue, width);
	test("DictHasKey_DictKeyIsNotInDict_ReturnsFalse", 
		  DictHasKey_DictKeyIsNotInDict_ReturnsFalse, width);
	// test("", , width);
}

void Dict_SizeIsNegativeValue_ReturnsNull(void){
	Dictionary actual;
	Dictionary expected = NULL;
	
	actual = dict(DICT_SIZE_NEGATIVE);
	
	assert(actual == expected);
}

void Dict_SizeIsZero_ReturnsNull(void){
	Dictionary actual;
	Dictionary expected = NULL;
	
	actual = dict(DICT_SIZE_ZERO);
	
	assert(actual == expected);
}

void Dict_SizeIsPositiveValue_ReturnsDictionary(void){
	Dictionary actual = NULL;
	
	actual = dict(DICT_SIZE_POSITIVE);
	
	assert(actual != NULL);
	del_dict(&actual);
}

void DelDict_DictIsNUll_ShouldDoNothing (void){
	Dictionary actual = NULL;
	Dictionary expected = NULL;
	
	del_dict(&actual);
	
	assert(actual == expected);
}

void DelDict_DictIsNotNull_ShouldFreeAllStructures (void){
	Dictionary actual = dict(DICT_SIZE_POSITIVE);
	Dictionary expected = NULL;
	
	del_dict(&actual);
	
	assert(actual == expected);
}

void Hash_NegativeValues_ReturnsZero(void){
	unsigned actual;
	unsigned expected = 0;
	
	actual = hash(KEY_SIZE_NEGATIVE, DICT_SIZE_NEGATIVE);

	assert(actual == expected);
}

void Hash_KeyIsPositiveAndSizeIsZero_ReturnsReturnsZero(void){
	unsigned actual;
	unsigned expected = 0;
	
	actual = hash(KEY_SIZE_ZERO, DICT_SIZE_ZERO);
	
	assert(actual == expected);
}

void Hash_KeyAndSizeArePositiveNotZeroValues_ReturnsRemainderOfTheKeyByTheSize(void){
	unsigned actual;
	unsigned expected = 0;
	
	actual = hash(KEY_SIZE_POSITIVE, DICT_SIZE_POSITIVE);

	assert(actual == expected);
}

void InsertToDict_DictIsNull_ReturnsFalse(void){
	Dictionary actualDict = NULL;
	Bool actualOperationResult;
	Bool expectedOperationResult = False;
	DictKey key = 0;
	DictValue value = "abc";
	
	actualOperationResult = insert_to_dict(key, value, actualDict);
	
	assert(actualOperationResult == expectedOperationResult);
}

void InsertToDict_DictIsEmpty_ReturnsTrue(void){
	Dictionary actualDict = dict(DICT_SIZE_POSITIVE);
	Bool actualOperationResult;
	Bool expectedOperationResult = True;
	DictKey key = 0;
	DictValue value = "abc";
	
	actualOperationResult = insert_to_dict(key, value, actualDict);
	
	assert(actualOperationResult == expectedOperationResult);
	assert(actualDict->array[0]->key == key);
	assert(strcmp(actualDict->array[0]->value, value) == 0);
	del_dict(&actualDict);
}

void InsertToDict_DictKeyIsInDictAndDictValueIsDifferent_ReturnsTrueAndShouldReplaceDictValue(void){
	Dictionary actualDict = dict(DICT_SIZE_POSITIVE);
	Bool actualOperationResult;
	Bool expectedOperationResult = True;
	DictKey key = 0;
	DictValue originalValue = "abc";
	DictValue finalValue = "def";
	insert_to_dict(key, originalValue, actualDict);
	
	actualOperationResult = insert_to_dict(key, finalValue, actualDict);
	
	assert(actualOperationResult == expectedOperationResult);
	assert(actualDict->array[0]->key == key);
	assert(strcmp(actualDict->array[0]->value, finalValue) == 0);
	del_dict(&actualDict);
}

void RemoveFromDict_DictIsNull_ShouldChangeNothing(void){
	Dictionary actual = NULL;
	Dictionary expected = NULL;
	
	remove_from_dict(0, actual);
	
	assert(actual == expected);
}

void RemoveFromDict_DictIsEmpty_ShouldChangeNothing(void){
	Dictionary actual = dict(DICT_SIZE_POSITIVE);
	
	remove_from_dict(0, actual);
	
	assert(actual->array[0] == NULL);
	del_dict(&actual);
}

void RemoveFromDict_DictKeyIsInDict_ShouldRemoveTheKey(void){
	Dictionary actual = dict(DICT_SIZE_POSITIVE);
	DictKey key = 0;
	DictValue value = "abc";
	insert_to_dict(key, value, actual);
	
	remove_from_dict(key, actual);
	
	assert(actual->array[0] == NULL);
	del_dict(&actual);
}

void RemoveFromDict_DictKeyIsNotInDict_ShouldChangeNothing(void){
	Dictionary actual = dict(DICT_SIZE_POSITIVE);
	DictKey key = 0;
	DictValue value = "abc";
	insert_to_dict(key, value, actual);
	
	remove_from_dict(key+1, actual);
	
	assert(actual->array[0] != NULL);
	assert(actual->array[0]->key == key);
	assert(strcmp(actual->array[0]->value, value) == 0);
	del_dict(&actual);
}

void DictHasKey_DictIsNUll_ReturnsFalse (void){
	Dictionary D = NULL;
	Bool actual;
	Bool expected = False;
	
	actual = dict_has_key(0, D);
	
	assert(actual == expected);
}

void DictHasKey_DictKeyIsInDict_ReturnsTrue (void){
	Dictionary D = dict(DICT_SIZE_POSITIVE);
	DictKey key = 0;
	DictValue value = "abc";
	insert_to_dict(key, value, D);
	Bool actual;
	Bool expected = True;
	
	actual = dict_has_key(key, D);
	
	assert(actual == expected);
	del_dict(&D);
}

void DictHasKey_DictKeyIsNotInDict_ReturnsFalse (void){
	Dictionary D = dict(DICT_SIZE_POSITIVE);
	DictKey key = 0;
	DictValue value = "abc";
	insert_to_dict(key, value, D);
	Bool actual;
	Bool expected = False;
	
	actual = dict_has_key(key+1, D);
	
	assert(actual == expected);
	del_dict(&D);
}
#undef DICT_SIZE_NEGATIVE
#undef DICT_SIZE_ZERO
#undef DICT_SIZE_POSITIVE
#undef KEY_SIZE_NEGATIVE
#undef KEY_SIZE_ZERO
#undef KEY_SIZE_POSITIVE

