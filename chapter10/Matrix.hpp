#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"

// A mathematical matrix class for storing and manipulating 2D arrays of numbers
class Matrix
{
private:
    double** mData;    // Pointer to 2D array storing matrix elements (rows of pointers to columns)
    int mNumRows;      // Number of rows in the matrix (height)
    int mNumCols;      // Number of columns in the matrix (width)
public:
    Matrix(const Matrix& otherMatrix);     // Copy constructor: create matrix by copying another matrix
    Matrix(int numRows, int numCols);      // Constructor: create empty matrix with specified rows and columns
    ~Matrix();                             // Destructor: free memory allocated for the matrix

    int GetNumberOfRows() const;           // Get the number of rows (height) in the matrix
    int GetNumberOfColumns() const;        // Get the number of columns (width) in the matrix

    double& operator()(int i, int j);      // Access element at row i, column j (can modify the value)
    Matrix& operator=(const Matrix& otherMatrix); // Assignment: copy all elements from another matrix
    Matrix operator+() const;             // Unary plus: return a positive copy of the matrix
    Matrix operator-() const;             // Unary minus: return matrix with all elements negated
    Matrix operator+(const Matrix& m1) const; // Addition: add corresponding elements of two matrices
    Matrix operator-(const Matrix& m1) const; // Subtraction: subtract corresponding elements of two matrices

    Matrix operator*(double a) const;     // Scalar multiplication: multiply each element by a number
    double CalculateDeterminant() const;  // Calculate determinant (only works for square matrices)

    // Friend functions for matrix-vector multiplication (can access private members)
    friend Vector operator*(const Matrix& m, const Vector& v);  // Matrix times vector: m * v
    friend Vector operator*(const Vector& v, const Matrix& m);  // Vector times matrix: v * m
};

// Stand-alone function declarations for matrix-vector operations
Vector operator*(const Matrix& m, const Vector& v);  // Multiply matrix by vector (m * v)
Vector operator*(const Vector& v, const Matrix& m);  // Multiply vector by matrix (v * m)

#endif