/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : antlr\\eudc.g
 *     -                            On : 2014-04-02 22:54:49
 *     -                 for the lexer : eudcLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
eudcLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef peudcLexer, which is returned from a call to eudcLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in peudcLexer are  as follows:
 *
 *  - 
 void
      peudcLexer->T__11(peudcLexer)
 *  - 
 void
      peudcLexer->T__12(peudcLexer)
 *  - 
 void
      peudcLexer->T__13(peudcLexer)
 *  - 
 void
      peudcLexer->T__14(peudcLexer)
 *  - 
 void
      peudcLexer->T__15(peudcLexer)
 *  - 
 void
      peudcLexer->T__16(peudcLexer)
 *  - 
 void
      peudcLexer->T__17(peudcLexer)
 *  - 
 void
      peudcLexer->T__18(peudcLexer)
 *  - 
 void
      peudcLexer->T__19(peudcLexer)
 *  - 
 void
      peudcLexer->T__20(peudcLexer)
 *  - 
 void
      peudcLexer->T__21(peudcLexer)
 *  - 
 void
      peudcLexer->T__22(peudcLexer)
 *  - 
 void
      peudcLexer->T__23(peudcLexer)
 *  - 
 void
      peudcLexer->T__24(peudcLexer)
 *  - 
 void
      peudcLexer->T__25(peudcLexer)
 *  - 
 void
      peudcLexer->T__26(peudcLexer)
 *  - 
 void
      peudcLexer->T__27(peudcLexer)
 *  - 
 void
      peudcLexer->T__28(peudcLexer)
 *  - 
 void
      peudcLexer->T__29(peudcLexer)
 *  - 
 void
      peudcLexer->T__30(peudcLexer)
 *  - 
 void
      peudcLexer->T__31(peudcLexer)
 *  - 
 void
      peudcLexer->T__32(peudcLexer)
 *  - 
 void
      peudcLexer->T__33(peudcLexer)
 *  - 
 void
      peudcLexer->T__34(peudcLexer)
 *  - 
 void
      peudcLexer->T__35(peudcLexer)
 *  - 
 void
      peudcLexer->T__36(peudcLexer)
 *  - 
 void
      peudcLexer->T__37(peudcLexer)
 *  - 
 void
      peudcLexer->T__38(peudcLexer)
 *  - 
 void
      peudcLexer->T__39(peudcLexer)
 *  - 
 void
      peudcLexer->T__40(peudcLexer)
 *  - 
 void
      peudcLexer->T__41(peudcLexer)
 *  - 
 void
      peudcLexer->T__42(peudcLexer)
 *  - 
 void
      peudcLexer->T__43(peudcLexer)
 *  - 
 void
      peudcLexer->T__44(peudcLexer)
 *  - 
 void
      peudcLexer->T__45(peudcLexer)
 *  - 
 void
      peudcLexer->T__46(peudcLexer)
 *  - 
 void
      peudcLexer->T__47(peudcLexer)
 *  - 
 void
      peudcLexer->T__48(peudcLexer)
 *  - 
 void
      peudcLexer->T__49(peudcLexer)
 *  - 
 void
      peudcLexer->T__50(peudcLexer)
 *  - 
 void
      peudcLexer->T__51(peudcLexer)
 *  - 
 void
      peudcLexer->T__52(peudcLexer)
 *  - 
 void
      peudcLexer->T__53(peudcLexer)
 *  - 
 void
      peudcLexer->T__54(peudcLexer)
 *  - 
 void
      peudcLexer->T__55(peudcLexer)
 *  - 
 void
      peudcLexer->T__56(peudcLexer)
 *  - 
 void
      peudcLexer->T__57(peudcLexer)
 *  - 
 void
      peudcLexer->T__58(peudcLexer)
 *  - 
 void
      peudcLexer->T__59(peudcLexer)
 *  - 
 void
      peudcLexer->T__60(peudcLexer)
 *  - 
 void
      peudcLexer->T__61(peudcLexer)
 *  - 
 void
      peudcLexer->VARTYPE(peudcLexer)
 *  - 
 void
      peudcLexer->NAME(peudcLexer)
 *  - 
 void
      peudcLexer->NUMBER(peudcLexer)
 *  - 
 void
      peudcLexer->STRING(peudcLexer)
 *  - 
 void
      peudcLexer->SHORTCOMMENT(peudcLexer)
 *  - 
 void
      peudcLexer->LONGCOMMENT(peudcLexer)
 *  - 
 void
      peudcLexer->SPACE(peudcLexer)
 *  - 
 void
      peudcLexer->Tokens(peudcLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_eudcLexer_H
#define _eudcLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct eudcLexer_Ctx_struct eudcLexer, * peudcLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
eudcLexer

 */
struct eudcLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mT__11)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__12)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__13)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__14)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__15)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__16)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__17)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__18)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__19)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__20)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__21)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__22)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__23)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__24)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__25)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__26)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__27)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__28)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__29)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__30)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__31)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__32)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__33)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__34)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__35)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__36)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__37)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__38)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__39)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__40)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__41)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__42)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__43)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__44)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__45)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__46)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__47)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__48)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__49)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__50)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__51)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__52)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__53)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__54)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__55)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__56)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__57)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__58)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__59)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__60)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mT__61)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mVARTYPE)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mNAME)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mNUMBER)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mSTRING)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mSHORTCOMMENT)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mLONGCOMMENT)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mSPACE)	(struct eudcLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct eudcLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct eudcLexer_Ctx_struct * ctx);
    void	    (*free)   (struct eudcLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API peudcLexer eudcLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API peudcLexer eudcLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__11      11
#define T__12      12
#define T__13      13
#define T__14      14
#define T__15      15
#define T__16      16
#define T__17      17
#define T__18      18
#define T__19      19
#define T__20      20
#define T__21      21
#define T__22      22
#define T__23      23
#define T__24      24
#define T__25      25
#define T__26      26
#define T__27      27
#define T__28      28
#define T__29      29
#define T__30      30
#define T__31      31
#define T__32      32
#define T__33      33
#define T__34      34
#define T__35      35
#define T__36      36
#define T__37      37
#define T__38      38
#define T__39      39
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define T__44      44
#define T__45      45
#define T__46      46
#define T__47      47
#define T__48      48
#define T__49      49
#define T__50      50
#define T__51      51
#define T__52      52
#define T__53      53
#define T__54      54
#define T__55      55
#define T__56      56
#define T__57      57
#define T__58      58
#define T__59      59
#define T__60      60
#define T__61      61
#define LONGCOMMENT      4
#define NAME      5
#define NUMBER      6
#define SHORTCOMMENT      7
#define SPACE      8
#define STRING      9
#define VARTYPE      10
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for eudcLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
