#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp"

// Vector implementation

// copy constructor
Vector::Vector(const Vector& otherVector){
    mSize = otherVector.GetSize();
    mData = new double[mSize];
    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];
    }
}

// create vector with given size
Vector::Vector(int size){
    assert(size > 0);
    mSize = size;
    mData = new double[mSize];
    for (int i=0; i<mSize; i++){
        mData[i] = 0.0;
    }
}

// destructor
Vector::~Vector(){
    delete[] mData;
}

// number of entries
int Vector::GetSize() const
{
    return mSize;
}

// element access (0-based)
double& Vector::operator[](int i){
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

// read element
double Vector::Read(int i) const {
    assert(i > -1 );
    assert(i < mSize);
    return mData[i];
}

// element access (1-based)
double& Vector::operator()(int i){
    assert(i > 0);
    assert(i < mSize+1);
    return mData[i-1];
}

// assignment
Vector& Vector::operator=(const Vector& otherVector){
    assert(mSize == otherVector.mSize);
    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];
    }
    return *this;
}

// unary plus
Vector Vector::operator+() const{
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i];
    }
    return v;
}

// unary minus
Vector Vector::operator-() const {
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = -mData[i];
    }
    return v;
}

// add vectors
Vector Vector::operator+(const Vector& v1) const{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] + v1.mData[i];
    }
    return v;
}

// subtract vectors
Vector Vector::operator-(const Vector& v1) const {
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] - v1.mData[i];
    }
    return v;
}

// multiply by scalar
Vector Vector::operator*(double a) const {
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = a*mData[i];
    }
    return v;
}

// compute p-norm
double Vector::CalculateNorm(int p) const{
    double sum = 0.0;
    for (int i=0; i<mSize; i++){
        sum += pow(fabs(mData[i]), p);
    }
    return pow(sum, 1.0/p);
}

// friend function
int length(const Vector& v){
    return v.mSize;
}
