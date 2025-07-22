#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector 
{
    private:
    double* mData; // we store the data in vector
    int mSize; // size of the vector
    public: 
    Vector (const Vector& otherVector); // copy constructor
}



#endif

