#pragma once

#include <exception>
#include <string>
#include <assert.h>


class ParserException : public std::exception {
public:
	ParserException(const std::string& reason);
	ParserException(const char* reason);
	virtual ~ParserException();
	virtual const char* what() const;

private:
	std::string _reason;
};

void runtime_assert_internal(const char* filename, int lineno, const char* funcname, bool expr, const char* exprstr);
#define runtime_assert(expr) runtime_assert_internal(__FILE__, __LINE__, __FUNCTION__, (expr), #expr)

// Fucking Visual Studio
#ifdef _MSC_VER
#if (_MSC_VER <= 1700)
int snprintf(char* str, int count, const char* format, ...);
#endif
#endif