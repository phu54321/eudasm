#include <stdio.h>
#include "ast.h"

extern FILE* yyin;
int yyparse(void);

AST* mainast;

int main(int argc, char *argv[]) 
{
	// Simple intro message
	printf(
		"eudc v0.01. Simple compiler for trigger programming.\n"
		"Created by trgk(phu54231@naver.com). Bug report welcomed.\n"
		"============================================================\n");

	if(argc == 1) {
		printf("Usage : eudc [input file]\n");
	}

	freopen("out.txt", "w", stdout);

	FILE* fp = fopen(argv[1], "r");

	yyin = fp;

	yyparse();

	fclose(fp);
	fflush(stdout);
	return 0;
}