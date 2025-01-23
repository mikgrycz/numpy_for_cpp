#include <cassert>
#include <iostream>
#include "../include/matrix.hpp"

void test_addition() {
    Matrix<int> mat1{{1, 2}, {3, 4}};
    Matrix<int> mat2{{5, 6}, {7, 8}};
    Matrix<int> result = mat1 + mat2;

    assert(result(0, 0) == 6);
    assert(result(0, 1) == 8);
    assert(result(1, 0) == 10);
    assert(result(1, 1) == 12);

    std::cout << "test_addition passed!" << std::endl;
}

void test_multiplication() {
    Matrix<int> mat1{{1, 2}, {3, 4}};
    Matrix<int> mat2{{2, 0}, {1, 2}};
    Matrix<int> result = mat1 * mat2;

    assert(result(0, 0) == 4);
    assert(result(0, 1) == 4);
    assert(result(1, 0) == 10);
    assert(result(1, 1) == 8);

    std::cout << "test_multiplication passed!" << std::endl;
}

int main() {
    test_addition();
    test_multiplication();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}