# llvm-pass-skeleton

A LLVM pass skeleton using new pass manager.
It's for LLVM 16.0.6.

Build:
```
$ cd llvm-pass-skeleton
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ..
```

Run:
```
$ cd test
$ clang -emit-llvm -S test.c -o test.ll
$ opt -disable-output -load-pass-plugin=../build/skeleton/SkeletonPass.so -passes="skeleton-pass" test.ll
```
