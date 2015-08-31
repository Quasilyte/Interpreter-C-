## Compilation settings
CC=g++
CFLAGS=-std=c++14 -Wall -fno-implicit-templates
BIN=bin/interpreter

## Sources
SRC=src/util/CstrSlice.cpp \
    src/util/CstrRange.cpp \
    src/Scanner.cpp \
    src/Messenger.cpp \
    src/TypeConv.cpp \
    src/ByteCode.cpp \
    src/PtrWalker.cpp \
    src/RecurPtrWalker.cpp \
    src/Stack.cpp \
    src/MultiStack.cpp \
    src/Compiler.cpp \
    src/Evaluator.cpp \
    main.cpp

## Targets and dependencies
# Default
all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

# Highest safe optimizations
bench:
	$(CC) $(CFLAGS) -O2 $(SRC) -o $(BIN)

# For debug mostly
raw:
	$(CC) $(CFLAGS) -O0 $(SRC) -o $(BIN)
