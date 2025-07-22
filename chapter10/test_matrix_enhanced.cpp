#include <iostream>
#include <iomanip>
#include <string>
#include "Matrix.hpp"
#include "Vector.hpp"

// Extended tests for the Matrix class

int testsPassed = 0;
int testsFailed = 0;

void PrintLine() {
    std::cout << "===========================================================" << std::endl;
}

// show section header
void PrintSection(const std::string& title) {
    std::cout << std::endl;
    PrintLine();
    std::cout << "  " << title << std::endl;
    PrintLine();
}

void PrintMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << name << " (" << matrix.GetNumberOfRows() << "x"
              << matrix.GetNumberOfColumns() << "):" << std::endl;
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
    std::cout << name << " (size " << vector.GetSize() << "):" << std::endl;
    std::cout << "  [";
    for (int i = 0; i < vector.GetSize(); i++) {
        std::cout << std::setw(7) << std::fixed << std::setprecision(2) << vector.Read(i);
        if (i < vector.GetSize() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl << std::endl;
}

bool TestEqual(double a, double b, double tolerance = 1e-10) {
    return std::abs(a - b) < tolerance;
}

void TestResult(const std::string& testName, bool passed) {
    if (passed) {
        std::cout << "✓ " << testName << " - PASSED" << std::endl;
        testsPassed++;
    } else {
        std::cout << "✗ " << testName << " - FAILED" << std::endl;
        testsFailed++;
    }
}

void TestConstructors() {
    PrintSection("TESTING CONSTRUCTORS");
    Matrix A(3, 4);
    bool test1 = (A.GetNumberOfRows() == 3) && (A.GetNumberOfColumns() == 4);
    TestResult("Basic constructor (3x4 matrix)", test1);
    bool test2 = true;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!TestEqual(A(i, j), 0.0)) {
                test2 = false;
                break;
            }
        }
        if (!test2) break;
    }
    TestResult("Elements initialized to zero", test2);
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0; A(1, 4) = 4.0;
    A(2, 1) = 5.0; A(2, 2) = 6.0; A(2, 3) = 7.0; A(2, 4) = 8.0;
    A(3, 1) = 9.0; A(3, 2) = 10.0; A(3, 3) = 11.0; A(3, 4) = 12.0;
    Matrix B(A);
    bool test3 = (B.GetNumberOfRows() == 3) && (B.GetNumberOfColumns() == 4);
    for (int i = 1; i <= 3 && test3; i++) {
        for (int j = 1; j <= 4 && test3; j++) {
            if (!TestEqual(A(i, j), B(i, j))) {
                test3 = false;
            }
        }
    }
    TestResult("Copy constructor", test3);
    Matrix C(3, 4);
    C = A;
    bool test4 = true;
    for (int i = 1; i <= 3 && test4; i++) {
        for (int j = 1; j <= 4 && test4; j++) {
            if (!TestEqual(A(i, j), C(i, j))) {
                test4 = false;
            }
        }
    }
    TestResult("Assignment operator", test4);
}

void TestArithmeticOperations() {
    PrintSection("TESTING ARITHMETIC OPERATIONS");
    Matrix A(2, 2);
    A(1, 1) = 1.0; A(1, 2) = 2.0;
    A(2, 1) = 3.0; A(2, 2) = 4.0;
    Matrix B(2, 2);
    B(1, 1) = 5.0; B(1, 2) = 6.0;
    B(2, 1) = 7.0; B(2, 2) = 8.0;
    Matrix C = A + B;
    bool test1 = TestEqual(C(1, 1), 6.0) && TestEqual(C(1, 2), 8.0) &&
                 TestEqual(C(2, 1), 10.0) && TestEqual(C(2, 2), 12.0);
    TestResult("Matrix addition", test1);
    Matrix D = B - A;
    bool test2 = TestEqual(D(1, 1), 4.0) && TestEqual(D(1, 2), 4.0) &&
                 TestEqual(D(2, 1), 4.0) && TestEqual(D(2, 2), 4.0);
    TestResult("Matrix subtraction", test2);
    Matrix E = A * 3.0;
    bool test3 = TestEqual(E(1, 1), 3.0) && TestEqual(E(1, 2), 6.0) &&
                 TestEqual(E(2, 1), 9.0) && TestEqual(E(2, 2), 12.0);
    TestResult("Scalar multiplication", test3);
    Matrix F = +A;
    bool test4 = TestEqual(F(1, 1), 1.0) && TestEqual(F(1, 2), 2.0) &&
                 TestEqual(F(2, 1), 3.0) && TestEqual(F(2, 2), 4.0);
    TestResult("Unary plus", test4);
    Matrix G = -A;
    bool test5 = TestEqual(G(1, 1), -1.0) && TestEqual(G(1, 2), -2.0) &&
                 TestEqual(G(2, 1), -3.0) && TestEqual(G(2, 2), -4.0);
    TestResult("Unary minus", test5);
}

void TestMatrixVectorOperations() {
    PrintSection("TESTING MATRIX-VECTOR OPERATIONS");
    Matrix A(2, 3);
    A(1, 1) = 1.0; A(1, 2) = 2.0; A(1, 3) = 3.0;
    A(2, 1) = 4.0; A(2, 2) = 5.0; A(2, 3) = 6.0;
    Vector v(3);
    v[0] = 1.0; v[1] = 2.0; v[2] = 3.0;
    Vector result1 = A * v;
    bool test1 = TestEqual(result1.Read(0), 14.0) && TestEqual(result1.Read(1), 32.0);
    TestResult("Matrix * Vector", test1);
    Vector w(2);
    w[0] = 2.0; w[1] = 3.0;
    Vector result2 = w * A;
    bool test2 = TestEqual(result2.Read(0), 14.0) && TestEqual(result2.Read(1), 19.0) &&
                 TestEqual(result2.Read(2), 24.0);
    TestResult("Vector * Matrix", test2);
}

void TestDeterminant() {
    PrintSection("TESTING DETERMINANT CALCULATION");
    Matrix A(1, 1);
    A(1, 1) = 7.0;
    double det1 = A.CalculateDeterminant();
    TestResult("1x1 determinant", TestEqual(det1, 7.0));
    Matrix B(2, 2);
    B(1, 1) = 3.0; B(1, 2) = 4.0;
    B(2, 1) = 1.0; B(2, 2) = 2.0;
    double det2 = B.CalculateDeterminant();
    TestResult("2x2 determinant", TestEqual(det2, 2.0));
    Matrix C(3, 3);
    C(1, 1) = 1.0; C(1, 2) = 0.0; C(1, 3) = 0.0;
    C(2, 1) = 0.0; C(2, 2) = 1.0; C(2, 3) = 0.0;
    C(3, 1) = 0.0; C(3, 2) = 0.0; C(3, 3) = 1.0;
    double det3 = C.CalculateDeterminant();
    TestResult("3x3 identity determinant", TestEqual(det3, 1.0));
    Matrix D(3, 3);
    D(1, 1) = 1.0; D(1, 2) = 2.0; D(1, 3) = 3.0;
    D(2, 1) = 2.0; D(2, 2) = 4.0; D(2, 3) = 6.0;
    D(3, 1) = 7.0; D(3, 2) = 8.0; D(3, 3) = 9.0;
    double det4 = D.CalculateDeterminant();
    TestResult("3x3 singular determinant", TestEqual(det4, 0.0));
}

void TestSpecialCases() {
    PrintSection("TESTING SPECIAL CASES AND EDGE CONDITIONS");
    Matrix A(1, 1);
    A(1, 1) = 5.0;
    Matrix B(1, 1);
    B(1, 1) = 3.0;
    Matrix C = A + B;
    TestResult("1x1 matrix addition", TestEqual(C(1, 1), 8.0));
    Matrix Large(10, 10);
    bool test1 = (Large.GetNumberOfRows() == 10) && (Large.GetNumberOfColumns() == 10);
    TestResult("Large matrix creation (10x10)", test1);
    Matrix Zero(2, 2);
    Matrix NonZero(2, 2);
    NonZero(1, 1) = 1.0; NonZero(1, 2) = 2.0;
    NonZero(2, 1) = 3.0; NonZero(2, 2) = 4.0;
    Matrix Result = Zero + NonZero;
    bool test2 = TestEqual(Result(1, 1), 1.0) && TestEqual(Result(1, 2), 2.0) &&
                 TestEqual(Result(2, 1), 3.0) && TestEqual(Result(2, 2), 4.0);
    TestResult("Zero matrix addition", test2);
}

void PrintSummary() {
    PrintSection("TEST SUMMARY");
    std::cout << "Total tests run: " << (testsPassed + testsFailed) << std::endl;
    std::cout << "Tests passed: " << testsPassed << std::endl;
    std::cout << "Tests failed: " << testsFailed << std::endl;
    if (testsFailed == 0) {
        std::cout << std::endl << "🎉 ALL TESTS PASSED! Matrix class is working correctly." << std::endl;
    } else {
        std::cout << std::endl << "❌ Some tests failed. Please review the Matrix implementation." << std::endl;
    }
    PrintLine();
}

int main() {
    std::cout << "Enhanced Matrix Class Test Suite" << std::endl;
    std::cout << "=================================" << std::endl;
    TestConstructors();
    TestArithmeticOperations();
    TestMatrixVectorOperations();
    TestDeterminant();
    TestSpecialCases();
    PrintSummary();
    return (testsFailed == 0) ? 0 : 1;
}
