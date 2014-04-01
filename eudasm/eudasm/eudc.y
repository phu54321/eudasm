%{
#include <stdio.h>

void yyerror(char *);
int yylex(void);

extern int yylineno;

#define YY_NEVER_INTERACTIVE

%}

%token IDENTIFIER INTEGER STRING VARTYPE
%token FUNC FOR WHILE IF ELSE
%token CONTINUE BREAK RETURN

%token MONIC_INC MONIC_DEC
%token BINARY_LSF BINARY_RSF
%token BINARY_LE BINARY_GE BINARY_EQ BINARY_NE
%token BINARY_LOGICALAND BINARY_LOGICALOR
%token ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN RMDASSIGN
%token ANDASSIGN ORASSIGN  XORASSIGN LSFASSIGN RSFASSIGN
	

	
	
%start program

%%

	/* Simple C-like language structure */
	



	/* Statements. base of eudc syntax. */
statement
	: fdef_statement
	| vardecl_statement
	| if_statement
	| while_statement
	| for_statement
	| expr_statement
	| continue_statement
	| break_statement
	| return_statement
	| error ';'
	| error '}'
	;
	

	/* Blocks. several statements makes a block. */
block:
	statement
	| '{' statement_list '}'
	;

statement_list
	: statement_list statement
	| /* NULL */
	;

	
	/* Function definition syntax */
	/* func myfunc(ptr a, ptr b); */
fdef_statement
	: FUNC IDENTIFIER '(' argdef ')' block
	;
	
argdef
	: VARTYPE IDENTIFIER argdef2
	| /* NULL*/
	;
	
argdef2
	: argdef2 ',' VARTYPE IDENTIFIER
	| /* NULL */
	;
	
	
	
vardecl_statement:
	VARTYPE IDENTIFIER vardecl_list ';'
	;
	
vardecl_list:
	vardecl_list ',' IDENTIFIER
	| /* NULL */
	;
	
	
if_statement:
	IF '(' expr ')' block
	| IF '(' expr ')' block ELSE block
	;
	
	
while_statement
	: WHILE '(' expr ')' block
	;
	
	
for_statement
	: FOR '(' expr ';' expr ';' expr ')' block
	;
	
	

	/* general expr syntax */
	/* based on C operators. */
	
	/*
	origin : http://en.cppreference.com/w/cpp/language/operator_precedence
	
	1	++   --	 Suffix/postfix increment and decrement
		()	 Function call
		[]	 Array subscripting
	2	++   --	 Prefix increment and decrement	 Right-to-left
		+   −	 Unary plus and minus
		!   ~	 Logical NOT and bitwise NOT
		*	 Indirection (dereference)
		&	 Address-of
	3	*   /   %	 Multiplication, division, and remainder
	4	+   −	 Addition and subtraction
	5	<<   >>	 Bitwise left shift and right shift
	6	<   <=	 For relational operators < and ≤ respectively
		>   >=	 For relational operators > and ≥ respectively
		==   !=	 For relational = and ≠ respectively
	7	&	 Bitwise AND
		^	 Bitwise XOR (exclusive or)
		|	 Bitwise OR (inclusive or)
	8	&&	 Logical AND
		||	 Logical OR
	9	?:	 Ternary conditional[1]	 Right-to-left
		=	 Direct assignment (provided by default for C++ classes)
		+=   −=	 Assignment by sum and difference
		*=   /=   %=	 Assignment by product, quotient, and remainder
		<<=   >>=	 Assignment by bitwise left shift and right shift
		&=   ^=   |=	 Assignment by bitwise AND, XOR, and OR
	*/
	
preexp
	: INTEGER
	| STRING
	| IDENTIFIER
	| '(' expr ')'
	;

expr_1
	: preexp
	| expr_1 MONIC_INC
	| expr_1 MONIC_DEC
	| expr_1 '(' arglist ')'
	| expr_1 '[' expr ']'
	;
	
arglist
	: expr arglist2
	| /* NULL */
	;
	
arglist2
	: arglist2 ',' expr
	| /* NULL */
	;
	
expr_2
	: expr_1
	| MONIC_INC    expr_2
	| MONIC_DEC    expr_2
	| '+'          expr_2
	| '-'          expr_2
	| '!'          expr_2
	| '~'          expr_2
	| '*'          expr_2
	| '&'          expr_2
	;
	
expr_3
	: expr_2
	| expr_3 '*' expr_2
	| expr_3 '/' expr_2
	| expr_3 '%' expr_2
	;
	
expr_4
	: expr_3
	| expr_4 '+' expr_3
	| expr_4 '-' expr_3
	;
	
expr_5
	: expr_4
	| expr_5 BINARY_LSF expr_4
	| expr_5 BINARY_RSF expr_4
	;
	
expr_6
	: expr_5
	| expr_6 '<'       expr_5
	| expr_6 BINARY_LE expr_5
	| expr_6 '>'       expr_5
	| expr_6 BINARY_GE expr_5
	| expr_6 BINARY_EQ expr_5
	| expr_6 BINARY_NE expr_5
	;
	
expr_7
	: expr_6
	| expr_7 '&' expr_6
	| expr_7 '^' expr_6
	| expr_7 '|'  expr_6
	;
	
expr_8
	: expr_7
	| expr_8 BINARY_LOGICALAND expr_7
	| expr_8 BINARY_LOGICALOR  expr_7
	;
	
expr_9
	: expr_8
	| expr_9'?' expr_9 ':' expr_9
	| expr_8 '='       expr_9
	| expr_8 ADDASSIGN expr_9
	| expr_8 SUBASSIGN expr_9
	| expr_8 MULASSIGN expr_9
	| expr_8 DIVASSIGN expr_9
	| expr_8 RMDASSIGN expr_9
	| expr_8 ANDASSIGN expr_9
	| expr_8 ORASSIGN  expr_9
	| expr_8 XORASSIGN expr_9
	| expr_8 LSFASSIGN expr_9
	| expr_8 RSFASSIGN expr_9
	;
	
expr
	: expr_9
	;

expr_statement
	: expr ';'
	;



continue_statement
	: CONTINUE ';'

break_statement
	: BREAK ';'

return_statement
	: RETURN expr ';'
	
	
	
	
	/* Finally, program itself. */
program:
	statement_list
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "Error on line %d : %s\n", yylineno, s);
}
