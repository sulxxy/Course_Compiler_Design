# version
cmake_minimum_required(VERSION 3.5.0)

# set compiler
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

# set cxxflags
execute_process(COMMAND llvm-config-3.8 --cxxflags OUTPUT_VARIABLE llvm_cxxflags)
string(REGEX REPLACE "\n" " " llvm_cxxflags ${llvm_cxxflags})
SET(CMAKE_CXX_FLAGS ${llvm_cxxflags})

# set linker
SET(CMAKE_LINK_LIBRARY_FLAG "-L/usr/lib/llvm-3.8/lib -lLLVMCore -lLLVMSupport -lrt -ldl -ltinfo -lpthread -lz -lm")

# targets
#add_executable(test1 test.cpp)
#add_executable(lexer lexer.cpp lexer.h)
add_executable(parser parser.cpp)
target_link_libraries(parser ${CMAKE_LINK_LIBRARY_FLAG})

