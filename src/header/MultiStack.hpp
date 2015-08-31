#ifndef HEADER_MULTI_STACK_
#define HEADER_MULTI_STACK_

#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"
#include "Stack.hpp"

class MultiStack {
private:
  static PtrWalker<char> types;
  static Stack<int, PtrWalker<int>> ints;
  static Stack<double, PtrWalker<double>> doubles;
  static Stack<char*, RecurPtrWalker<char*>> strings;

public:
  static void push(int v);
  static void push(double v);
  static void push(char* v);
  
  static char* popStr();    
};

#endif
