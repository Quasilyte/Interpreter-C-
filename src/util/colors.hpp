#ifndef UTIL_COLORS_
#define UTIL_COLORS_

// #FIXME: everything should be defined by special flags,
// so we can have colorful output on multiple
// terminals, but it is OK for now.

#define SEQ_RESET "\x1B[0m"
#define SEQ_RED  "\x1B[31m"
#define SEQ_GREEN "\x1B[32m"
#define SEQ_YELLOW "\x1B[33m"
#define SEQ_BLUE "\x1B[34m"
#define SEQ_VIOLET "\x1B[35m"
#define SEQ_CYAN "\x1B[36m"
#define SEQ_WHITE "\x1B[37m"

#define RED(str) SEQ_RED str SEQ_RESET
#define GREEN(str) SEQ_GREEN str SEQ_RESET
#define YELLOW(str) SEQ_YELLOW str SEQ_RESET
#define BLUE(str) SEQ_BLUE str SEQ_RESET
#define VIOLET(str) SEQ_VIOLET str SEQ_RESET
#define CYAN(str) SEQ_CYAN str SEQ_RESET
#define WHITE(str) SEQ_WHITE str SEQ_RESET

#define BOLD(str) "\x1B[1m" str SEQ_RESET

#endif
