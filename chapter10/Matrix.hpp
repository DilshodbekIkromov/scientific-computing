#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"

// Basic matrix class
class Matrix
{
private:
    double** mData;  // matrix entries
    int mNumRows;    // rows
    int mNumCols;    // columns
public:
    Matrix(const Matrix& otherMatrix);
    Matrix(int numRows, int numCols);
    ~Matrix();

    int GetNumberOfRows() const;
    int GetNumberOfColumns() const;

    double& operator()(int i, int j);
    Matrix& operator=(const Matrix& otherMatrix);
    Matrix operator+() const;
    Matrix operator-() const;
    Matrix operator+(const Matrix& m1) const;
    Matrix operator-(const Matrix& m1) const;

    Matrix operator*(double a) const;
    double CalculateDeterminant() const;

    friend Vector operator*(const Matrix& m, const Vector& v);
    friend Vector operator*(const Vector& v, const Matrix& m);
};

// Multiply matrix and vector
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);

#endif
