// dynamic allocation of memory

#include <iostream>
using namespace std;

int main() {
    int rows = 5, cols = 3;
    double** A;

    // Allocate memory for an array of pointers (each for a row)
    A = new double*[rows];

    // Allocate memory for each row (each row is an array of doubles)
    for (int i = 0; i < rows; i++) {
        A[i] = new double[cols];
    }

    // Fill the array with values and print them
    cout << "Filling and printing the 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = i * cols + j; // Example value
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Free the memory for each row
    for (int i = 0; i < rows; i++) {
        delete[] A[i];
    }

    // Free the memory for the array of pointers
    delete[] A;

    return 0;
}