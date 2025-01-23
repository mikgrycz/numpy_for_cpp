cmake_minimum_required(VERSION 3.10)
project(numpy_for_cpp)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
add_executable(test_matrix tests/test_matrix.cpp)