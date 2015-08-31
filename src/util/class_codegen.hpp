#ifndef CODEGEN_CLASS_
#define CODEGEN_CLASS_

// TMPL_ARGS -- angle brackets type enumeration
// TMPL_TYPENAMES -- template types as part of definition signature
// CLASS_NAME -- name of class those methods we are defining

#ifdef TMPL_ARGS
  // Class template
  #define TEMPLATE template<TMPL_ARGS>
  #define TMPL_CLASS_NAME CLASS_NAME<TMPL_TYPENAMES>

  #define DEFN(ret, name) TEMPLATE ret TMPL_CLASS_NAME::name
  #define CTOR(...) TEMPLATE TMPL_CLASS_NAME::CLASS_NAME(__VA_ARGS__)
  #define DTOR() TEMPLATE TMPL_CLASS_NAME::~CLASS_NAME()

  // Instantiate template explicitly
  #define PERMIT(...) template class CLASS_NAME<__VA_ARGS__>
#else
  // Ordinary class
  #define DEFN(ret, name) ret CLASS_NAME::name
  #define CTOR(...) CLASS_NAME::CLASS_NAME(__VA_ARGS__)
  #define DTOR() CLASS_NAME::~CLASS_NAME()
#endif

#endif
