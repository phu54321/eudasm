#pragma once
/*
#include <list>

enum Vartype {
	VAR_FULL,
	VAR_LIGHT
};

struct Variable {
	int ID;
	Vartype type;
};

struct Function {
	int ID;
	int argn;
};

struct String {
	int ID;
};

enum {
	SYMBOL_VARIABLE,
	SYMBOL_FUNCION,
	SYMBOL_INTEGER,
	SYMBOL_STRING,
	SYMBOL_INVALID,
};

struct Symbol {
	int symtype;
	union {
		Variable var;
		Function func;
		int value;
		String str;
	} data;
};

void PushBlock();
int CreateVariable(Vartype type, const std::string& name);
Variable GetVariable(const std::string& name);
Variable GetTempVariable();
void PopBlock();

Function CreateFunction(const std::string& funcname, int argn);
Function GetFunction(const std::string& funcname);

String GetString(const std::string& data);

*/