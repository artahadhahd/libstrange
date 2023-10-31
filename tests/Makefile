CSTD=-std=c11
CXXSTD=-std=c++17
WARNINGS=-Wall -Wextra -Wpedantic
LINK=-L../bin -lstrange
INCLUDE=-I. -I../include
CFLAGS=$(WARNINGS) $(LINK) $(INCLUDE) -g -O3

all: CTARGET CXXTARGET

CTARGET:
	gcc C/main.c -o bin/cTest.out $(CFLAGS) $(CSTD)

CXXTARGET:
	g++ CXX/main.cpp -o bin/CppTest.out $(CFLAGS) $(CXXSTD)