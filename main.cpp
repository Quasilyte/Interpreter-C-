#include "src/header/PtrWalker.hpp"
#include "src/header/RecurPtrWalker.hpp"
#include "src/header/ByteCode.hpp"
#include "src/header/typeconv.hpp"
#include "src/header/Evaluator.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

/*
DEFN(void, parseNum()) {
  const char* slice = input;

  while (isdigit(*++input)) {
  }

  char tmp = *input;
  *input = '\0';
  output.insert(slice, 4);
  *input = tmp;
}
*/

class StrSlice {
private:
  int pos;
  char erasedChar;
  char* mem;

public:
  StrSlice(char* str, int len) {
    pos = len;
    mem = str;
    
    erasedChar = str[len];
    mem[len] = '\0';
  }

  ~StrSlice() {
    mem[pos] = erasedChar;
  }

  operator char*() const {
    return mem;
  }
};

void print3(char *s) {
  StrSlice slice(s, 3);
  printf("`%s'\n", static_cast<char*>(slice));
}

int main() {
  Evaluator evaluator;
  char s[] = {'a', 'b', 1, 0, 0, 0, 6, 'z', 'v'};
  evaluator.eval(s, 8);

  char str[10]; strcpy(str, "string!");
  
  print3(str);
  printf("`%s'\n", str);
  
  return 0;
}

