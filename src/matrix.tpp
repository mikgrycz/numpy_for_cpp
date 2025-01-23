#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "../include/matrix.hpp"

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T init_value)
    : rows(rows), cols(cols), data(rows, std::vector<T>(cols, init_value)) {}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list)
    : rows(list.size()), cols(list.begin()->size()) {
    data.reserve(rows);
    for (const auto& row : list) {
        data.emplace_back(row);
    }
}

template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[row][col];
}

// Example: Matrix addition
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

// Matrix multiplication
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication");
    }
    Matrix<T> result(rows, other.cols, T{});
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

// Transpose
template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(j, i) = data[i][j];
        }
    }
    return result;
}

// Determinant (recursive for square matrices)
template <typename T>
T Matrix<T>::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Determinant can only be computed for square matrices");
    }
    if (rows == 1) {
        return data[0][0];
    }
    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    T det = 0;
    for (size_t p = 0; p < cols; ++p) {
        Matrix<T> submatrix(rows - 1, cols - 1);
        for (size_t i = 1; i < rows; ++i) {
            size_t col_index = 0;
            for (size_t j = 0; j < cols; ++j) {
                if (j == p) continue;
                submatrix(i - 1, col_index) = data[i][j];
                ++col_index;
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * data[0][p] * submatrix.determinant();
    }
    return det;
}

// NumPy-like zeros function
template <typename T>
Matrix<T> Matrix<T>::zeros(size_t rows, size_t cols) {
    return Matrix<T>(rows, cols, T{});
}

template <typename T>
Matrix<T> Matrix<T>::empty(size_t rows, size_t cols) {
    return Matrix<T>(rows, cols);
}

template <typename T>
Matrix<T> Matrix<T>::full(size_t rows, size_t cols, T value) {
    return Matrix<T>(rows, cols, value);
}

#endif // MATRIX_TPP
