## Compilation settings
CC=g++
CFLAGS=-std=c++11 -Wall -fno-implicit-templates
BIN=bin/interpreter

## Sources
SRC=src/typeconv.cpp \
    src/PtrWalker.cpp \
    src/RecurPtrWalker.cpp \
    src/Stack.cpp \
    src/MultiStack.cpp \
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
