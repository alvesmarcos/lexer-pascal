cmake_minimum_required(VERSION 3.6)
project(pascalzim)

# ref http://llvm.org/docs/CMake.html
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 14)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(SOURCE_FILES test/main.cc src/lex/scanner.cc include/lex/scanner.h include/lex/types.h src/lex/types.cc)

# Create a library called "pascalzim" which includes the source files.
add_executable(pascalzim ${SOURCE_FILES})

# ref https://github.com/alvesmarcos/minicc
# copia arquivos de teste para diretorio de build
add_custom_command(TARGET pascalzim POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/test/files-pas/lex1.pas
        ${CMAKE_CURRENT_BINARY_DIR})
