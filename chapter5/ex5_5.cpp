#include <iostream>
#include <cassert>

void Multiply(
    double* matrixA, int rowsA, int colsA,
    double* matrixB, int rowsB, int colsB,
    double* result
);

int main(){
    double matrixA[2][2] = {
        {1,3},
        {5,10}
    };
    double matrixB[2][2] = {
        {8,8},
        {4,4}
    };

    double result[2][2];

    Multiply((double*)matrixA, 2, 2, (double*)matrixB, 2, 2, (double*)result);
    
    // Print result
    std::cout << "Result:" << std::endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

void Multiply(
    double* matrixA, int rowsA, int colsA,
    double* matrixB, int rowsB, int colsB,
    double* result
){
    assert(matrixA != nullptr && "Matrix A cannot be null");
    assert(matrixB != nullptr && "Matrix B cannot be null");
    assert(result != nullptr && "Result matrix cannot be null");
    assert(rowsA > 0 && "Rows A must be positive");
    assert(colsA > 0 && "Cols A must be positive");
    assert(rowsB > 0 && "Rows B must be positive");
    assert(colsB > 0 && "Cols B must be positive");
    assert(colsA == rowsB && "Matrix dimensions incompatible");

    // For each element in result matrix
    for(int i = 0; i < rowsA; i++){          // i = row of result
        for(int j = 0; j < colsB; j++){      // j = column of result
            
            // Initialize result[i][j] to 0
            result[i*colsB + j] = 0.0;
            
            for(int k = 0; k < colsA; k++){
                // result[i][j] += A[i][k] * B[k][j]
                result[i*colsB + j] += matrixA[i*colsA + k] * matrixB[k*colsB + j];
            }
        }
    }
}