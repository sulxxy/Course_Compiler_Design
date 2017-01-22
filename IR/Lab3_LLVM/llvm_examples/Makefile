CXXFLAGS = -rdynamic $(shell llvm-config --cxxflags) -g -O0 -std=c++0x

all: MyModulePass.so MyFunctionPass.so MyBlockPass.so MyLoopPass.so MyRegionPass.so MySCCPass.so pass.so

%.so: %.o
	$(CXX) $(CXXFLAGS) -dylib -shared -fPIC  $^ -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c  $^ -o $@

clean:
	rm -f *.o *~ *.so



