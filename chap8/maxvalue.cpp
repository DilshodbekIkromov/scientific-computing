#include <iostream>
#include <complex>

template<typename T> 
T maxValue(const T& a, const T& b){
    if (a==b){
        std::cout << "They are equal" << std::endl;
        return a;
    }
    else if (a<b){
        std::cout << "Maximum value between them is: " << b << std::endl;
        return b;
    }
    else {
        std::cout << "Maximum value between them is: " << a << std::endl;
        return a;
    }
}

// Specialization for complex numbers - compare by magnitude
template<>
std::complex<double> maxValue(const std::complex<double>& a, const std::complex<double>& b){
    if (a==b){
        std::cout << "They are equal" << std::endl;
        return a;
    }
    else if (std::abs(a) < std::abs(b)){
        std::cout << "Maximum magnitude between them is: " << b << std::endl;
        return b;
    }
    else {
        std::cout << "Maximum magnitude between them is: " << a << std::endl;
        return a;
    }
}

int main() {
    // Test with int
    std::cout << "Testing with int:" << std::endl;
    int i1 = 5, i2 = 10;
    maxValue(i1, i2);
    
    // Test with double
    std::cout << "\nTesting with double:" << std::endl;
    double d1 = 3.14, d2 = 2.71;
    maxValue(d1, d2);
    
    // Test with std::complex<double>
    std::cout << "\nTesting with std::complex<double>:" << std::endl;
    std::complex<double> c1(3.0, 4.0), c2(1.0, 2.0);  // Changed to have different magnitudes
    maxValue(c1, c2);
    
    return 0;
}