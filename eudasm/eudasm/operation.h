#pragma once

#include "type.h"
#include <memory>

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
	OP_PHI
};


class Operation {
public:
	Operation(Opcode opc);
	virtual ~Operation();

	CTypePtr OutType();

};