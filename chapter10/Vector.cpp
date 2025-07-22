#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp"

// Copy constructor: creates a new vector by copying another vector
Vector::Vector(const Vector& otherVector){
    mSize = otherVector.GetSize();
    mData = new double [mSize];  // allocate memory for new vector
    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];  // copy each element
    }
}

// Constructor: creates a vector of given size, initialized to zero
Vector::Vector(int size){
    assert(size > 0);  // ensure positive size
    mSize = size;
    mData = new double [mSize];  // allocate memory
    for (int i=0; i<mSize; i++){
        mData[i] = 0.0;  // initialize all elements to zero
    }
}

// Destructor: frees the allocated memory
Vector::~Vector(){
    delete[] mData;
}

// Returns the size of the vector
int Vector::GetSize() const
{
    return mSize;
}

// Access operator: returns reference to element at index i (0-based)
double& Vector::operator[](int i){
    assert(i > -1);    // check lower bound
    assert(i < mSize); // check upper bound
    return mData[i];
}

// Read-only access: returns copy of element at index i (0-based)
double Vector::Read(int i) const {
    assert(i > -1 );   // check lower bound
    assert(i < mSize); // check upper bound
    return mData[i];
}

// Access operator: returns reference to element at index i (1-based indexing)
double& Vector::operator()(int i){
    assert(i > 0);         // check lower bound (1-based)
    assert(i < mSize+1);   // check upper bound (1-based)
    return mData[i-1];     // convert to 0-based indexing
}

// Assignment operator: copies elements from another vector
Vector& Vector::operator=(const Vector& otherVector){
    assert(mSize == otherVector.mSize);  // vectors must be same size
    for (int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];  // copy each element
    }
    return *this;  // return reference to this vector
}

// Unary plus: returns a copy of the vector
Vector Vector::operator+() const{
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i];  // copy each element
    }
    return v;  // return the copy
}

// Unary minus: returns a vector with all elements negated
Vector Vector::operator-() const {
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = -mData[i];  // negate each element
    }
    return v;  // return the negated vector
}

// Vector addition: adds corresponding elements of two vectors
Vector Vector::operator+(const Vector& v1) const{
    assert(mSize == v1.mSize);  // vectors must be same size
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] + v1.mData[i];  // add corresponding elements
    }
    return v;
}

// Vector subtraction: subtracts corresponding elements of two vectors
Vector Vector::operator-(const Vector& v1) const { 
    assert(mSize == v1.mSize);  // vectors must be same size
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = mData[i] - v1.mData[i];  // subtract corresponding elements
    }
    return v;  // return the result vector
}

// Scalar multiplication: multiplies each element by a scalar value
Vector Vector::operator*(double a) const {
    Vector v(mSize);
    for (int i=0; i<mSize; i++){
        v[i] = a*mData[i];  // multiply each element by scalar
    }
    return v;
}

// Calculate p-norm of the vector (default p=2 for Euclidean norm)
double Vector::CalculateNorm(int p) const{
    double sum = 0.0;
    for (int i=0; i<mSize; i++){
        sum += pow(fabs(mData[i]), p);  // sum of |element|^p
    }
    return pow(sum, 1.0/p);  // return p-th root of sum
}

// Friend function: returns the length (size) of the vector
int length(const Vector& v){
    return v.mSize;
}



