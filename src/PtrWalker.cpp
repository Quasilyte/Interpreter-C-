#include "PtrWalker.hpp"

#include <stdlib.h>
#include <string.h>

#define TMPL_ARGS class T
#define TMPL_TYPENAMES T
#define TMPL_CLASS_NAME PtrWalker
#include "tmpl.hpp"

CTOR(T* initializer, int initializerSize) {
  this->cap = initializerSize;

  mem = initializer;
  p = mem;
}

CTOR(const int initialCap) {
  cap = initialCap;

  mem = (T*) calloc(initialCap, sizeof(T));
  p = mem;
}

DTOR() {
  if (mem) 
    free(mem);
}

TMPL(void, rewind()) {
  p = mem;
}

TMPL(int, pos()) const {
  return p - mem;
}

TMPL(void, enlarge(const int offset)) {
  cap += cap - 1;
  mem = (T*) realloc(mem, cap * sizeof(T));
  p = mem + offset;
}

TMPL(bool, atEnd()) const {
  return pos() == cap;
}

TMPL(T*, begin()) const {
  return mem;
}

TMPL(T*, head()) const {
  return p;
}

TMPL(T, val()) const {
  return *p;
}

TMPL(T, valf()) {
  return *p++;
}

TMPL(T, fval()) {
  return *++p;
}

TMPL(T, valb()) {
  return *p--;
}

TMPL(T, bval()) {
  return *--p;
}

TMPL(void, set(T value)) {
  *p = value;
}

TMPL(void, setf(T value)) {
  *p++ = value;
}

TMPL(void, fset(T value)) {
  *++p = value;
}

TMPL(void, setb(T value)) {
  *p-- = value;
}

TMPL(void, bset(T value)) {
  *--p = value;
}

TMPL(void, insert(T* value, int n)) {
  memcpy(p, value, n); 
}

TMPL(void, operator++()) {
  ++p;
}

TMPL(void, operator--()) {
  --p;
}

TMPL(void, move(int distance)) {
  p += distance;
}

INST(char);
INST(int);
INST(double);

// Instances below are only for RecurPtrWalker
INST(char*); 
