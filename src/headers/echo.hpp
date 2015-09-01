#ifndef HEADERS_ECHO_
#define HEADERS_ECHO_
  
namespace echo {
  void message(const char* text);
  void details(const char* fmt, ...);

  void printAsError();
  void printAsWarning();
  void printAsFatal();
}

#endif
