#pragma once

#include <string>
#include <memory>

struct nodeimpl;
typedef const nodeimpl* node;

struct nodeimpl {
	nodeimpl(const char* type, const std::string& str);
	nodeimpl(const char* type, node left, node right);
	~nodeimpl();

	const char* const type;
	const std::string* const str;
	node left;
	node right;
};

node makenode();
node makenode(const char* type, const std::string& str);
node makenode(const char* type, node left, node right);

