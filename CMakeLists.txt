cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C++_COMPILER clang++)
project(msladkov-llp-lab2 LANGUAGES CXX)



set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)