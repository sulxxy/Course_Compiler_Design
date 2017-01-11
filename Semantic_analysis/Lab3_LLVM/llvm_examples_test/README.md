# LLVM examples for the course "Compiler Design"

The archive contains a list of LLVM pass examples you can browse, compile and use with the LLVM optimizer (*.cpp), three simple C test file (*.c), and a Makefile to produce a *.so file for each given LLVM pass.


# Getting started with LLVM

You can generate LLVM IR (also called bitcode) with the following command:
> clang example1.c -o example1.bc -c -emit-llvm

you can quickly run it by using the LLVM interpreter:
> lli example1.bc

The bitcode can be browsed by using the LLVM disassembler
> llvm-dis < example1.bc

Instead of using an interpreter, you can actually compile the bytecode with the LLVM backend compiler, using the following:
> llc example1.bc -o example1.s

> gcc example1.s -o example1.native

> ./example1.native

The produced assembly can be inspected with:
> cat example1.s


To start, try these commands with all the provided input C files; also try to write your C file and see what bytecode is generated.

# LLVM IR: Quick Overview

> ; for comments

> @ for global identifiers

> % for local identifiers

> iN integer type of N bit

> [128 x i8] array of 128 int8

> constant c”string example\00”

> define i32 @main(){ } function definition

> declare i32 puts(i8*) function declaration

> ret i32 0 return statement

> ret void return statement

> call i32 @puts(i8* %arg1) func. call 

getelemenptr step over the pointer (read the page linked in the last section about GEP)


# Using the LLVM Optimizer

The next step is to use the bitcode LLVM optimizer, e.g. using the following commands:
> opt example1.bc -S 

> opt example1.bc > example1_opt.bc

> opt example1.bc -S -O1 -stats

> opt example1.bc -S -O3 -stats

> opt example1.bc -f -O3 -stats


# Implementing an LLVM compiler pass

The following files are implementations of LLVM passes:
> MyBlockPass.cpp

> MyFunctionPass.cpp

> MyLoopPass.cpp

> MyModulePass.cpp

> MyRegionPass.cpp

> MySCCPass.cpp

you can compile all of them by simply using the given Makefile:
> make

After generationg the IR, as we have seen before:
> clang example1.c -c -emit-llvm

you will have both IR and passes availalbe; then you can run the pass on the IR using the optimizer:
> opt -load ./MyModulePass.so -function-info example1.bc -o example1.opt

Also try the following parameter for opt: -analyze

Note that "function-info" is the name we used in MyModulePass to register the pass to the PassManager.
Different passes (registered differently) may therefore require a different parameter.

Run the optimizer with all the given passes and see what do they do. You are encouraged to modify and test different input in order to understand how LLVM works.


# LLVM important links
[LLVM commands](http://llvm.org/docs/CommandGuide)

[Getting started](http://llvm.org/docs/GettingStarted.html#an-example-using-the-llvm-tool-chain)

[GEP Instruction]( http://llvm.org/docs/GetElementPtr.html)

[Value class](http://llvm.org/docs/doxygen/html/classllvm_1_1Value.html)

[Pass class](http://llvm.org/doxygen/classllvm_1_1Pass.html)

[Writing an LLVM Pass](http://llvm.org/docs/WritingAnLLVMPass.html)

[LLVM’s Analysis and Transform Passes](http://llvm.org/docs/Passes.html)
