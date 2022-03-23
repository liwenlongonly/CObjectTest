cmake_minimum_required(VERSION 3.21)
project(CObjectTest C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/)

file(GLOB _Source   ${PROJECT_SOURCE_DIR}/*.*)

add_executable(CTest ${_Source} log.c log.h)
