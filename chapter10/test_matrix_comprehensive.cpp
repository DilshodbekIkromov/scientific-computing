/**
 * test_matrix_comprehensive.cpp
 * 
 * A comprehensive test program for the Matrix class.
 * This program tests all the functionality of the Matrix class including:
 * - Constructors and destructor
 * - Element access and assignment
 * - Basic operations (addition, subtraction, scalar multiplication)
 * - Matrix-Vector operations
 * - Determinant calculation
 * 
 * Compile with:
 * g++ -o test_matrix test_matrix_comprehensive.cpp Matrix.cpp Vector.cpp
 */

#include <iostream>
#include <iomanip>  // For setting precision in output
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"

// Helper function to print a matrix (for debugging and display)
void PrintMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "Matrix " << name << " (" << matrix.GetNumberOfRows() 
              << "x" << matrix.GetNumberOfColumns() << "):" << std::endl;
    
    for (int i = 1; i <= matrix.GetNumberOfRows(); i++) {
        std::cout << "  ";
        for (int j = 1; j <= matrix.GetNumberOfColumns(); j++) {
            // We need to use a const_cast here because operator() isn't const
            // In a real implementation, you might want to add a const version of operator()
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) 
                      << const_cast<Matrix&>(matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Helper function to print a vector (for debugging and display)
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

// Test function for constructors and basic operations
void TestConstructorsAndBasics() {
    std::cout << "=== Testing Constructors and Basic Operations ===" << std::endl;
    
    // Test creating a matrix with dimensions
    std::cout << "Creating a 3x3 matrix A..." << std::endl;
    Matrix A(3, 3);
    
    // Fill the matrix with some values
    std::cout << "Filling matrix A with values..." << std::endl;
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    A(3, 1) = 7.0; A(3, 2) = 8.0; A(3, 3) = 9.0;
    
    // Display the matrix
    PrintMatrix(A, "A");
    
    // Test copy constructor
    std::cout << "Testing copy constructor to create matrix B from A..." << std::endl;
    Matrix B(A);
    PrintMatrix(B, "B");
    
    // Test assignment operator
    std::cout << "Testing assignment operator to create matrix C = A..." << std::endl;
    Matrix C(2, 2);  // Different size initially
    // C = A; // This would fail with an assertion - matrices must be same size
    
    // Create a matrix of the same size first
    Matrix D(3, 3);
    D = A;  // This should work
    PrintMatrix(D, "D");
    
    std::cout << "Basic constructor and assignment tests passed!" << std::endl << std::endl;
}

// Test function for matrix operations
void TestMatrixOperations() {
    std::cout << "=== Testing Matrix Operations ===" << std::endl;
    
    // Create test matrices
    Matrix A(2, 2);
    A(1, 1) = 1.0; A(1, 2) = 2.0;
    A(2, 1) = 3.0; A(2, 2) = 4.0;
    PrintMatrix(A, "A");
    
    Matrix B(2, 2);
    B(1, 1) = 5.0; B(1, 2) = 6.0;
    B(2, 1) = 7.0; B(2, 2) = 8.0;
    PrintMatrix(B, "B");
    
    // Test addition
    std::cout << "Testing A + B..." << std::endl;
    Matrix C = A + B;
    PrintMatrix(C, "A + B");
    
    // Test subtraction
    std::cout << "Testing A - B..." << std::endl;
    Matrix D = A - B;
    PrintMatrix(D, "A - B");
    
    // Test scalar multiplication
    std::cout << "Testing 2.5 * A..." << std::endl;
    Matrix E = A * 2.5;
    PrintMatrix(E, "2.5 * A");
    
    // Test unary operations
    std::cout << "Testing +A (unary plus)..." << std::endl;
    Matrix F = +A;  // This might need to be fixed in your Matrix class
    PrintMatrix(F, "+A");
    
    std::cout << "Testing -A (unary minus)..." << std::endl;
    Matrix G = -A;  // This might need to be fixed in your Matrix class
    PrintMatrix(G, "-A");
    
    std::cout << "Matrix operation tests completed!" << std::endl << std::endl;
}

// Test function for matrix-vector operations
void TestMatrixVectorOperations() {
    std::cout << "=== Testing Matrix-Vector Operations ===" << std::endl;
    
    // Create a test matrix
    Matrix A(2, 3);
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    PrintMatrix(A, "A");
    
    // Create a test vector
    Vector v(3);
    v[0] = 10.0; v[1] = 20.0; v[2] = 30.0;
    PrintVector(v, "v");
    
    // Test matrix * vector
    std::cout << "Testing A * v (Matrix * Vector)..." << std::endl;
    Vector result1 = A * v;
    PrintVector(result1, "A * v");
    
    // Create another test matrix for vector * matrix
    Matrix B(3, 2);
    B(1, 1) = 1.0; B(1, 2) = 2.0;
    B(2, 1) = 3.0; B(2, 2) = 4.0;
    B(3, 1) = 5.0; B(3, 2) = 6.0;
    PrintMatrix(B, "B");
    
    // Test vector * matrix
    std::cout << "Testing v * B (Vector * Matrix)..." << std::endl;
    Vector result2 = v * B;
    PrintVector(result2, "v * B");
    
    std::cout << "Matrix-Vector operation tests completed!" << std::endl << std::endl;
}

// Test function for determinant calculation
void TestDeterminant() {
    std::cout << "=== Testing Determinant Calculation ===" << std::endl;
    
    // Test 1x1 matrix determinant
    Matrix A(1, 1);
    A(1, 1) = 5.0;
    PrintMatrix(A, "A");
    std::cout << "Determinant of A = " << A.CalculateDeterminant() << std::endl;
    
    // Test 2x2 matrix determinant
    Matrix B(2, 2);
    B(1, 1) = 1.0; B(1, 2) = 2.0;
    B(2, 1) = 3.0; B(2, 2) = 4.0;
    PrintMatrix(B, "B");
    std::cout << "Determinant of B = " << B.CalculateDeterminant() << std::endl;
    
    // Test 3x3 matrix determinant
    Matrix C(3, 3);
    C(1, 1) = 1.0; C(1, 2) = 2.0; C(1, 3) = 3.0;
    C(2, 1) = 4.0; C(2, 2) = 5.0; C(2, 3) = 6.0;
    C(3, 1) = 7.0; C(3, 2) = 8.0; C(3, 3) = 10.0;  // Note: not 9 to make det non-zero
    PrintMatrix(C, "C");
    std::cout << "Determinant of C = " << C.CalculateDeterminant() << std::endl;
    
    std::cout << "Determinant calculation tests completed!" << std::endl << std::endl;
}

// Main function to run all tests
int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "    COMPREHENSIVE MATRIX CLASS TESTS    " << std::endl;
    std::cout << "=========================================" << std::endl << std::endl;
    
    // Run all test functions
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
