#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

double determinant3x3(const vector<vector<double>>& mat) {
    return mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])
         - mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])
         + mat[0][2]*(mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0]);
}

vector<vector<double>> replaceColumn(const vector<vector<double>>& A, const vector<double>& b, int col) {
    vector<vector<double>> modified = A;
    for (int i = 0; i < 3; ++i) {
        modified[i][col] = b[i];
    }
    return modified;
}

vector<double> solve3x3(const vector<vector<double>>& A, const vector<double>& b) {
    double detA = determinant3x3(A);

    if (detA == 0.0) {
        throw runtime_error("Matrix A is singular (det = 0). No unique solution exists.");
    }

    vector<double> u(3);
    for (int i = 0; i < 3; ++i) {
        vector<vector<double>> Ai = replaceColumn(A, b, i);
        u[i] = determinant3x3(Ai) / detA;
    }

    return u;
}

int main() {
    vector<vector<double>> A = {
        {2, -1, 3},
        {1,  0, 4},
        {0,  2, -1}
    };

    vector<double> b = {5, 6, -3};

    try {
        vector<double> u = solve3x3(A, b);

        cout << "Solution vector u: ";
        for (double val : u) {
            cout << val << " ";
        }
        cout << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
