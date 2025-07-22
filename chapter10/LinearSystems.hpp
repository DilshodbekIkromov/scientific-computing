#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Vector.hpp"
#include "Matrix.hpp"

// Solve Ax = b
class LinearSystem
{
protected:
    int mSize;      // dimension
    Matrix* mpA;    // matrix
    Vector* mpb;    // right-hand side

    LinearSystem(const LinearSystem& otherLinearSystem){};

public:
    LinearSystem(const Matrix& A, const Vector& b);
    ~LinearSystem();
    virtual Vector Solve();
};

#endif
