#include "tests_utils.h"

void test_header(TestTitle title, TestTitleWidth width){
	printf("\n%*s\n\n", width, title);
}

void test(TestTitle title, TestFunc function, TestTitleWidth width){
	printf("%*s: ", width, title);
	(*function)();
	
	/* Como se pressup�e que as fun��es de teste */
	/* utilizem a fun��o assert(), caso o teste falhe */
	/* o printf n�o ser� exibido */
	printf(" OK \n");
}
