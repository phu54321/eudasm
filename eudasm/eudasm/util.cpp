#pragma warning(disable:4996)

#include "util.h"
#include <stdarg.h>
#include <stdio.h>

ParserException::ParserException(const char* reason) : _reason(reason) {}
ParserException::ParserException(const std::string& reason) : _reason(reason) {}
ParserException::~ParserException() {}
const char* ParserException::what() const { return _reason.c_str(); }



void runtime_assert_internal(const char* filename, int lineno, const char* funcname, bool expr, const char* exprstr) {
	if(expr) {
		char str[512];
		sprintf_s(str, "[Assertion Error] File %s, Line %d, Function %s : Assertion on expression %s failed.",
			filename, lineno, funcname, exprstr);
	}
}


// Fucking Visual Studio
#ifdef _MSC_VER
#if (_MSC_VER <= 1700)
int snprintf(char* str, int count, const char* format, ...) {
	va_list v;
	va_start(v, format);
	int ret = vsnprintf(str, count, format, v);
	// Fucking VS
	if(count) str[count - 1] = 0;
	va_end(v);
	return ret;
}

#endif
#endif