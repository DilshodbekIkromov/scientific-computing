#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> getMinor(const vector<vector<double>>& matrix, int row, int col) {
    int n = matrix.size();
    vector<vector<double>> minor;

    for (int i = 0; i < n; ++i) {
        if (i == row) continue; 

        vector<double> minorRow;
        for (int j = 0; j < n; ++j) {
            if (j == col) continue; 
            minorRow.push_back(matrix[i][j]);
        }
        minor.push_back(minorRow);
    }

    return minor;
}

double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();

    if (n == 1) return matrix[0][0];

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    for (int j = 0; j < n; ++j) {
        double cofactor = pow(-1, j) * matrix[0][j] * determinant(getMinor(matrix, 0, j));
        det += cofactor;
    }

    return det;
}

int main() {
    vector<vector<double>> mat2 = {
        {1, 2},
        {3, 4}
    };

    cout << "Determinant (2x2): " << determinant(mat2) << endl; 

    vector<vector<double>> mat3 = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    };

    cout << "Determinant (3x3): " << determinant(mat3) << endl; 

    return 0;
}
