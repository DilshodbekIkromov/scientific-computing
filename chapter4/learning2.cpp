#include <iostream>

int main(){
    double* x;
    double* y;
    x = new double [10];
    y = new double [10];

    for (int i=0; i<10; i++){
        x[i] = ((double)(i));
        y[i] = 2.0*x[i];

    }
    delete[] x;
    delete[] y;
    x = nullptr;
    y = nullptr;

    return 0;
}