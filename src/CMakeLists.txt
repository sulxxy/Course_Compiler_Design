cmake_minimum_required(VERSION 3.5.0)

SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
SET(llvm_config "llvm-config-3.8")
SET(flag "--cxxflags")
execute_process(COMMAND ${llvm_config} ${flag} OUTPUT_VARIABLE llvm_cxxflags)

# remove \n
string(REGEX REPLACE "\n" "" llvm_cxxflags ${llvm_cxxflags})

SET(CMAKE_CXX_FLAGS ${llvm_cxxflags})

add_executable(lexer lexer.cpp)
add_executable(parser parser.cpp)


