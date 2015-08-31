#include "header/Messenger.hpp"

// #TODO: refactor this!

#include <string>
#include <string.h>
#include <stdarg.h>
#include <iostream>

#include "util/colors.hpp"

#define CLASS_NAME Messenger
#include "util/class_codegen.hpp"

bool CLASS_NAME::verbose = true;
bool CLASS_NAME::warnings;
int CLASS_NAME::warningsCount = 0;
char* CLASS_NAME::parts[2];

#define MESSAGE_INDEX 0
#define DETAILS_INDEX 1
#define PART_MAX_LEN 160

DEFN(void, init(bool withWarnings)) {
  warnings = withWarnings;
  
  parts[MESSAGE_INDEX] = new char[PART_MAX_LEN];
  parts[DETAILS_INDEX] = new char[PART_MAX_LEN];
}

DEFN(void, cleanup()) {
  delete[] parts[MESSAGE_INDEX];
  delete[] parts[DETAILS_INDEX];
}

DEFN(void, reset()) {
  parts[MESSAGE_INDEX][0] = '\0';
  parts[DETAILS_INDEX][0] = '\0';
}

DEFN(void, message(const char* text)) {
  strcpy(parts[MESSAGE_INDEX], text);
}

DEFN(void, details(const char* fmt, ...)) {
  va_list args;
  va_start(args, fmt);

  vsprintf(parts[DETAILS_INDEX], fmt, args);

  va_end(args);
}

DEFN(const char*, collectContext()) {
  return "context coming soon..."; // Mockup
}

DEFN(void, print(const char* type, const char* context)) {
  std::string text;

  text += " { ";
  text += type;
  text += " }\n";

  if (context) {
    text += BOLD("[context] ");
    text += context;
    text += "\n";
  }

  text += BOLD("[message] ");
  text += parts[MESSAGE_INDEX];
  text += "\n";

  if (*parts[DETAILS_INDEX]) {
    text += BOLD("[details] ");
    text += parts[DETAILS_INDEX];
    text += "\n";
  }

  std::cout << text;
}

DEFN(void, printError()) {
  print(RED("execution error"), collectContext());
  
  exit(EXIT_SUCCESS); // Expected error
}

DEFN(void, printWarning()) {
  if (warnings) {
    print(VIOLET("warning"), collectContext());
  
    reset();
  }

  ++warningsCount;
}

DEFN(void, printFatal()) {
  print(RED("fatal error"), nullptr); // Context is not available...
  
  exit(EXIT_FAILURE); // Unexpected error
}

  
