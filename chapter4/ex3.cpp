#include <iostream>


int main(){
    const int N = 3;
    double dot_prod = 0.0;

    for (long long i = 0; i< 1000000000LL; ++i){
        double* a = new double[N];
        double* b = new double[N];

        for (int i = 0; i<N; ++i){
            a[i] = i+1;
            b[i] = i+10;
        }
        dot_prod = 0.0;
        for (int i = 0; i < N; ++i)
        {
            dot_prod += a[i]*b[i];
        }
        if (i == 0){
            std::cout << "Dot product: " << dot_prod << std::endl;
        }
        delete[] a;
        delete[] b;
    }
    return 0;
}