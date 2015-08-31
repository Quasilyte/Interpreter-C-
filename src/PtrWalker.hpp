#ifndef PTR_WALKER_
#define PTR_WALKER_

/**
 * Description:
 * Lightweight "smart" pointer, which makes it easy to
 * iterate over underlying pointer while modifying its values.
 * It supports resizing, but does not perform it, so the using
 * code should invoke `enlarge' explicitly.
 * This is merely a wrapper to T* begin, T* current idiom
 * with nice methods like already mentioned `enlarge'.
 **
 * Perfomance:
 * The tiniest overhead is payed off by the convenience.
 * Definitions are mostly one-liner, so compiler could inline them all.
 **
 * Warning:
 * Associated buffer is cleared upon destruction, but NOT recursively,
 * so it is unsafe to store T, where T is a pointer of raw type.
 * In this cases, RecurPtrWalker should be used instead.
 */
template <class T> class PtrWalker {
protected:
  int cap;
  T* begin;
  T* head;

public:
  PtrWalker(T* initializer, int initializerSize);
  PtrWalker(const int initialCap);
  ~PtrWalker();
  
  // Reset `head' to the `begin'
  void rewind();

  // Current offset
  int pos() const;

  // Increase buffer capacity by `cap * 2 - 1'
  void enlarge(const int offset);

  // If returns true, then it is UB to move further.
  bool atEnd() const;

  T* getBegin() const;
  T* getHead() const;
  
  // Dereferencing current (head) element
  T val() const;
  T valf();
  T fval();
  T valb();
  T bval();

  // Modifiying value which is pointed by a head
  void set(T value);
  void setf(T value);
  void fset(T value);
  void setb(T value);
  void bset(T value);

  // Move head back and forth
  void operator++();
  void operator--();
  void move(int distance);
};

#endif
