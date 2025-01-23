# NumPy for C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)  
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)  
![Google Test](https://img.shields.io/badge/Google%20Test-4285F4?style=for-the-badge&logo=googletest&logoColor=white)  
![GitHub Actions](https://img.shields.io/badge/GitHub%20Actions-2088FF?style=for-the-badge&logo=github-actions&logoColor=white)

## Overview

**NumPy for C++** is a high-performance library that brings the core functionalities of **NumPy**, the widely used Python library for scientific computing, to the C++ programming language. It offers a range of tools for matrix operations, linear algebra, and other numerical computations, allowing C++ developers to efficiently perform complex mathematical tasks.

## Features

- **Matrix Operations**: Supports basic matrix operations such as addition, subtraction, multiplication, and more.
- **Linear Algebra**: Provides functions for solving linear equations, computing eigenvalues and eigenvectors, and more.
- **Numerical Methods**: Includes various numerical methods for scientific computing, similar to the ones in NumPy.

## Technologies

- **C++**: Core language for the library's implementation.
- **CMake**: Build system for managing the project.
- **Google Test**: Unit testing framework for C++.
- **GitHub Actions**: Continuous integration (CI) and continuous deployment (CD) pipeline for automated testing and deployment.

## Getting Started

### Prerequisites

To get started with the library, ensure you have the following tools installed:

- **C++ Compiler**: A C++ compiler such as `g++` or `clang`.
- **CMake**: A cross-platform build system for managing the build process.
- **vcpkg**: A package manager for C++ libraries.

### Installation

Follow these steps to install and build the library:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/numpy_for_cpp.git
   cd numpy_for_cpp
   ```

2. **Install dependencies using vcpkg**:
   - Clone the `vcpkg` repository:
     ```bash
     git clone https://github.com/microsoft/vcpkg.git
     cd vcpkg
     ```
   - Bootstrap `vcpkg`:
     ```bash
     .\bootstrap-vcpkg.bat
     ```
   - Install required dependencies:
     ```bash
     .\vcpkg install gtest
     ```

3. **Build the project**:
   - Create a build directory:
     ```bash
     mkdir build
     cd build
     ```
   - Configure the project using CMake:
     ```bash
     cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
     ```
   - Build the project:
     ```bash
     cmake --build .
     ```

4. **Run tests**:
   - To run the tests, use:
     ```bash
     ./tests/test_matrix
     ```

## Usage

Once the library is built, you can start using it in your C++ projects. Include the necessary headers and link the library in your CMake configuration.

```cpp
#include "numpy_for_cpp/matrix.h"

int main() {
    // Example of matrix creation and operation
    Matrix A(3, 3);
    A.fill(1.0);
    Matrix B(3, 3);
    B.fill(2.0);
    Matrix C = A + B;
    C.print();
    return 0; 
}
```
