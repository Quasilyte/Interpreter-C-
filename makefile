## Project settings
INC=src/headers/

## Compilation settings
CC=g++
CFLAGS=-I$(INC) -std=c++14 -Wall -fno-implicit-templates
BIN=bin/interpreter

## Sources
SRC=src/util/CstrSlice.cpp \
    src/util/CstrRange.cpp \
    src/scan.cpp \
    src/echo.cpp \
    src/typeconv.cpp \
    src/bytecode.cpp \
    src/PtrWalker.cpp \
    src/RecurPtrWalker.cpp \
    src/Stack.cpp \
    src/storage.cpp \
    src/compilation.cpp \
    src/evaluation.cpp \
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
