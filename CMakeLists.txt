cmake_minimum_required(VERSION 3.10)
project(numpy_for_cpp)

set(CMAKE_CXX_STANDARD 17)

# Add vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Add source files
add_executable(test_matrix tests/test_matrix.cpp src/matrix.cpp include/matrix.hpp)

# Link Google Test
find_package(GTest REQUIRED)
target_link_libraries(test_matrix PRIVATE GTest::gtest GTest::gtest_main)