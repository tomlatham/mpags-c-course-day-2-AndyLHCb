# - Main CMake build for MPAGS-cipher
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)



set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(mpags-cipher
 mpags-cipher.cpp
 MPAGSCipher/TransformChar.cpp
 MPAGSCipher/TransformChar.hpp
 MPAGSCipher/DealingWithFiles.cpp
 MPAGSCipher/DealingWithFiles.hpp
 MPAGSCipher/CommandLine.cpp
 MPAGSCipher/CommandLine.hpp
 MPAGSCipher/RunCaesarCipher.hpp
 MPAGSCipher/RunCaesarCipher.cpp)

target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wfatal-errors")

target_include_directories(mpags-cipher
 PRIVATE MPAGSCipher
 )
