#pragma once

#include "ast.h"

#define AST_CREATE_DEBUG

#ifdef AST_CREATE_DEBUG
extern int yylineno;

void printline(AST* n) {
	printf("( %s ", n->type);
	if(n->str) printf("%s %d %d ", n->str->c_str(), n->line, n->col);
	if(n->left) { printline(n->left); putchar(' '); }
	if(n->right) { printline(n->right); putchar(' '); }
	printf(")");
}

void print(AST* n, int tabcount) {
	printf("%*c\"%s\"\n", 2 * (tabcount + 1), ' ', n->type);
	if(n->str) {
		printf("%*c\"%s\" %d %d\n", 2 * (tabcount + 1) + 2, ' ', n->str->c_str(), n->line, n->col);
	}
	if(n->left) {
		printf("%*c[LEFT]\n", 2 * (tabcount + 1) + 2, ' ');
		print(n->left, tabcount + 2);
	}
	if(n->right) {
		printf("%*c[RIGHT]\n", 2 * (tabcount + 1) + 2, ' ');
		print(n->right, tabcount + 2);
	}
}
#endif


AST::AST(const char* type, const std::string& str, int line, int col) :
	type(type), str(new std::string(str)), left(NULL), right(NULL), line(line), col(col) {}
AST::AST(const char* type, AST* left, AST* right) :
	type(type), str(NULL), left(left), right(right), line(-1), col(-1) {}

AST::~AST() {
	delete str;
	delete left;
	delete right;
}

AST* makenode(const char* type, const std::string& str, int line, int col) {
	AST* n = new AST(type, str, line, col);
#ifdef AST_CREATE_DEBUG
	printf("%3d ", yylineno);
	printline(n);
	putchar('\n');
#endif
	return n;
}

AST* makenode(const char* type, AST* left, AST* right) {
	AST* n = new AST(type, left, right);
#ifdef AST_CREATE_DEBUG
	printf("%3d ", yylineno);
	printline(n);
	putchar('\n');
#endif
	return n;
}


