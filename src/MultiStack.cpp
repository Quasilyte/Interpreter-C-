#include "MultiStack.hpp"

#include "typeconv.hpp"

MultiStack::MultiStack(int initialCap):
  types(initialCap * 2),
  ints(initialCap),
  doubles(initialCap),
  strings(initialCap) {}

void MultiStack::push(int v) {
  types.setf('i');
  ints.push(v);
}

void MultiStack::push(double v) {
  types.setf('d');
  doubles.push(v);
}
  
void MultiStack::push(char* v) {
  types.setf('s');
  strings.push(v);
}
  
char* MultiStack::popStr() {
  switch (types.bval()) {
  case 'i': return toStr(ints.pop());
  case 's': return strings.pop();
  // Should never happend
  default: throw new int(0);
  }
}    
