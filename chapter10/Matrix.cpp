#include <cmath>
#include <iostream>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"

// Matrix implementation

// copy constructor
Matrix::Matrix(const Matrix& otherMatrix){
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    mData = new double*[mNumRows];
    for (int i=0; i<mNumRows; i++){
        mData[i] = new double[mNumCols];
    }
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

// create empty matrix
Matrix::Matrix(int numRows, int numCols){
    assert(numCols > 0);
    assert(numRows > 0);
    mNumCols = numCols;
    mNumRows = numRows;
    mData = new double*[mNumRows];
    for (int i=0; i<mNumRows; i++){
        mData[i] = new double[mNumCols];
    }
    for (int i=0; i<mNumRows; i++){
        for (int j = 0; j<mNumCols; j++){
            mData[i][j] = 0.0;
        }
    }
}

// destructor
Matrix::~Matrix(){
    for (int i=0; i<mNumRows; i++){
        delete[] mData[i];
    }
    delete[] mData;
}

// column count
int Matrix::GetNumberOfColumns() const {
    return mNumCols;
}

// row count
int Matrix::GetNumberOfRows() const{
    return mNumRows;
}

// access element (1-based)
double& Matrix::operator()(int i, int j){
    assert(i>0);
    assert(i < mNumRows+1);
    assert(j>0);
    assert(j < mNumCols+1);
    return mData[i-1][j-1];
}

// assignment
Matrix& Matrix::operator=(const Matrix& otherMatrix){
    assert(mNumRows == otherMatrix.mNumRows);
    assert(mNumCols == otherMatrix.mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j = 0; j< mNumCols; j++){
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

// unary plus
Matrix Matrix::operator+() const{
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mat(i+1,j+1) = mData[i][j];
        }
    }
    return mat;
}

// unary minus
Matrix Matrix::operator-() const{
    Matrix mat(mNumRows, mNumCols);
    for (int i=0;i<mNumRows; i++){
        for(int j=0; j<mNumCols; j++){
            mat(i+1,j+1)= -mData[i][j];
        }
    }
    return mat;
}

// add matrices
Matrix Matrix::operator+(const Matrix& m1) const{
    assert(mNumCols == m1.mNumCols);
    assert(mNumRows == m1.mNumRows);
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0;j<mNumCols; j++){
            mat(i+1,j+1) = mData[i][j] + m1.mData[i][j];
        }
    }
    return mat;
}

// subtract matrices
Matrix Matrix::operator-(const Matrix& m1) const {
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mat(i+1,j+1) = mData[i][j] - m1.mData[i][j];
        }
    }
    return mat;
}

// multiply by scalar
Matrix Matrix::operator*(double a) const {
    Matrix mat(mNumRows, mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mat(i+1, j+1) = a*mData[i][j];
        }
    }
    return mat;
}

// matrix times vector
Vector operator*(const Matrix& m, const Vector& v)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfColumns() == original_vector_size);
    int new_vector_length = m.GetNumberOfRows();
    Vector new_vector(new_vector_length);
    for (int i=0; i<new_vector_length; i++)
    {
        for (int j=0; j<original_vector_size; j++)
        {
            new_vector[i] += m.mData[i][j]*v.Read(j);
        }
    }
    return new_vector;
}

// vector times matrix
Vector operator*(const Vector& v, const Matrix& m)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfRows() == original_vector_size);
    int new_vector_length = m.GetNumberOfColumns();
    Vector new_vector(new_vector_length);
    for (int i=0; i<new_vector_length; i++)
    {
        for (int j=0; j<original_vector_size; j++)
        {
            new_vector[i] += v.Read(j)*m.mData[j][i];
        }
    }
    return new_vector;
}

// determinant using expansion by minors
double Matrix::CalculateDeterminant() const
{
    assert(mNumRows == mNumCols);
    if (mNumRows == 1)
    {
        return mData[0][0];
    }
    if (mNumRows == 2)
    {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    double determinant = 0.0;
    for (int j = 0; j < mNumCols; j++)
    {
        Matrix subMatrix(mNumRows - 1, mNumCols - 1);
        for (int i = 1; i < mNumRows; i++)
        {
            int colIndex = 0;
            for (int k = 0; k < mNumCols; k++)
            {
                if (k != j)
                {
                    subMatrix.mData[i-1][colIndex] = mData[i][k];
                    colIndex++;
                }
            }
        }
        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        determinant += sign * mData[0][j] * subMatrix.CalculateDeterminant();
    }
    return determinant;
}
