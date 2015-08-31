#include "header/RecurPtrWalker.hpp"

#include <stdlib.h>

#define TMPL_ARGS class T
#define TMPL_TYPENAMES T
#define CLASS_NAME RecurPtrWalker
#include "util/class_codegen.hpp"

// We need to use `this' to perform two-phase name lookup.
// In other words, removing `this' will break the compilation.
DTOR() {
  this->rewind();

  for (int i = 0; i < this->cap; ++i) {
    if (*this->p) 
      free(*this->p);
    
    ++this->p;
  }
}

PERMIT(char*);
