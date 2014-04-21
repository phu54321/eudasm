#pragma once

#include "ast.h"

extern int yylineno;

void printline(node n) {
	printf("( %s ", n->type);
	if(n->str) printf("%s ", n->str->c_str());
	if(n->left) { printline(n->left); putchar(' '); }
	if(n->right) { printline(n->right); putchar(' '); }
	printf(")");
}

void print(node n, int tabcount) {
	printf("%*c\"%s\"\n", 2 * (tabcount + 1), ' ', n->type);
	if(n->str) {
		printf("%*c\"%s\"\n", 2 * (tabcount + 1) + 2, ' ', n->str->c_str());
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


nodeimpl::nodeimpl(const char* type, const std::string& str) :
	type(type), str(new std::string(str)), left(NULL), right(NULL) {}
nodeimpl::nodeimpl(const char* type, node left, node right) :
	type(type), str(NULL), left(left), right(right) {}

nodeimpl::~nodeimpl() {
	delete str;
	delete left;
	delete right;
}

node makenode(const char* type, const std::string& str) {
	node n = node(new nodeimpl(type, str));
	printf("%3d ", yylineno);
	printline(n);
	putchar('\n');
	return n;
}

node makenode(const char* type, node left, node right) {
	node n = node(new nodeimpl(type, left, right));
	printf("%3d ", yylineno);
	printline(n);
	putchar('\n');
	return n;
}


void CompileAST(node ast) {
	printf("Final output:\n");
	print(ast, 0);
}