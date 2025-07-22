/**
 * test_matrix.cpp
 * 
 * A simple and clear test program for the Matrix class that demonstrates basic functionality.
 * This program provides examples of how to use the Matrix class with easy-to-understand output.
 * 
 * Compile with:
 * g++ -o test_matrix test_matrix.cpp Matrix.cpp Vector.cpp
 */

#include <iostream>
#include <iomanip>  // For setting precision in output
#include "Matrix.hpp"
#include "Vector.hpp"

// Function to print a horizontal line for better output formatting
void PrintLine() {
    std::cout << "-------------------------------------------------------" << std::endl;
}

// Function to print a section header
void PrintSection(const std::string& title) {
    PrintLine();
    std::cout << title << std::endl;
    PrintLine();
}

// Function to print a matrix with a title
void PrintMatrix(const Matrix& matrix, const std::string& title) {
    std::cout << title << " (" << matrix.GetNumberOfRows() << "x" 
              << matrix.GetNumberOfColumns() << " matrix):" << std::endl;
    
    for (int i = 1; i <= matrix.GetNumberOfRows(); i++) {
        std::cout << "  ";
        for (int j = 1; j <= matrix.GetNumberOfColumns(); j++) {
            // We need to use a const_cast here because operator() isn't const
            std::cout << std::setw(6) << std::fixed << std::setprecision(1) 
                      << const_cast<Matrix&>(matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to print a vector with a title
void PrintVector(const Vector& vector, const std::string& title) {
    std::cout << title << " (size " << vector.GetSize() << "):" << std::endl;
    std::cout << "  [";
    for (int i = 0; i < vector.GetSize(); i++) {
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << vector.Read(i);
        if (i < vector.GetSize() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl << std::endl;
}

int main() {
    // Welcome message
    std::cout << std::endl;
    std::cout << "=============== MATRIX CLASS TEST PROGRAM ===============" << std::endl;
    std::cout << "This program demonstrates the functionality of Matrix class" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::endl;

    // PART 1: Creating and displaying matrices
    PrintSection("PART 1: Creating and displaying matrices");
    
    std::cout << "Creating a 2x3 matrix A..." << std::endl;
    Matrix A(2, 3);
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    PrintMatrix(A, "Matrix A");
    
    std::cout << "Creating a 3x2 matrix B..." << std::endl;
    Matrix B(3, 2);
    B(1, 1) = 7.0;  B(1, 2) = 8.0;
    B(2, 1) = 9.0;  B(2, 2) = 10.0;
    B(3, 1) = 11.0; B(3, 2) = 12.0;
    PrintMatrix(B, "Matrix B");
    
    std::cout << "Creating a 2x2 matrix C..." << std::endl;
    Matrix C(2, 2);
    C(1, 1) = 1.0; C(1, 2) = 2.0;
    C(2, 1) = 3.0; C(2, 2) = 4.0;
    PrintMatrix(C, "Matrix C");
    
    std::cout << "Creating a 2x2 matrix D..." << std::endl;
    Matrix D(2, 2);
    D(1, 1) = 5.0; D(1, 2) = 6.0;
    D(2, 1) = 7.0; D(2, 2) = 8.0;
    PrintMatrix(D, "Matrix D");
    
    // PART 2: Matrix operations
    PrintSection("PART 2: Matrix operations");
    
    std::cout << "1. Matrix addition: C + D" << std::endl;
    Matrix sum = C + D;
    PrintMatrix(sum, "C + D");
    
    std::cout << "2. Matrix subtraction: C - D" << std::endl;
    Matrix diff = C - D;
    PrintMatrix(diff, "C - D");
    
    std::cout << "3. Scalar multiplication: 2.5 * C" << std::endl;
    Matrix scaled = C * 2.5;
    PrintMatrix(scaled, "2.5 * C");
    
    // PART 3: Matrix-Vector operations
    PrintSection("PART 3: Matrix-Vector operations");
    
    std::cout << "Creating a vector v of size 3..." << std::endl;
    Vector v(3);
    v[0] = 10.0; v[1] = 20.0; v[2] = 30.0;
    PrintVector(v, "Vector v");
    
    std::cout << "1. Matrix-Vector multiplication: A * v" << std::endl;
    Vector resultAv = A * v;
    PrintVector(resultAv, "A * v");
    
    std::cout << "Creating a vector w of size 2..." << std::endl;
    Vector w(2);
    w[0] = 10.0; w[1] = 20.0;
    PrintVector(w, "Vector w");
    
    std::cout << "2. Vector-Matrix multiplication: w * A" << std::endl;
    Vector resultWa = w * A;
    PrintVector(resultWa, "w * A");
    
    // PART 4: Determinant calculation
    PrintSection("PART 4: Determinant calculation");
    
    std::cout << "Creating a square matrix for determinant calculation..." << std::endl;
    Matrix detMatrix(3, 3);
    detMatrix(1, 1) = 2.0; detMatrix(1, 2) = -1.0; detMatrix(1, 3) = 0.0;
    detMatrix(2, 1) = -1.0; detMatrix(2, 2) = 2.0; detMatrix(2, 3) = -1.0;
    detMatrix(3, 1) = 0.0; detMatrix(3, 2) = -1.0; detMatrix(3, 3) = 2.0;
    PrintMatrix(detMatrix, "Determinant Test Matrix");
    
    std::cout << "Calculating determinant..." << std::endl;
    double det = detMatrix.CalculateDeterminant();
    std::cout << "Determinant = " << det << std::endl << std::endl;
    
    // Conclusion
    PrintSection("CONCLUSION");
    std::cout << "All matrix operations were demonstrated successfully!" << std::endl;
    std::cout << "Note: Some functions in your Matrix class may have bugs that need fixing." << std::endl;
    std::cout << "Check the comments in Matrix.cpp for potential issues." << std::endl;
    std::cout << std::endl;
    
    return 0;
}
