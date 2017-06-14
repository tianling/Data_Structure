cmake_minimum_required(VERSION 3.6)
project(hashMap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        HashTable.cpp
        HashTable.h)

add_executable(hashMap ${SOURCE_FILES})