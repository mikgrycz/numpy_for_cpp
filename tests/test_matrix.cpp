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

void test_transpose() {
    Matrix<int> mat{{1, 2, 3}, {4, 5, 6}};
    Matrix<int> transposed = mat.transpose();

    assert(transposed.get_rows() == 3);
    assert(transposed.get_cols() == 2);
    assert(transposed(0, 0) == 1);
    assert(transposed(1, 0) == 2);
    assert(transposed(2, 0) == 3);

    std::cout << "test_transpose passed!" << std::endl;
}


void test_zeros() {
    Matrix<int> zero_matrix = Matrix<int>::zeros(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            assert(zero_matrix(i, j) == 0);
        }
    }
    std::cout << "test_zeros passed!" << std::endl;
}

void test_full() {
    Matrix<int> full_matrix = Matrix<int>::full(2, 3, 7);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            assert(full_matrix(i, j) == 7);
        }
    }
    std::cout << "test_full passed!" << std::endl;
}

void test_vstack() {
    Matrix<int> mat1{{1, 2}};
    Matrix<int> mat2{{3, 4}};
    Matrix<int> vstacked = mat1.vstack(mat2);

    assert(vstacked.get_rows() == 2);
    assert(vstacked.get_cols() == 2);
    assert(vstacked(0, 0) == 1);
    assert(vstacked(1, 0) == 3);

    std::cout << "test_vstack passed!" << std::endl;
}

void test_apply() {
    Matrix<int> mat{{1, 2}, {3, 4}};
    Matrix<int> squared = mat.apply([](int x) { return x * x; });

    assert(squared(0, 0) == 1);
    assert(squared(0, 1) == 4);
    assert(squared(1, 0) == 9);
    assert(squared(1, 1) == 16);

    std::cout << "test_apply passed!" << std::endl;
}

int main() {
    test_addition();
    test_multiplication();
    test_transpose();
    test_zeros();
    test_full();
    test_vstack();
    test_apply();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
