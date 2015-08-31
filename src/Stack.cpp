#include "Stack.hpp"

#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"

#define TMPL_ARGS class T, class Ptr
#define TMPL_TYPENAMES T, Ptr
#define CLASS_NAME Stack
#include "util/class_codegen.hpp"

CTOR(int initialCap): elems(initialCap) {}

DEFN(T, top()) const {
  return elems.val();
}

DEFN(T, pop()) {
  return elems.bval();
}

DEFN(void, push(T value)) {
  ensureCap();
  elems.setf(value);
}

DEFN(void, ensureCap()) {
  if (elems.atEnd()) 
    elems.enlarge(elems.pos());
}

PERMIT(int, PtrWalker<int>);
PERMIT(double, PtrWalker<double>);
PERMIT(char*,  RecurPtrWalker<char*>);
