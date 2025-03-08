#!/bin/bash
clang-16 -shared -o lib.so main.cpp -fPIC  -I /usr/include/llvm-c-16/ -I /usr/include/llvm-16/
clang-16 -S -emit-llvm test.c -o test.ll
opt-16 -load-pass-plugin ./lib.so -passes=run-pass -disable-output test.ll