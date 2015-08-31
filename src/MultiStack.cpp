#include "header/MultiStack.hpp"

#include "header/config/runtime.hpp"
#include "header/TypeConv.hpp"

#define CLASS_NAME MultiStack
#include "util/class_codegen.hpp"

PtrWalker<char> CLASS_NAME::types(DATA_STACK_SIZE * 2);
Stack<int, PtrWalker<int>> CLASS_NAME::ints(DATA_STACK_SIZE);
Stack<double, PtrWalker<double>> CLASS_NAME::doubles(DATA_STACK_SIZE);
Stack<char*, RecurPtrWalker<char*>> CLASS_NAME::strings(DATA_STACK_SIZE);

DEFN(void, push(int v)) {
  types.setf('i');
  ints.push(v);
}

DEFN(void, push(double v)) {
  types.setf('d');
  doubles.push(v);
}
  
DEFN(void, push(char* v)) {
  types.setf('s');
  strings.push(v);
}
  
DEFN(char*, popStr()) {
  switch (types.bval()) {
  case 'i': return TypeConv::toCstr(ints.pop());
  case 's': return strings.pop();
  // Should never happend
  default: throw new int(0);
  }
}    
