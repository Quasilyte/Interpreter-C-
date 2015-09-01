#include "PtrWalker.hpp"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TMPL_ARGS class T
#define TMPL_TYPENAMES T
#define CLASS_NAME PtrWalker
#include "class_codegen.hpp"

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

DEFN(void, rewind()) {
  p = mem;
}

DEFN(int, pos()) const {
  return p - mem;
}

DEFN(void, enlarge(const int offset)) {
  cap += cap - 1;
  mem = (T*) realloc(mem, cap * sizeof(T));
  p = mem + offset;
}

DEFN(bool, atEnd()) const {
  return pos() == cap;
}

DEFN(bool, canMovef()) const {
  return pos() < cap;
}

DEFN(bool, canMoveb()) const {
  return pos() > -1;
}

DEFN(T*, begin()) const {
  return mem;
}

DEFN(T*, head()) const {
  return p;
}

DEFN(T, val()) const {
  return *p;
}

DEFN(T, valf()) {
  return *p++;
}

DEFN(T, fval()) {
  return *++p;
}

DEFN(T, valb()) {
  return *p--;
}

DEFN(T, bval()) {
  return *--p;
}

DEFN(void, set(T value)) {
  *p = value;
}

DEFN(void, setf(T value)) {
  *p++ = value;
}

DEFN(void, fset(T value)) {
  *++p = value;
}

DEFN(void, setb(T value)) {
  *p-- = value;
}

DEFN(void, bset(T value)) {
  *--p = value;
}

DEFN(void, insert(T* value, int n)) {
  memcpy(p, value, n); 
}

DEFN(void, insertf(T* value, int n)) {
  insert(value, n);
  move(n);
}

DEFN(void, operator++()) {
  ++p;
}

DEFN(void, operator--()) {
  --p;
}

DEFN(void, move(int distance)) {
  p += distance;
}

PERMIT(unsigned char);
PERMIT(char);
PERMIT(int);
PERMIT(double);

// Instances below are only for RecurPtrWalker
PERMIT(char*); 
