#include "storage.hpp"

#include "config/runtime.hpp"
#include "typeconv.hpp"
#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"
#include "Stack.hpp"

namespace storage {
  PtrWalker<char> types(DATA_STACK_SIZE * 2);
  Stack<inum, PtrWalker<inum>> ints(DATA_STACK_SIZE);
  Stack<fnum, PtrWalker<fnum>> doubles(DATA_STACK_SIZE);
  Stack<char*, RecurPtrWalker<char*>> strings(DATA_STACK_SIZE);

  void push(inum v) {
    types.setf('i');
    ints.push(v);
  }

  void push(fnum v) {
    types.setf('f');
    doubles.push(v);
  }
  
  void push(char* v) {
    types.setf('s');
    strings.push(v);
  }
  
  char* popStr() {
    switch (types.bval()) {
    case 'i': return typeconv::toCstr(ints.pop());
    case 's': return strings.pop();
      // Should never happend
    default: throw new int(0);
    }
  }    
}
