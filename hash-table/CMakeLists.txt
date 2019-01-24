cmake_minimum_required(VERSION 3.6)
project(hash_table)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(hash_table ${SOURCE_FILES})