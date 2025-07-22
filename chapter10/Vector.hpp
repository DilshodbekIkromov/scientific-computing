#ifndef VECTOR_HPP
#define VECTOR_HPP

// Simple vector class
class Vector
{
private:
    double* mData; // data array
    int mSize;     // length
public:
    Vector(const Vector& otherVector);
    Vector(int size);
    ~Vector();

    int GetSize() const;
    double& operator[](int i);
    double Read(int i) const;
    double& operator()(int i);

    Vector& operator=(const Vector& otherVector);
    Vector operator+() const;
    Vector operator-() const;
    Vector operator+(const Vector& v1) const;
    Vector operator-(const Vector& v1) const;
    Vector operator*(double a) const;
    double CalculateNorm(int p=2) const;

    friend int length(const Vector& v);
};

// Friend function to get size
int length(const Vector& v);

#endif
