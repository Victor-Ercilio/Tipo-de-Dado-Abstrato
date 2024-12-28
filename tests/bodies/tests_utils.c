#include "tests_utils.h"

void test_header(TestTitle title, TestTitleWidth width){
	printf("\n%*s\n\n", width, title);
}

void test(TestTitle title, TestFunc function, TestTitleWidth width){
	printf("%*s: ", width, title);
	(*function)();
	
	/* Como se pressupõe que as funções de teste */
	/* utilizem a função assert(), caso o teste falhe */
	/* o printf não será exibido */
	printf(" OK \n");
}
