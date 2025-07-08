#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

vector<double> gaussianElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        A[i].push_back(b[i]);
    }

    for (int k = 0; k < n; ++k) {
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (fabs(A[i][k]) > fabs(A[maxRow][k])) {
                maxRow = i;
            }
        }

        if (fabs(A[maxRow][k]) < 1e-12) {
            throw runtime_error("Matrix is singular or nearly singular.");
        }

        swap(A[k], A[maxRow]);

        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j <= n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = A[i][n];  
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    return x;
}

void printVector(const vector<double>& vec) {
    for (double val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    vector<vector<double>> A = {
        {2, -1, 1},
        {3,  3, 9},
        {3,  3, 5}
    };

    vector<double> b = {2, -1, 4};

    try {
        vector<double> solution = gaussianElimination(A, b);
        cout << "Solution vector x: ";
        printVector(solution);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
