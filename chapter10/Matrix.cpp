#include <cmath>
#include <iostream>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"

Matrix::Matrix(const Matrix& otherMatrix){
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols; 
    mData = new double* [mNumRows];
    for (int i=0; i<mNumRows; i++){
        mData[i] = new double [mNumCols];   
    }
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; i++){
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

Matrix::Matrix(int numRows, int numCols){
    assert(numCols > 0 );
    assert(numRows > 0 );
    mNumCols = numRows;
    mNumRows = numCols;
    mData = new double* [mNumRows];
    for (int i=0; i<mNumCols; i++){
        mData[i] = new double [mNumCols];
    }
    for (int i=0; i<mNumRows; i++){
        for (int j = 0; i<mNumCols ; j++){
            mData[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix(){
    for (int i=0; i<mNumRows; i++){
        delete[] mData[i];
    }
    delete[] mData;
}

Matrix::GetNumberOfColumns() const {
    return mNumCols;
}

Matrix::GetNumberOfRows() const{
    return mNumRows;
}

double& Matrix::operator()(int i, int j){
    assert(i>0);
    assert(i < mNumRows+1);
    assert(j>0);
    assert(j < mNumCols+1)
    return mData[i-1][j-1];
}


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

// matrix hpp 22 line left 






