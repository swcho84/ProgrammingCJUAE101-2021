cmake_minimum_required(VERSION 3.0.0)
project(13_class_exercise_vector VERSION 0.1.0)
add_compile_options(-std=c++11)
include_directories(include)
add_executable(main main.cpp include/point2d.h include/point3d.h include/vector_calculation.h include/vector2d.h lib/vector2d.cpp include/vector3d.h lib/vector3d.cpp)

