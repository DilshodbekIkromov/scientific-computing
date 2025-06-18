#include <iostream>
using namespace std;

double det(const double matrix_A[2][2]) {
    return matrix_A[0][0] * matrix_A[1][1] - matrix_A[0][1] * matrix_A[1][0];
}

void printInv(const double matrix_A[2][2], double determinant) {
    if (determinant == 0) {
        cout << "Matrix is singular, inverse does not exist." << endl;
        return;
    }
    double inv[2][2];
    inv[0][0] =  matrix_A[1][1] / determinant;
    inv[0][1] = -matrix_A[0][1] / determinant;
    inv[1][0] = -matrix_A[1][0] / determinant;
    inv[1][1] =  matrix_A[0][0] / determinant;

    cout << "Inverse matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double matrix_A[2][2] = { {4, 10}, {1, 1} }; 
    double determinant = det(matrix_A);
    printInv(matrix_A, determinant);
    return 0;
}




