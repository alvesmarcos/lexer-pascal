cmake_minimum_required(VERSION 3.6)
project(minicc)

# ref http://llvm.org/docs/CMake.html
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 14)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(SOURCE_FILES src/lex/scanner.cc include/lex/scanner.h include/lex/types.h)

# Create a library called "pascc" which includes the source files.
add_executable(pascc ${SOURCE_FILES})
