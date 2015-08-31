#ifndef TYPECONV_
#define TYPECONV_

#include <stdint.h>

#include "platform_specific/endians.hpp"

int32_t toInt(char* v);
char* toStr(int32_t v);

int32_t intBytesToInt(char* v);
char* strToIntBytes(char* s);

#endif
