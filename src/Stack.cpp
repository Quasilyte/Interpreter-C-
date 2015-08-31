#include "Stack.hpp"

#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"

template <class T, class Ptr> 
Stack<T, Ptr>::Stack(int initialCap):
  elems(initialCap) {}

template <class T, class Ptr> 
T Stack<T, Ptr>::top() const {
  return elems.val();
}

template <class T, class Ptr> 
T Stack<T, Ptr>::pop() {
  return elems.bval();
}

template <class T, class Ptr> 
void Stack<T, Ptr>::push(T value) {
  ensureCap(); elems.setf(value);
}

template <class T, class Ptr> 
void Stack<T, Ptr>::ensureCap() {
  if (elems.atEnd()) {
    elems.enlarge(elems.pos());
  }
}

template class Stack<int, PtrWalker<int>>;
template class Stack<double, PtrWalker<double>>;
template class Stack<char*, RecurPtrWalker<char*>>;
