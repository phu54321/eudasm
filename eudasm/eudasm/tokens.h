#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef struct {
	int tokentype;
	size_t len;
	char data[1];
} Token;

Token* GenerateToken(int tokentype, const void* data, size_t len);

#ifdef __cplusplus
}
#endif