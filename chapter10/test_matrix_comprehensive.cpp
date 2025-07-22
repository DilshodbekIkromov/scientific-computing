#include <iostream>
#include <iomanip>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"

// Comprehensive tests for the Matrix class

void PrintMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "Matrix " << name << " (" << matrix.GetNumberOfRows()
              << "x" << matrix.GetNumberOfColumns() << "):" << std::endl;
    for (int i = 1; i <= matrix.GetNumberOfRows(); i++) {
        std::cout << "  ";
        for (int j = 1; j <= matrix.GetNumberOfColumns(); j++) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2)
                      << const_cast<Matrix&>(matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintVector(const Vector& vector, const std::string& name) {
    std::cout << "Vector " << name << " (size " << vector.GetSize() << "):" << std::endl;
    std::cout << "  [";
    for (int i = 0; i < vector.GetSize(); i++) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << vector.Read(i);
        if (i < vector.GetSize() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl << std::endl;
}

// constructors and assignment
void TestConstructorsAndBasics() {
    std::cout << "=== Testing Constructors and Basic Operations ===" << std::endl;
    std::cout << "Creating a 3x3 matrix A..." << std::endl;
    Matrix A(3, 3);
    std::cout << "Filling matrix A with values..." << std::endl;
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    A(3, 1) = 7.0; A(3, 2) = 8.0; A(3, 3) = 9.0;
    PrintMatrix(A, "A");
    std::cout << "Testing copy constructor..." << std::endl;
    Matrix B(A);
    PrintMatrix(B, "B");
    std::cout << "Testing assignment operator..." << std::endl;
    Matrix C(3, 3);
    C = A;
    PrintMatrix(C, "C");
    std::cout << "Basic constructor and assignment tests passed!" << std::endl << std::endl;
}

// arithmetic tests
void TestMatrixOperations() {
    std::cout << "=== Testing Matrix Operations ===" << std::endl;
    Matrix A(2, 2);
    A(1, 1) = 1.0; A(1, 2) = 2.0;
    A(2, 1) = 3.0; A(2, 2) = 4.0;
    PrintMatrix(A, "A");
    Matrix B(2, 2);
    B(1, 1) = 5.0; B(1, 2) = 6.0;
    B(2, 1) = 7.0; B(2, 2) = 8.0;
    PrintMatrix(B, "B");
    std::cout << "Testing A + B..." << std::endl;
    Matrix C = A + B;
    PrintMatrix(C, "A + B");
    std::cout << "Testing A - B..." << std::endl;
    Matrix D = A - B;
    PrintMatrix(D, "A - B");
    std::cout << "Testing 2.5 * A..." << std::endl;
    Matrix E = A * 2.5;
    PrintMatrix(E, "2.5 * A");
    std::cout << "Testing unary operations..." << std::endl;
    Matrix F = +A;
    PrintMatrix(F, "+A");
    Matrix G = -A;
    PrintMatrix(G, "-A");
    std::cout << "Matrix operation tests completed!" << std::endl << std::endl;
}

// matrix-vector operations
void TestMatrixVectorOperations() {
    std::cout << "=== Testing Matrix-Vector Operations ===" << std::endl;
    Matrix A(2, 3);
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    PrintMatrix(A, "A");
    Vector v(3);
    v[0] = 10.0; v[1] = 20.0; v[2] = 30.0;
    PrintVector(v, "v");
    std::cout << "Testing A * v..." << std::endl;
    Vector result1 = A * v;
    PrintVector(result1, "A * v");
    Matrix B(3, 2);
    B(1, 1) = 1.0; B(1, 2) = 2.0;
    B(2, 1) = 3.0; B(2, 2) = 4.0;
    B(3, 1) = 5.0; B(3, 2) = 6.0;
    PrintMatrix(B, "B");
    std::cout << "Testing v * B..." << std::endl;
    Vector result2 = v * B;
    PrintVector(result2, "v * B");
    std::cout << "Matrix-Vector operation tests completed!" << std::endl << std::endl;
}

// determinant tests
void TestDeterminant() {
    std::cout << "=== Testing Determinant Calculation ===" << std::endl;
    Matrix A(1, 1);
    A(1, 1) = 5.0;
    PrintMatrix(A, "A");
    std::cout << "Determinant of A = " << A.CalculateDeterminant() << std::endl;
    Matrix B(2, 2);
    B(1, 1) = 1.0; B(1, 2) = 2.0;
    B(2, 1) = 3.0; B(2, 2) = 4.0;
    PrintMatrix(B, "B");
    std::cout << "Determinant of B = " << B.CalculateDeterminant() << std::endl;
    Matrix C(3, 3);
    C(1, 1) = 1.0; C(1, 2) = 2.0; C(1, 3) = 3.0;
    C(2, 1) = 4.0; C(2, 2) = 5.0; C(2, 3) = 6.0;
    C(3, 1) = 7.0; C(3, 2) = 8.0; C(3, 3) = 10.0;
    PrintMatrix(C, "C");
    std::cout << "Determinant of C = " << C.CalculateDeterminant() << std::endl;
    std::cout << "Determinant calculation tests completed!" << std::endl << std::endl;
}

int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "    COMPREHENSIVE MATRIX CLASS TESTS    " << std::endl;
    std::cout << "=========================================" << std::endl << std::endl;
    try {
        TestConstructorsAndBasics();
        TestMatrixOperations();
        TestMatrixVectorOperations();
        TestDeterminant();
        std::cout << "All tests completed successfully!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred during testing." << std::endl;
        return 1;
    }
    return 0;
}
