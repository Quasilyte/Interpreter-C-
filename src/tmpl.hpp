#ifndef TMPL_
#define TMPL_

// TMPL_ARGS -- angle brackets type enumeration
// TMPL_TYPENAMES -- template types as part of definition signature
// TMPL_CLASS_NAME -- name of class those methods we are defining

#define TEMPLATE template<TMPL_ARGS>
#define CLASS TMPL_CLASS_NAME<TMPL_TYPENAMES>

#define TMPL(ret, name) TEMPLATE ret CLASS::name
#define CTOR(...) TEMPLATE CLASS::TMPL_CLASS_NAME(__VA_ARGS__)
#define DTOR() TEMPLATE CLASS::~TMPL_CLASS_NAME()

#define INST(...) template class TMPL_CLASS_NAME<__VA_ARGS__>

#endif
