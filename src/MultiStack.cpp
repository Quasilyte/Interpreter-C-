#include "header/MultiStack.hpp"

#include "header/TypeConv.hpp"

#define CLASS_NAME MultiStack
#include "util/class_codegen.hpp"

CTOR(int initialCap):
  types(initialCap * 2),
  ints(initialCap),
  doubles(initialCap),
  strings(initialCap) {}

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
