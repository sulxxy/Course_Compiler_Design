CXXFLAGS = -rdynamic $(shell llvm-config-3.8 --cxxflags) -g -O3
CXX = clang++-3.8

.PHONY: all clean

all: Parser.out

Parser.out: Parser.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	rm -f *.out
