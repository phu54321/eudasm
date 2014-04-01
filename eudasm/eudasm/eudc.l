
%{

#include "eudc.tab.hpp"
#include <stdlib.h>
void yyerror(char *);
   
#define VT_VAR 0
#define VT_PTR 1

#define YY_NO_UNISTD_H
#define YY_NEVER_INTERACTIVE 1

%}


%start STATE_LC STATE_LC2
%start STATE_STRING

%option noyywrap
%option yylineno

%%
	/*
	%token IDENTIFIER INTEGER STRING VARTYPE
	%token FUNC FOR WHILE IF ELSE
	%token CONTINUE BREAK RETURN
	
	%token MONIC_INC MONIC_DEC
	%token BINARY_LSF BINARY_RSF
	%token BINARY_LE BINARY_GE BINARY_EQ BINARY_NE
	%token BINARY_LOGICALAND BINARY_LOGICALOR
	%token ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN RMDASSIGN
	%token ANDASSIGN ORASSIGN  XORASSIGN LSFASSIGN RSFASSIGN
	*/
	
	

	// Ignore blank line & comments
<INITIAL>[ \t\r\n]* //skip

\/\/.*	{}
\/\*	{ BEGIN STATE_LC; }
<STATE_LC>\*	{ BEGIN STATE_LC2; }
<STATE_LC>[^\*]	{ }
<STATE_LC2>\/	{ BEGIN 0; }
<STATE_LC2>\*	{}
<STATE_LC2>[^\*]*	{ BEGIN STATE_LC; }



	/* Read all known keywords */
if	{ return IF; }
else	{ return ELSE; }
for	{ return FOR; }
while	{ return WHILE; }
func	{ return FUNC; }
continue	{ return CONTINUE; }
break	{ return BREAK; }
return	{ return RETURN; }

\+\+	{ return MONIC_INC; }
--	{ return MONIC_DEC; }
\<\<	{ return BINARY_LSF; }
\>\>	{ return BINARY_RSF; }
\<=	{ return BINARY_LE; }
\>=	{ return BINARY_GE; }
==	{ return BINARY_EQ; }
!=	{ return BINARY_NE; }
&&	{ return BINARY_LOGICALAND; }
\|\|	{ return BINARY_LOGICALOR; }
\+=	{ return ADDASSIGN; }
-=	{ return SUBASSIGN; }
\*=	{ return MULASSIGN; }
\/=	{ return DIVASSIGN; }
%=	{ return RMDASSIGN; }
&=	{ return ANDASSIGN; }
\|=	{ return ORASSIGN; }
\^=	{ return XORASSIGN; }
\<\<=	{ return LSFASSIGN; }
\>\>=	{ return RSFASSIGN; }


var	{ yylval = VT_VAR; return VARTYPE; }
ptr	{ yylval = VT_PTR; return VARTYPE; }


	/* Read identifiers */
[_a-zA-Z]([_0-9a-zA-Z])*	{
		// yylval = GetNameIdentifier(yytext);
		return IDENTIFIER;
	}

0|([1-9][0-9]*)|(0x[0-9a-zA-Z]+)|(0[0-7]+)	{
		yylval = strtol(yytext, NULL, 0);
		return INTEGER;
	}



<INITIAL>\"   BEGIN STATE_STRING; /* no yymore here */
<STATE_STRING>[^\\\n\"]+	yymore();
<STATE_STRING><<EOF>>	{ yyerror("EOF in string.");       BEGIN 0; }
<STATE_STRING>\n	{ yyerror("Unterminated string."); BEGIN 0; }
<STATE_STRING>\\\n	yymore();
<STATE_STRING>\"	{
		yytext[yyleng-1] = '\0';
		BEGIN 0;
	}
	

	/* anything else will just pass by. */
.	{ return *yytext; }
%%
