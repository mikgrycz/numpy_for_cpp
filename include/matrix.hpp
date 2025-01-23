#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <functional>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    // Constructors
    Matrix(size_t rows, size_t cols, T init_value = T{});
    Matrix(std::initializer_list<std::initializer_list<T>> list);

    // Accessors
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;

    // Basic Operations
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> transpose() const;

    // Advanced Operations
    T determinant() const;
    Matrix<T> inverse() const;
    T norm(const std::string& type = "frobenius") const;
    Matrix<T> normalize(const std::string& axis = "matrix") const;

    // NumPy-like Operations
    Matrix<T> where(const Matrix<bool>& condition, const Matrix<T>& x, const Matrix<T>& y) const;
    Matrix<T> apply(std::function<T(T)> func) const;

    // Utility
    void print() const;

    size_t get_rows() const { return rows; }
    size_t get_cols() const { return cols; }

    static Matrix<T> zeros(size_t rows, size_t cols);
    static Matrix<T> empty(size_t rows, size_t cols);
    static Matrix<T> full(size_t rows, size_t cols, T value);
    Matrix<T> vstack(const Matrix<T>& other) const;
};

#include "../src/matrix.tpp"
#endif // MATRIX_HPP