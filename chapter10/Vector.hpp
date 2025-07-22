#ifndef VECTOR_HPP
#define VECTOR_HPP

// A mathematical vector class for storing and manipulating arrays of numbers
class Vector 
{
    private:
        double* mData; // pointer to dynamically allocated array storing vector elements
        int mSize;     // number of elements in the vector
        
    public: 
        Vector(const Vector& otherVector); // create vector by copying another vector
        Vector(int size);                  // create vector with specified size
        ~Vector();                         // destructor to free memory

        int GetSize() const;               // returns the size of the vector
        double& operator[] (int i);        // access element at index i (can modify)

        double Read(int i) const;          // read element at index i (read-only)
        double& operator() (int i);        // alternative way to access element at index i

        Vector& operator=(const Vector& otherVector); // assign one vector to another
        Vector operator+() const;          // unary plus (returns copy of vector)
        Vector operator-() const;          // unary minus (negates all elements)
        Vector operator+(const Vector& v1) const; // add two vectors element-wise
        Vector operator-(const Vector& v1) const; // subtract two vectors element-wise

        Vector operator*(double a) const;  // multiply vector by a scalar
        double CalculateNorm(int p=2) const; // calculate p-norm of vector (default: 2-norm)

        friend int length(const Vector& v); // friend function to get vector length
};

// Friend function declaration (note the semicolon)
int length(const Vector& v);

#endif

