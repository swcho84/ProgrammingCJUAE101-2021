cmake_minimum_required(VERSION 3.13)  # CMake version check
project(01_hello_world)               # Create project
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES  main.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(01_hello_world ${SOURCE_FILES})