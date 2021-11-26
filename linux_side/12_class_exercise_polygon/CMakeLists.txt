cmake_minimum_required(VERSION 3.0.0)
project(12_class_exercise_polygon VERSION 0.1.0)
add_compile_options(-std=c++11)
include_directories(include)
add_executable(main main.cpp include/polygon.h include/circle.h lib/circle.cpp include/triangle.h lib/triangle.cpp include/rectangle.h lib/rectangle.cpp)

