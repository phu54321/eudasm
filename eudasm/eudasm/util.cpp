#include "util.h"

ParserException::ParserException(const char* reason) : _reason(reason) {}
ParserException::ParserException(const std::string& reason) : _reason(reason) {}
ParserException::~ParserException() {}
const char* ParserException::what() const { return _reason.c_str(); }
