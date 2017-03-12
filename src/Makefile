CXXFLAGS = -g -O3 `llvm-config-3.8 --cxxflags --ldflags --system-libs --libs core`
CXX = clang++-3.8

.PHONY: all clean

all: Parser.out

Parser.out: Parser.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	rm -f *.out
