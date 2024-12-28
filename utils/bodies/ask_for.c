#include "ask_for.h"	

Bool ask_for_int(PtrCharConstData var_name, PtrInt num){
	Bool op_result = False;
	
	printf("%s ", var_name);
	op_result = scanf("%d", num);
	fflush(stdin);
	
	return (op_result != EOF && op_result != False);
}

Bool ask_for_int_between(PtrCharConstData var_name, int min, int max, PtrInt num){
	Bool op_result = False;
	int value;
	
	do{
		printf("(%d >= int >= %d)", max, min);
		op_result = ask_for_int(var_name, &value);
	}while( op_result == False || value < min || value > max);
	
	*num = value;
	return op_result;
}

Bool ask_for_double(PtrCharFrozen var_name, double* num){
	Bool op_result = False;
	
	printf("%s ", var_name);
	op_result = scanf("%lf", &num);
	fflush(stdin);
	
	return (op_result != EOF && op_result != False);
}
