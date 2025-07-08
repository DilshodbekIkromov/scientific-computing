#include <iostream>
#include <vector>
#include <cassert>

// Function to multiply two matrices 
std::vector<std::vector<double>> Multiply(const std::vector<std::vector<double>>& A, 
                                          const std::vector<std::vector<double>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();
    
    assert(colsA == rowsB && "Matrix dimensions incompatible for multiplication");
    
    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0.0));
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

// 1. Multiply a vector and a matrix (vector * matrix)
std::vector<double> Multiply(const std::vector<double>& vec, 
                            const std::vector<std::vector<double>>& matrix) {
    int vecSize = vec.size();
    int matrixRows = matrix.size();
    int matrixCols = matrix[0].size();
    
    assert(vecSize == matrixRows && "Vector size must match matrix rows");
    
    std::vector<double> result(matrixCols, 0.0);
    
    for (int j = 0; j < matrixCols; j++) {
        for (int i = 0; i < vecSize; i++) {
            result[j] += vec[i] * matrix[i][j];
        }
    }
    
    return result;
}

// 2. Multiply a matrix and a vector (matrix * vector)
std::vector<double> Multiply(const std::vector<std::vector<double>>& matrix, 
                            const std::vector<double>& vec) {
    int matrixRows = matrix.size();
    int matrixCols = matrix[0].size();
    int vecSize = vec.size();
    
    assert(matrixCols == vecSize && "Matrix columns must match vector size");
    
    std::vector<double> result(matrixRows, 0.0);
    
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    
    return result;
}

// 3. Multiply a scalar and a matrix (scalar * matrix)
std::vector<std::vector<double>> Multiply(double scalar, 
                                          const std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = scalar * matrix[i][j];
        }
    }
    
    return result;
}

// 4. Multiply a matrix and a scalar (matrix * scalar)
std::vector<std::vector<double>> Multiply(const std::vector<std::vector<double>>& matrix, 
                                          double scalar) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    
    return result;
}

void PrintMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void PrintVector(const std::vector<double>& vec) {
    for (double val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<double>> matrix = {{1, 2, 3}, {4, 5, 6}};
    std::vector<double> vec1 = {1, 2};  // For vector * matrix
    std::vector<double> vec2 = {1, 2, 3}; // For matrix * vector
    double scalar = 2.0;
    
    std::cout << "Original matrix:" << std::endl;
    PrintMatrix(matrix);
    
    std::cout << "\nVector [1, 2] * Matrix:" << std::endl;
    auto result1 = Multiply(vec1, matrix);
    PrintVector(result1);
    
    std::cout << "\nMatrix * Vector [1, 2, 3]:" << std::endl;
    auto result2 = Multiply(matrix, vec2);
    PrintVector(result2);
    
    std::cout << "\nScalar 2.0 * Matrix:" << std::endl;
    auto result3 = Multiply(scalar, matrix);
    PrintMatrix(result3);
    
    std::cout << "\nMatrix * Scalar 2.0:" << std::endl;
    auto result4 = Multiply(matrix, scalar);
    PrintMatrix(result4);
    
    return 0;
}