%{
#include "eudc.tab.hpp"
#include <stdlib.h>
#include "ast.h"

void yyerror(char *);
   
#define YY_NO_UNISTD_H
#define YY_NEVER_INTERACTIVE 1

int charpos = 0;
#define YY_USER_ACTION { charpos += yyleng; }
%}


%start STATE_LC STATE_LC2
%start STATE_STRING

%option noyywrap
%option yylineno

%%
	/*
	%token NAME INTEGER STRING
	%token INCR DECR LE GE EQ NE AND OR ADDMOV SUBMOV
	%token FDEF FDECL VDEF VAR ARRAY
	%token FOR WHILE IF ELSE CONTINUE BREAK
	%token RETURN YIELD
	*/



	/* Ignore blank line & comments */
<INITIAL>[ \t\r]*	;
<INITIAL>\n	{ charpos = 0; /* reset position. */ }


	/* Ignore comment */
<INITIAL>\/\/.*	{}
<INITIAL>\/\*	{ BEGIN STATE_LC; }
<STATE_LC>\*	{ BEGIN STATE_LC2; }
<STATE_LC>[^\*]	{ }
<STATE_LC2>\/	{ BEGIN 0; }
<STATE_LC2>\*	{}
<STATE_LC2>[^\*]*	{ BEGIN STATE_LC; }


	/* String */
<INITIAL>\"([^\"]|\\.)*\"	{
	yylval = makenode("string", yytext, yylineno, charpos - yyleng + 1);
	return STRING;
}

	/* Read all known keywords
	 LE GE EQ NE AND OR ADDMOV SUBMOV
	 FDEF FDECL VDEF VAR ARR
	 FOR WHILE IF ELSE CONTINUE BREAK
	 RETURN YIELD
	*/

\+\+	{ return INCR; }
--	{ return DECR; }
\<=	{ return LE; }
>=	{ return GE; }
==	{ return EQ; }
!=	{ return NE; }
and	{ return AND; }
or	{ return OR; }
\+=	{ return ADDMOV; }
-=	{ return SUBMOV; }

fdef	{ return FDEF; }
fdecl	{ return FDECL; }

vdef	{ return VDEF; }
var		{ return VAR; }
array		{ return ARRAY; }

for			{ return FOR; }
while		{ return WHILE; }
if			{ return IF; }
else		{ return ELSE; }
continue	{ return CONTINUE; }
break		{ return BREAK; }
return		{ return RETURN; }
yield		{ return YIELD; }


	/* Read identifiers */
[_a-zA-Z]([_0-9a-zA-Z])*	{
		yylval = makenode("name", yytext, yylineno, charpos - yyleng + 1);
		return NAME;
	}

	/* read numbers. */
0|([1-9][0-9]*)|(0x[0-9a-zA-Z]+)|(0[0-7]+)	{
		yylval = makenode("integer", yytext, yylineno, charpos - yyleng + 1);
		return INTEGER;
	}

	/* anything else will just pass by. */
.	{ return *yytext; }

%%