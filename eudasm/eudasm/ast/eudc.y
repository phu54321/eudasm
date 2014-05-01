%{
#include <stdio.h>
#include "parsertype.h"

void yyerror(char *);
int yylex(void);
extern int yylineno;

extern AST* mainast;
%}

%token <name> NAME 
%token <num> INTEGER
%token <string> STRING

%token LE GE EQ NE AND OR ADDMOV SUBMOV
%token FDEF FDECL VDEF VAR ARRAY
%token FOR WHILE IF ELSE CONTINUE BREAK
%token RETURN YIELD

%right '=' ADDMOV SUBMOV
%left OR
%left AND
%left '<' LE '>' GE EQ NE
%left '+' '-'
%left MONIC
%left ARRSUBSCRIPT FUNCTIONCALL

%start program

%destructor { delete $$; }

%%

program
	: block	{
		mainast = ast;
	}

block_list
	: block_list block
	: /* NULL */
	;

block
	: fdecl_statement	{ $$ = $1; }
	| fdef_statement	{ $$ = $1; }
	| vdef_statement	{ $$ = $1; }
	;

statement
	: vdef_statement	{ $$ = $1; }
	| if_statement	{ $$ = $1; }
	| for_statement	{ $$ = $1; }
	| while_statement	{ $$ = $1; }
	| continue_statement	{ $$ = $1; }
	| break_statement	{ $$ = $1; }
	| yield_statement	{ $$ = $1; }
	| return_statement	{ $$ = $1; }
	| expr_statement	{ $$ = $1; }
	| blank_statement	{ $$ = $1; }
	| '{' statement_list '}' { $$ = $2; }
	;

statement_list
	: statement_list statement { $$ = makenode("statement_list", $1, $2); }
	| statement	{ $$ = $1; }


	// expression
	// expr
	/*
		Prec	Op        Desc
		1		()	     Function call
				[]       Array subscription.
		2		++   --  Increment / Decrement operator
		3		+    -	 Unary plus and minus
				!        Logical NOT
		4		+    -	 Addition and subtraction
		5		<    <=	 For relational operators < and ¡Â respectively
				>    >=	 For relational operators > and ¡Ã respectively
				==   !=	 For relational = and ¡Á respectively
		6		&&	     Logical AND
				||	     Logical OR
		7		=	     Direct assignment
				+=   -=  Complex assignment
	*/

<string> stringlist
	: stringlist STRING	{ $$ = makenode("stringlist", $1, $2); }
	| STRING	{ $$ = $1; }
	;

<name> exprlist
	: NAME	{ $$ = $1; }
	| INTEGER	{ $$ = $1; }
	| stringlist	{ $$ = $1; }

	| exprlist ',' exprlist     %prec CONCAT	{ $$ = makenode(",", $1, $3); }

	| exprlist '[' exprlist ']' %prec ARRSUBSCRIPT	{ $$ = makenode("[]", $1, $3); }
	| exprlist '(' exprlist ')' %prec FUNCTIONCALL	{ $$ = makenode("()", $1, $3); }

	| '+' exprlist %prec MONIC	{ $$ = makenode("+", $2, NULL); }
	| '-' exprlist %prec MONIC	{ $$ = makenode("-", $2, NULL); }
	| '!' exprlist %prec MONIC	{ $$ = makenode("!", $2, NULL); }

	| INCR exprlist	{ $$ = makenode("++", $2, NULL); }
	| DECR exprlist	{ $$ = makenode("--", $2, NULL); }
	| exprlist INCR	{ $$ = makenode("++", $1, NULL); }
	| exprlist DECR	{ $$ = makenode("--", $1, NULL); }


	| exprlist '+' exprlist	{ $$ = makenode("+", $1, $3); }
	| exprlist '-' exprlist	{ $$ = makenode("-", $1, $3); }

	| exprlist '<' exprlist	{ $$ = makenode("<", $1, $3); }
	| exprlist LE exprlist	{ $$ = makenode("<=", $1, $3); }
	| exprlist '>' exprlist	{ $$ = makenode(">", $1, $3); }
	| exprlist GE exprlist	{ $$ = makenode(">=", $1, $3); }
	| exprlist EQ exprlist	{ $$ = makenode("==", $1, $3); }
	| exprlist NE exprlist	{ $$ = makenode("!=", $1, $3); }

	| exprlist AND exprlist	{ $$ = makenode("and", $1, $3); }

	| exprlist OR exprlist	{ $$ = makenode("or", $1, $3); }

	| exprlist '=' exprlist	{ $$ = makenode("=", $1, $3); }
	| exprlist ADDMOV exprlist	{ $$ = makenode("+=", $1, $3); }
	| exprlist SUBMOV exprlist	{ $$ = makenode("-=", $1, $3); }
	;


	// code structure.
fdecl_statement
	: FDECL NAME '(' fdecl_varlist ')' ';'	{
		AST* fbody = makenode("fbody", $4, NULL);
		$$ = makenode("fdecl_statement", $2, fbody);
	}
	;


fdef_statement
	: FDEF NAME '(' fdecl_varlist ')' statement	{
		AST* fbody = makenode("fbody", $4, $6);
		$$ = makenode("fdef_statement", $2, fbody);
	}
	;


fdecl_varlist
	: fdecl_varlist_nonempty	{ $$ = $1; }
	| /* NULL */ { $$ = NULL; }
	;


fdecl_varlist_nonempty
	: fdecl_varlist_nonempty ',' fdecl_varlist_single {
		$$ = makenode("fdecl_varlist", $1, $3);
	}
	| fdecl_varlist_single {
		$$ = makenode("fdecl_varlist", $1, NULL);
	}
	;


fdecl_varlist_single
	: VAR NAME	{ $$ = makenode("var", $2, NULL); }
	| ARRAY NAME	{ $$ = makenode("array", $2, NULL); }
	;


vdef_statement
	: VDEF vdef_varlist ';'	{ $$ = makenode("vdef_statement", $2, NULL); }
	;


vdef_varlist
	: vdef_varlist ',' vdef_varlist_single	{ $$ = makenode("vdef_varlist", $1, $3); }
	| vdef_varlist_single	{ $$ = makenode("vdef_varlist", $1, NULL); }
	;


vdef_varlist_single
	: NAME	{ $$ = makenode("vdef_var", $1, NULL); }
	| NAME '[' exprlist ']' { $$ = makenode("vdef_arr", $1, $3); }
	;


if_statement
	: IF '(' exprlist ')' statement	{
		AST* ifbody = makenode("ifbody", $3, $5);
		$$ = makenode("if_statement", ifbody, NULL);
	}
	| IF '(' exprlist ')' statement ELSE statement	{
		AST* ifbody = makenode("ifbody", $3, $5);
		$$ = makenode("if_statement", ifbody, $7);
	}
	;


for_statement
	: FOR '(' forexpr ';' forexpr ';' forexpr ')' statement	{
		/*
		for(a ; b ; c) d;

		->

		a;
		while(b) {
			d;
			c;
		}
		*/

		AST* internal = makenode("statement_list", $9, $7);
		AST* whilenode = makenode("while_statement", $5, internal);
		$$ = makenode("statement_list", $3, whilenode);
	}
	;


forexpr
	: exprlist	{ $$ = $1; }
	| { $$ = NULL; }
	;


while_statement
	: WHILE '(' exprlist ')' statement	{ $$ = makenode("while_statement", $3, $5); }
	;


return_statement
	: RETURN return_exprlist ';'	{ $$ = makenode("return_statement", $2, NULL); }
	;


return_exprlist
	: return_exprlist_nonempty	{ $$ = $1; }
	| /* NULL */	{ $$ = NULL; }
	;


return_exprlist_nonempty
	: return_exprlist_nonempty ',' exprlist	{ $$ = makenode("return_exprlist", $1, $3); }
	| exprlist	{ $$ = $1; }
	;

continue_statement
	: CONTINUE ';'	{ $$ = makenode("continue_statement", NULL, NULL); }
	;

break_statement
	: BREAK ';'	{ $$ = makenode("break_statement", NULL, NULL); }
	;

yield_statement
	: YIELD ';'	{ $$ = makenode("yield_statement", NULL, NULL); } 

expr_statement
	: exprlist ';'	{ $$ = makenode("expr_statement", $1, NULL); }
	;

blank_statement
	: ';'	{ $$ = NULL; }
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "Error on line %d : %s\n", yylineno, s);
}