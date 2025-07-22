#include <iostream>
#include <memory>

template<typename T, std::size_t N>
class Matrix {
private:
    T* buffer; // buffer is a pointer to memory where we store all matrix elements

public:
    // Constructor (creates matrix) 
    // When we create matrix this automatically runs and creates nxn matrix with 0's
    Matrix() { 
        buffer = new T[N * N]();  // Initialize to zero
    }

    // Destructor
    ~Matrix() {
        delete[] buffer;
    }

    // Copy constructor
    Matrix(const Matrix& other) {
        buffer = new T[N * N];
        for (std::size_t i = 0; i < N * N; ++i) {
            buffer[i] = other.buffer[i];
        }
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (std::size_t i = 0; i < N * N; ++i) {
                buffer[i] = other.buffer[i];
            }
        }
        return *this;
    }

    // Element access operator
    T& operator()(std::size_t i, std::size_t j) {
        return buffer[i * N + j];
    }

    const T& operator()(std::size_t i, std::size_t j) const {
        return buffer[i * N + j];
    }

    // Static member function for dimension
    static constexpr std::size_t dimension() { 
        return N; 
    }
};

// Test the Matrix class
int main() {
    // Test with int, 3x3 matrix
    Matrix<int, 3> intMatrix;
    
    // Fill matrix with values
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            intMatrix(i, j) = i * 3 + j + 1;
        }
    }
    
    // Print matrix
    std::cout << "3x3 int matrix:" << std::endl;
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            std::cout << intMatrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    // Test dimension function
    std::cout << "Matrix dimension: " << Matrix<int, 3>::dimension() << std::endl;
    
    // Test with double, 2x2 matrix
    Matrix<double, 2> doubleMatrix;
    doubleMatrix(0, 0) = 1.5;
    doubleMatrix(0, 1) = 2.5;
    doubleMatrix(1, 0) = 3.5;
    doubleMatrix(1, 1) = 4.5;
    
    std::cout << "\n2x2 double matrix:" << std::endl;
    for (std::size_t i = 0; i < 2; ++i) {
        for (std::size_t j = 0; j < 2; ++j) {
            std::cout << doubleMatrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
