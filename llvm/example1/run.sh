#!/bin/bash
clang-16 -shared -o func_lister.so func_lister.cpp -fPIC -I /usr/include/llvm-c-16/ -I /usr/include/llvm-16/
clang-16 -O1 -fpass-plugin=./func_lister.so test.c -o test

