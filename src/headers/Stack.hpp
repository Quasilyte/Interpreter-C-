#ifndef HEADER_STACK_
#define HEADER_STACK_

template <class T, class Ptr> class Stack {
private:
  Ptr elems;
  
public:
  Stack(int initialCap);
  
  T top() const;
  T pop();
  void push(T value);

  // Check the available size, grow buffer if needed
  void ensureCap();
};

#endif
