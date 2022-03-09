#!/bin/bash
cd ../Pass/build/
cmake -DCMAKE_BUILD_TYPE=Release ../Transforms/ValueNumbering
make -j4
cd -
clang -S -fno-discard-value-names -emit-llvm test.c -o test.ll
opt -load ../Pass/build/libLLVMValueNumberingPass.so -enable-new-pm=0 -ValueNumbering test.ll
