#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "matrix.hpp"

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

// NumPy-like where function
template <typename T>
Matrix<T> Matrix<T>::where(const Matrix<bool>& condition, const Matrix<T>& x, const Matrix<T>& y) const {
    if (condition.get_rows() != rows || condition.get_cols() != cols ||
        x.get_rows() != rows || x.get_cols() != cols ||
        y.get_rows() != rows || y.get_cols() != cols) {
        throw std::invalid_argument("All matrices must have the same dimensions for where function");
    }
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = condition(i, j) ? x(i, j) : y(i, j);
        }
    }
    return result;
}

// Apply a function element-wise
template <typename T>
Matrix<T> Matrix<T>::apply(std::function<T(T)> func) const {
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = func(data[i][j]);
        }
    }
    return result;
}

#endif // MATRIX_TPP