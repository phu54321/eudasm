#pragma once

#include "../type/type.h"
#include <memory>
#include <stdint.h>

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



