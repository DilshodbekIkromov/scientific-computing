#include <iostream>

int main(){
    int n=2;

    double** A = new double*[n];
    double** B = new double*[n];
    double** C = new double*[n];

    for (int i = 0; i< n; i++){
        A[i] = new double[n];
        B[i] = new double[n];
        C[i] = new double[n];

    }

    for (int i=0; i<2; i++){
        for(int j=0; j<2 ; j++){
            A[i][j] = i+j;
            B[i][j] = i*j + i + j + j*j;
            C[i][j] = 0.0;
        }
    }

    for (int k = 0; k<n; k++){
        for (int m = 0; m<n; m++){
            C[k][m] = A[k][m] + B[k][m];
        }
    }

    // print
    for (int i = 0; i<n; i++){
        for (int j =0; j<n; j++){
            std::cout << C[i][j] << " " ; 
        }
        std::cout << "\n" << std::endl;
    }

    for (int i = 0; i<n; i++){
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}


