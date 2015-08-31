#ifndef HEADER_MESSENGER_
#define HEADER_MESSENGER_

class Messenger {
private:
  static bool warnings;
  static bool verbose; // For now, always verbose (actually - unused)
  
  static int warningsCount;
  static char* parts[2];

  static const char* collectContext(); 
  static void print(const char* type, const char* context);
  static void reset();
  
public:
  static void cleanup();
  static void init(bool withWarnings);

  static void message(const char* text);
  static void details(const char* fmt, ...);
  
  static void printError();
  static void printWarning();
  static void printFatal();
};

#endif
