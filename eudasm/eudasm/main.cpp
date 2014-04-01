#include <stdio.h>
#include <stdlib.h>


extern FILE* yyin;

int yyparse (void);

int main() {
	yyin = fopen("test.txt", "r");
	yyparse();
	fclose(yyin);
	system("pause");
	return 0;
}