#pragma once

#include <vector>
#include <string>
#include <memory>


enum class ASTType {
	AST_FDEF_STATEMENT,
	AST_FBODY,
	AST_FUNC_ARGLIST,
	AST_FUNC_ARGDEF,
	AST_FUNC_TYPE,
	AST_FUNC_NAME,
	AST_PLUS,
	AST_MINUS,
};

class AST {
public:
	AST(ASTType type);
	~AST();

	virtual bool IsTerminal() const;
	void push_back(AST* ast);
	AST* operator[](int index);

private:
	std::vector<AST*> _subnodes;
	int value;
};