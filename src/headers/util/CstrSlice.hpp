#ifndef UTIL_CSTR_SLICE_
#define UTIL_CSTR_SLICE_

class CstrSlice {
private:
  int pos;
  char erasedChar;
  char* slice;

public:
  CstrSlice(char* cstr, int len);

  // Restore corrupted string
  ~CstrSlice();

  operator char*() const;
};

#endif
