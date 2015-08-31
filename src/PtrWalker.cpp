#include "PtrWalker.hpp"

#include <stdlib.h>

template <class T>
PtrWalker<T>::PtrWalker(T* initializer, int initializerSize) {
  this->cap = initializerSize;

  begin = initializer;
  head = begin;
}

template <class T>
PtrWalker<T>::PtrWalker(const int initialCap) {
  cap = initialCap;

  begin = (T*) calloc(initialCap, sizeof(T));
  head = begin;
}

template <class T>
PtrWalker<T>::~PtrWalker() {
  if (begin) {
    free(begin);
  }
}

template <class T>
void PtrWalker<T>::rewind() {
  head = begin;
}

template <class T>
int PtrWalker<T>::pos() const {
  return head - begin;
}

template <class T>
void PtrWalker<T>::enlarge(const int offset) {
  cap += cap - 1;
  begin = (T*) realloc(begin, cap * sizeof(T));
  head = begin + offset;
}

template <class T>
bool PtrWalker<T>::atEnd() const {
  return pos() == cap;
}

template <class T>
T* PtrWalker<T>::getBegin() const {
  return begin;
}

template <class T>
T* PtrWalker<T>::getHead() const {
  return head;
}

template <class T>
T PtrWalker<T>::val() const {
  return *head;
}

template <class T>
T PtrWalker<T>::valf() {
  return *head++;
}

template <class T>
T PtrWalker<T>::fval() {
  return *++head;
}

template <class T>
T PtrWalker<T>::valb() {
  return *head--;
}

template <class T>
T PtrWalker<T>::bval() {
  return *--head;
}

template <class T>
void PtrWalker<T>::set(T value) {
  *head = value;
}

template <class T>
void PtrWalker<T>::setf(T value) {
  *head++ = value;
}

template <class T>
void PtrWalker<T>::fset(T value) {
  *++head = value;
}

template <class T>
void PtrWalker<T>::setb(T value) {
  *head-- = value;
}

template <class T>
void PtrWalker<T>::bset(T value) {
  *--head = value;
}

template <class T>
void PtrWalker<T>::operator++() {
  ++head;
}

template <class T>
void PtrWalker<T>::operator--() {
  --head;
}

template <class T>
void PtrWalker<T>::move(int distance) {
  head += distance;
}

template class PtrWalker<char>;
template class PtrWalker<int>;
template class PtrWalker<double>;

// Below instances are only for RecurPtrWalker
template class PtrWalker<char*>; 
