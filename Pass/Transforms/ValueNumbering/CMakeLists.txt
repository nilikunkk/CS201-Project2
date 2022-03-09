set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.9)
SET (CMAKE_CXX_FLAGS "-fno-rtti -fPIC")

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

#setting up the build environment
#This build script specifies that ValueNumbering.cpp file in the current directory 
#is to be compiled and linked into a shared object $(LEVEL)/lib/LLVMValueNumberingPass.so 
#that can be dynamically loaded by the opt tool via its -load option. 
add_library(LLVMValueNumberingPass MODULE ValueNumbering.cpp)

set_target_properties(LLVMValueNumberingPass PROPERTIES COMPILE_FLAGS "-D__GLIBCXX_USE_CXX11_ABI=0 ")
#SET(CMAKE_MODULE_LINKER_FLAGS "-undefined dynamic_lookup")

target_link_libraries(LLVMValueNumberingPass)


