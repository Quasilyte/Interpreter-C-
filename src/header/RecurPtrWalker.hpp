#ifndef HEADER_RECUR_PTR_WALKER_
#define HEADER_RECUR_PTR_WALKER_

#include "PtrWalker.hpp"

/**
 * Description:
 * See `PtrWalker'.
 * The only difference in that this one can safely be used for 
 * pointer arrays, so instantiation with <char*> is OK.
 */
template <class T> struct RecurPtrWalker : public PtrWalker<T> {
  using PtrWalker<T>::PtrWalker;
  
  ~RecurPtrWalker();
};

#endif
