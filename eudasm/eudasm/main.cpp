#include <stdio.h>
extern FILE* yyin;
int yyparse(void);

int main(int argc, char *argv[]) 
{
	// Simple intro message
	printf(
		"eudc v0.01. Simple compiler for trigger programming.\n"
		"Created by trgk(phu54231@naver.com). Bug report welcomed.\n"
		"============================================================\n");

	freopen("out.txt", "w", stdout);

	if(argc == 1) {
		printf("Usage : eudc [input file]\n");
	}

	FILE* fp = fopen(argv[1], "r");

	yyin = fp;

	yyparse();

	fclose(fp);
	getchar();
	fflush(stdout);
	return 0;
}