grammar eudc;

options {
	language = C;
	output = AST;
}

VARTYPE	:	'fv' | 'lv';
NAME	:	('_' | ('a' .. 'z' | 'A' .. 'Z')) ('_' | ('a' .. 'z' | 'A' .. 'Z' | '0' .. '9'))* ;
NUMBER	:	( '0x' ('0' .. '9' | 'a' .. 'z' | 'A' .. 'Z')+ | ('1' .. '9') ('0' .. '9')* | '0' ('0' .. '7') + | '0') ;
STRING	:	'"' (~('"' | '\\') | ('\\' ( 'n' | 'r' | '"' | '\'' | 'x' ('0' .. '9' | 'a' .. 'f' | 'A' .. 'F')
		('0' .. '9' | 'a' .. 'f' | 'A' .. 'F') | 'a' | 'b' | 'f' | 't' | 'v' | '\\' | '0' | '\n') ) ) * '"';

SHORTCOMMENT
	:	'//' (~'\n')* { $channel=HIDDEN; };

LONGCOMMENT
	:	'/*' (options {greedy=false;} : .)* '*/' {$channel=HIDDEN;} ;
	
SPACE
	:	('\n' | '\r' | '\t') + {$channel=HIDDEN;} ;


statement
	: fdecl_statement
	| fdef_statement
	| vardecl_statement
	| if_statement
	| while_statement
	| for_statement
	| expr_statement
	| continue_statement
	| break_statement
	| return_statement
	;
	


block:
	statement
	| '{' statement* '}'
	;
	
	
	/* Function definition syntax */
fdecl_statement
	:	'fdecl' NAME '(' argdef ')' ';' ;
	
fdef_statement
	:	'fdef' NAME '(' argdef ')' block ;

argdef	:	(NAME ( ',' NAME )* )? ;

	
vardecl_statement
	: 'def' VARTYPE vardecl (',' vardecl)* ';' ;

vardecl	:	NAME ( '=' expr ) ;
	
if_statement
	:	'if' '(' expr ')' block (options {greedy=true;} : 'else' block)? ;
	
	
while_statement
	:	'while' '(' expr ')' block ;
	
	
for_statement
	:	'for' '(' expr ';' expr ';' expr ')' block
	;
	

	
preexp	:	NAME | NUMBER | STRING | '(' expr ')' ;

expr_1	:	preexp ('++' | '--' | '(' arglist ')' | '[' expr ']') * ;
arglist :	(expr (',' expr)*)? ;
	
expr_2	:	('++' | '--' | '+' | '-' | '!' | '~' | '*' | '&')* expr_1;
expr_3	:	expr_2 ( ( '*' | '/' | '%' ) expr_2 )* ;
expr_4	:	expr_3 ( ( '+' | '-' ) expr_3 )* ;
expr_5	:	expr_4 ( ( '<<' | '>>' ) expr_4 )* ;
expr_6	:	expr_5 ( ( '<' | '<=' | '>' | '>=' | '==' | '!=' ) expr_5 )* ;
expr_7	:	expr_6 ( ( '&' | '^' | '|' ) expr_6 )* ;
expr_8	:	expr_7 ( ( '&&' | '||' ) expr_7 )* ;
expr_9	:	expr_8 ( ( '=' | '+=' | '-=' | '*=' | '/=' | '%=' | '&=' | '|=' | '^=' | '<<=' | '>>=' ) expr_8 )* ;
expr	:	expr_9;

expr_statement
	: expr ';' ;

continue_statement
	:	'continue' ';' ;
	
break_statement
	:	'break' ';' ;

return_statement
	:	'return' expr ';' ;
	
	
	
	
	/* Finally, program itself. */
program	:	statement* ;


