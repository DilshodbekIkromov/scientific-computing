#include "LinearSystem.hpp"
#include <cassert>
#include <cmath>

// Gaussian elimination solver

LinearSystem::LinearSystem(const Matrix& A, const Vector& b)
{
    int local_size = A.GetNumberOfRows();
    assert(A.GetNumberOfColumns() == local_size);
    assert(b.GetSize() == local_size);
    mSize = local_size;
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

LinearSystem::~LinearSystem()
{
    delete mpA;
    delete mpb;
}

Vector LinearSystem::Solve()
{
    Matrix A(*mpA);
    Vector b(*mpb);
    Vector solution(mSize);
    for (int k = 0; k < mSize - 1; k++)
    {
        int pivot_row = k;
        double max_val = fabs(A.Read(k, k));
        for (int i = k + 1; i < mSize; i++)
        {
            if (fabs(A.Read(i, k)) > max_val)
            {
                max_val = fabs(A.Read(i, k));
                pivot_row = i;
            }
        }
        if (pivot_row != k)
        {
            for (int j = 0; j < mSize; j++)
            {
                double temp = A.Read(k, j);
                A(k, j) = A.Read(pivot_row, j);
                A(pivot_row, j) = temp;
            }
            double temp = b.Read(k);
            b[k] = b.Read(pivot_row);
            b[pivot_row] = temp;
        }
        assert(fabs(A.Read(k, k)) > 1e-10);
        for (int i = k + 1; i < mSize; i++)
        {
            double multiplier = A.Read(i, k) / A.Read(k, k);
            for (int j = k; j < mSize; j++)
            {
                A(i, j) = A.Read(i, j) - multiplier * A.Read(k, j);
            }
            b[i] = b.Read(i) - multiplier * b.Read(k);
        }
    }
    for (int i = mSize - 1; i >= 0; i--)
    {
        solution[i] = b.Read(i);
        for (int j = i + 1; j < mSize; j++)
        {
            solution[i] -= A.Read(i, j) * solution[j];
        }
        solution[i] /= A.Read(i, i);
    }
    return solution;
}
