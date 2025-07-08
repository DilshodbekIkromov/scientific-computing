#include <iostream>
#include <vector>
#include <cmath>   // for std::pow and std::abs

double pNorm(const std::vector<double>& v, int p = 2) {
    double sum = 0.0;

    for (double vi : v) {
        sum += std::pow(std::abs(vi), p);
    }

    return std::pow(sum, 1.0 / p);
}

int main() {
    // Example usage
    std::vector<double> vec = {3.0, 4.0};

    double norm2 = pNorm(vec);         // default p = 2 (Euclidean norm)
    double norm1 = pNorm(vec, 1);      // p = 1 (Manhattan norm)
    double norm3 = pNorm(vec, 3);      // p = 3

    std::cout << "2-norm: " << norm2 << std::endl;
    std::cout << "1-norm: " << norm1 << std::endl;
    std::cout << "3-norm: " << norm3 << std::endl;

    return 0;
}
