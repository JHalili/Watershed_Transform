cmake_minimum_required (VERSION 3.0)
project (SELF_DUAL_MORPHOLOGICAL_RECONSTRUCTION)

find_package(PkgConfig REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(main main.cpp csv.cpp watershed.cpp)
