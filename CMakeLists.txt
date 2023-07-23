cmake_minimum_required(VERSION 3.13.4)
project(Skeleton)

# support C++17 features used by LLVM 16.0.6
set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)
include(AddLLVM)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(skeleton)  # Use your pass name here.
