# Generate the LLVM IR
clang-16 -S -emit-llvm test.c -o test.ll

# Print Control-Flow Graph to 'dot' file.
opt-16 -dot-cfg -disable-output -enable-new-pm=0 test.ll

# Generate an image from the 'dot' file
dot -Tpng -o img.png .main.dot