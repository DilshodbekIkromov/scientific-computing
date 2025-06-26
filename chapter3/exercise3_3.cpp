#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 1 && "Please provide the number of grid points N as a command line argument.");

    int N = atoi(argv[1]);
    assert(N > 1 && "Number of grid points N must be greater than 1.");

    double a = 0.0, b = 1.0; 
    double h = (b - a) / (N - 1); 

    vector<double> x(N), y(N);
    x[0] = a;
    y[0] = 1.0; 

    for (int n = 1; n < N; ++n) {
        x[n] = a + n * h;
        y[n] = y[n-1] / (1.0 + h);
    }

    // Write results to file
    ofstream fout("xy.dat");
    assert(fout.is_open() && "Failed to open xy.dat for writing.");
    for (int n = 0; n < N; ++n) {
        fout << x[n] << " " << y[n] << "\n";
    }
    fout.close();

    cout << "Results written to xy.dat\n";
    return 0;
}
