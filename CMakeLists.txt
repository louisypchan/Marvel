cmake_minimum_required(VERSION 3.10)
project(Marvel)

set(CMAKE_CXX_STANDARD 11)

#openssl
set(INC_DIR D:\\OpenSSL-Win64\\include)
set(LINK_DIR D:\\OpenSSL-Win64\\lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

link_libraries(libcrypto libssl)

add_executable(Marvel main.cpp sys.h vendor/cipher.cpp vendor/cipher.h core/sign.cpp core/sign.h)

target_link_libraries(Marvel libcrypto libssl)