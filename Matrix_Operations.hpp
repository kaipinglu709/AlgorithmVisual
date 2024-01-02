// MatrixOperations.hpp

#pragma once
#include <vector>
#include <stdexcept>

class MatrixOperations {
public:
    typedef std::vector<std::vector<double> > Matrix;

    // Add two matrices
    static Matrix add(const Matrix& a, const Matrix& b) {
        if (a.size() != b.size() || a[0].size() != b[0].size()) {
            throw std::invalid_argument("Matrices dimensions do not match for addition.");
        }
        Matrix result(a.size(), std::vector<double>(a[0].size(), 0));
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[i].size(); ++j) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        return result;
    }

    // Multiply two matrices
    static Matrix multiply(const Matrix& a, const Matrix& b) {
        if (a[0].size() != b.size()) {
            throw std::invalid_argument("Matrices dimensions do not match for multiplication.");
        }
        Matrix result(a.size(), std::vector<double>(b[0].size(), 0));
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < b[0].size(); ++j) {
                for (size_t k = 0; k < a[0].size(); ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    // Calculate determinant (assuming square matrix)
    static double determinant(const Matrix& matrix) {
        if (matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Matrix must be square to calculate determinant.");
        }
        return determinantHelper(matrix);
    }

private:
    static double determinantHelper(const Matrix& matrix) {
        const size_t n = matrix.size();
        if (n == 1) {
            return matrix[0][0];
        } else if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        } else {
            double det = 0.0;
            int sign = 1;
            for (size_t i = 0; i < n; ++i) {
                Matrix submatrix = getSubmatrix(matrix, 0, i);
                det += sign * matrix[0][i] * determinantHelper(submatrix);
                sign = -sign;
            }
            return det;
        }
    }

    static Matrix getSubmatrix(const Matrix& matrix, size_t excluding_row, size_t excluding_col) {
        Matrix submatrix(matrix.size() - 1, std::vector<double>(matrix.size() - 1));
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (i == excluding_row) continue;
            for (size_t j = 0, sub_j = 0; j < matrix[i].size(); ++j) {
                if (j == excluding_col) continue;
                submatrix[i < excluding_row ? i : i - 1][sub_j++] = matrix[i][j];
            }
        }
        return submatrix;
    }
};

