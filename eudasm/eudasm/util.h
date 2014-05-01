#pragma once

#include <exception>
#include <string>

class ParserException : public std::exception {
public:
	ParserException(const std::string& reason);
	ParserException(const char* reason);
	virtual ~ParserException();
	virtual const char* what() const;

private:
	std::string _reason;
};

void runtime_assert_internal(const char* filename, int lineno, const char* funcname, bool expr, const char* errormsg);
#define runtime_assert(expr, errormsg) runtime_assert_internal(__FILE__, __LINE__, __FUNCTION__, (expr), (errormsg))
