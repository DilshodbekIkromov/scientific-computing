/**
 * test_matrix_performance.cpp
 * 
 * Performance test for the Matrix class to measure execution time for different operations.
 * 
 * Compile with:
 * g++ -O2 -o test_performance test_matrix_performance.cpp Matrix.cpp Vector.cpp
 */

#include <iostream>
#include <chrono>
#include <iomanip>
#include <functional>
#include <algorithm>
#include "Matrix.hpp"
#include "Vector.hpp"

using namespace std::chrono;

double TimeOperation(std::function<void()> operation) {
    auto start = high_resolution_clock::now();
    operation();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000.0; // Return milliseconds
}

void TestMatrixCreationPerformance() {
    std::cout << "Matrix Creation Performance:" << std::endl;
    std::cout << "Size\t\tTime (ms)" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    for (int size = 10; size <= 500; size += 50) {
        double time = TimeOperation([size]() {
            Matrix A(size, size);
            // Fill with some values to ensure memory is actually allocated
            for (int i = 1; i <= std::min(size, 5); i++) {
                for (int j = 1; j <= std::min(size, 5); j++) {
                    A(i, j) = i * j;
                }
            }
        });
        
        std::cout << size << "x" << size << "\t\t" 
                  << std::fixed << std::setprecision(3) << time << std::endl;
    }
    std::cout << std::endl;
}

void TestMatrixMultiplicationPerformance() {
    std::cout << "Matrix-Vector Multiplication Performance:" << std::endl;
    std::cout << "Size\t\tTime (ms)" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    for (int size = 50; size <= 500; size += 50) {
        // Create matrices and vector
        Matrix A(size, size);
        Vector v(size);
        
        // Fill with test data
        for (int i = 1; i <= size; i++) {
            v[i-1] = i * 0.1;
            for (int j = 1; j <= size; j++) {
                A(i, j) = (i + j) * 0.01;
            }
        }
        
        double time = TimeOperation([&A, &v]() {
            Vector result = A * v;
        });
        
        std::cout << size << "x" << size << "\t\t" 
                  << std::fixed << std::setprecision(3) << time << std::endl;
    }
    std::cout << std::endl;
}

void TestDeterminantPerformance() {
    std::cout << "Determinant Calculation Performance:" << std::endl;
    std::cout << "Size\t\tTime (ms)" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    for (int size = 2; size <= 8; size++) {
        Matrix A(size, size);
        
        // Fill with test data (avoid singular matrices)
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (i == j) {
                    A(i, j) = 2.0; // Diagonal dominance
                } else {
                    A(i, j) = 0.1;
                }
            }
        }
        
        double time = TimeOperation([&A]() {
            double det = A.CalculateDeterminant();
        });
        
        std::cout << size << "x" << size << "\t\t" 
                  << std::fixed << std::setprecision(3) << time << std::endl;
        
        // Stop at reasonable size since determinant calculation is O(n!)
        if (size >= 7 && time > 1000) {
            std::cout << "Stopping test - determinant calculation too slow for larger matrices" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

void TestMatrixArithmeticPerformance() {
    std::cout << "Matrix Addition Performance:" << std::endl;
    std::cout << "Size\t\tTime (ms)" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    for (int size = 100; size <= 1000; size += 100) {
        Matrix A(size, size);
        Matrix B(size, size);
        
        // Fill with test data
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                A(i, j) = i * 0.01;
                B(i, j) = j * 0.01;
            }
        }
        
        double time = TimeOperation([&A, &B]() {
            Matrix C = A + B;
        });
        
        std::cout << size << "x" << size << "\t\t" 
                  << std::fixed << std::setprecision(3) << time << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Matrix Class Performance Tests" << std::endl;
    std::cout << "==============================" << std::endl << std::endl;
    
    TestMatrixCreationPerformance();
    TestMatrixArithmeticPerformance();
    TestMatrixMultiplicationPerformance();
    TestDeterminantPerformance();
    
    std::cout << "Performance testing completed!" << std::endl;
    std::cout << "Note: Times may vary based on system performance." << std::endl;
    
    return 0;
}
