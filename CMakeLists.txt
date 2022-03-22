cmake_minimum_required(VERSION 3.21)
project(CObjectTest C)

set(CMAKE_C_STANDARD 99)

add_executable(CTest main.c struct_file.c struct_file.h animal.c animal.h dog.c dog.h)
