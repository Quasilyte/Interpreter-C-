#include "RecurPtrWalker.hpp"

#include <stdlib.h>
#include <stdio.h>

// We need to use `this' to perform two-phase name lookup.
// In other words, removing `this' will break the compilation.
template <class T>
RecurPtrWalker<T>::~RecurPtrWalker() {
  this->rewind();

  for (int i = 0; i < this->cap; ++i) {
    if (*this->head) {
      free(*this->head);
    }
    
    ++this->head;
  }
}

template class RecurPtrWalker<char*>;
