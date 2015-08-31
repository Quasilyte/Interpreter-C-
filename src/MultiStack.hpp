#ifndef MULTI_STACK_
#define MULTI_STACK_

#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"
#include "Stack.hpp"

extern template class PtrWalker<int>;
extern template class PtrWalker<double>;
extern template class RecurPtrWalker<char*>;

class MultiStack {
private:
  PtrWalker<char> types;
  Stack<int, PtrWalker<int>> ints;
  Stack<double, PtrWalker<double>> doubles;
  Stack<char*, RecurPtrWalker<char*>> strings;

public:
  MultiStack(int initialCap);

  void push(int v);
  void push(double v);
  void push(char* v);
  
  char* popStr();    
};

#endif
