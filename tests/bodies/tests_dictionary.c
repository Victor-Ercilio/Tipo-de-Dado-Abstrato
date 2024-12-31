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

#undef DICT_SIZE_NEGATIVE
#undef DICT_SIZE_ZERO
#undef DICT_SIZE_POSITIVE
#undef KEY_SIZE_NEGATIVE
#undef KEY_SIZE_ZERO
#undef KEY_SIZE_POSITIVE

