#include "echo.hpp"

#include <string.h>
#include <stdarg.h>
#include <iostream>

#include "config/colors.hpp"

namespace echo {
  bool verbose = true;
  
  bool withWarnings = true;
  int warningsCount = 0;

  const char* messageText;
  const char* detailsFmt;
  va_list detailsData;

  void reset() {
    messageText = nullptr;

    if (detailsFmt) {
      detailsFmt = nullptr;
      va_end(detailsData);
    }
  }

  void message(const char* text) {
    messageText = text;
  }

  void details(const char* fmt, ...) {
    detailsFmt = fmt;
    va_start(detailsData, fmt);
  }

  void printSection(const char* section) {
    printf(BOLD("[%s] "), section);
  }

  void printContext() {
    printSection("context");
    printf("coming soon!\n");
  }

  void print(const char* heading, bool withContext) {
    printf(" { %s } \n", heading);
    
    if (withContext) {
      printContext();
    }

    printSection("message");
    printf("%s\n", messageText);

    if (detailsFmt) {
      printSection("details");
      vprintf(detailsFmt, detailsData);
      printf("\n");
    }
  }

  void printAsError() {
    print(RED("execution error"), true);
    
    exit(EXIT_SUCCESS); // Expected error
  }

  
  void printAsWarning() {
    if (withWarnings) {
      print(VIOLET("warning"), true);
      
      reset();
    }

    ++warningsCount;
  }

  void printAsFatal() {
    print(RED("fatal error"), false); // Context is not available...
  
    exit(EXIT_FAILURE); // Unexpected error
  }
}


