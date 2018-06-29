cmake_minimum_required(VERSION 3.10)
project(Marvel)

set(CMAKE_CXX_STANDARD 11)

add_executable(Marvel main.cpp sys.h vendor/cipher.cpp vendor/cipher.h)