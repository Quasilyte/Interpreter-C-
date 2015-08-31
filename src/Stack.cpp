#include "Stack.hpp"

#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"

#define TMPL_ARGS class T, class Ptr
#define TMPL_TYPENAMES T, Ptr
#define TMPL_CLASS_NAME Stack
#include "tmpl.hpp"

CTOR(int initialCap): elems(initialCap) {}

TMPL(T, top()) const {
  return elems.val();
}

TMPL(T, pop()) {
  return elems.bval();
}

TMPL(void, push(T value)) {
  ensureCap();
  elems.setf(value);
}

TMPL(void, ensureCap()) {
  if (elems.atEnd()) 
    elems.enlarge(elems.pos());
}

INST(int, PtrWalker<int>);
INST(double, PtrWalker<double>);
INST(char*,  RecurPtrWalker<char*>);
