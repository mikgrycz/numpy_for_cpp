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

void test_zeros() {
    Matrix<int> zero_matrix = Matrix<int>::zeros(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            assert(zero_matrix(i, j) == 0);
        }
    }
    std::cout << "test_zeros passed!" << std::endl;

}

void test_empty() {
    Matrix<int> empty_matrix = Matrix<int>::empty(2, 2);
    // Cannot assert values as they are uninitialized, but dimensions should be correct.
    assert(empty_matrix.get_rows() == 2);
    assert(empty_matrix.get_cols() == 2);
    std::cout << "test_empty passed!" << std::endl;

}

void test_full() {
    Matrix<int> full_matrix = Matrix<int>::full(2, 2, 5);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            assert(full_matrix(i, j) == 5);
        }
    }
    std::cout << "test_fill passed!" << std::endl;

}

// void test_vstack() {
//     Matrix<int> mat1 = Matrix<int>::full(2, 2, 1);
//     Matrix<int> mat2 = Matrix<int>::full(2, 2, 2);
//     Matrix<int> vstacked = mat1.vstack(mat2);

//     assert(vstacked.get_rows() == 4);
//     assert(vstacked.get_cols() == 2);

//     for (size_t i = 0; i < 2; ++i) {
//         for (size_t j = 0; j < 2; ++j) {
//             assert(vstacked(i, j) == 1);
//         }
//     }
//     for (size_t i = 2; i < 4; ++i) {
//         for (size_t j = 0; j < 2; ++j) {
//             assert(vstacked(i, j) == 2);
//         }
//     }
// }

int main() {
    test_addition();
    test_multiplication();
    test_zeros();
    test_empty();
    test_full();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}