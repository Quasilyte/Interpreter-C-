#ifndef COMPILER_
#define COMPILER_

class Compiler {
private:
  static char* input;
  static char* output;

public:
  static char* toByteCode(char* input);
};

#endif
