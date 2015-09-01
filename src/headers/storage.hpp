#ifndef HEADERS_STORAGE_
#define HEADERS_STORAGE_

#include "config/types.hpp"

// Language has stack-like temporal data storage
namespace storage {
  void push(inum v);
  void push(fnum v);
  void push(char* v);
  
  char* popStr();    
}

#endif
