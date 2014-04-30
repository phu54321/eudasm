// Implements simple recursive parser

/*

preexp
	: number
	| name
	| '(' expr ')'
	;

expr
	: expr '+' expr
	| expr '-' expr
*/