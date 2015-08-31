#ifndef UTIL_CSTR_RANGE_
#define UTIL_CSTR_RANGE_

struct CstrRange {
  static char* low;
  static char* high;

  static void load(char* cstr);

  static void ofDigits(char* cstr);

  static int dist();
};

#endif
