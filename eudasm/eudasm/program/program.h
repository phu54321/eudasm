#pragma once

#include <map>
#include <deque>
#include <string>
#include <list>
#include <exception>

#include "../type/type.h"
#include "namespace.h"
#include "../murmurhash3.h"

enum class Opcode {
	OP_ADD,
	OP_SUB,
	OP_EQ,
	OP_LE,
	OP_GE,
	OP_NOT,
	OP_AND,
	OP_OR,
	OP_JZ,
	OP_JMP,
	OP_CALL,
	OP_GETPTR,
	OP_PHI,
	OP_LABEL
};

enum OprType {
	OPERAND_STRING,
	OPERAND_NUMBER,
	OPERAND_VARIABLE,
	OPERAND_LABEL
};

struct Operand {
	Operand(OprType type, int value);

	int type;
	union {
		uint64_t stringid;
		int number;
		int varid;
		int labelid;
	} data;
};


struct Operation {
	Opcode opc;
	Operand out, op1, op2;
};


class Program {
public:
	Program();
	~Program();

	// Label, String : Global Resource
	Operand GetLabel(const char* name);
	Operand GetString(const char* content);
	Operand GetVariable(const char* name);
	
	void PushBlock();
	void CreateVariable(const char* name, CTypePtr type);
	void PopBlock();

	Operand PushAdd(Operand op1, Operand op2);
	Operand PushSub(Operand op1, Operand op2);
	Operand PushLe(Operand op1, Operand op2);
	Operand PushRe(Operand op1, Operand op2);
	Operand PushEq(Operand op1, Operand op2);
	Operand PushNe(Operand op1, Operand op2);
	Operand PushAnd(Operand op1, Operand op2);
	Operand PushOr(Operand op1, Operand op2);
	Operand PushNot(Operand op1);
	void PushJz(Operand op1, Operand op2);
	void PushJmp(Operand op1);
	Operand PushCall(Operand op1);
	Operand PushGetPtr(Operand op1, Operand op2);
	Operand PushPhi(Operand op1, Operand op2);
	void PushLabel(Operand labelid);

	std::list<Operation>& GetList();

private:
	Namespace _namespace;
	std::list<Operation> _functionlist;
};
