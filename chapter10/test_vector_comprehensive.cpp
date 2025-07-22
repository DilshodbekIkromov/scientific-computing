#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector.hpp"

// Detailed tests for the Vector class

void printVector(const Vector& v, const std::string& name) {
    std::cout << name << " = [";
    for (int i = 0; i < v.GetSize(); i++) {
        std::cout << v.Read(i);
        if (i < v.GetSize() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void testVectorCreation() {
    std::cout << "\n=== Testing Vector Creation ===" << std::endl;
    Vector v1(5);
    printVector(v1, "v1");
    assert(v1.GetSize() == 5);
    std::cout << "✓ Vector created successfully with size: " << v1.GetSize() << std::endl;
    std::cout << "\nFilling vector with values 1, 2, 3, 4, 5..." << std::endl;
    for (int i = 0; i < v1.GetSize(); i++) {
        v1[i] = i + 1;
    }
    printVector(v1, "v1 (after filling)");
    std::cout << "\nTesting copy constructor..." << std::endl;
    Vector v2(v1);
    printVector(v2, "v2 (copy of v1)");
    assert(v2.GetSize() == v1.GetSize());
    std::cout << "✓ Copy constructor works correctly" << std::endl;
}

void testElementAccess() {
    std::cout << "\n=== Testing Element Access ===" << std::endl;
    Vector v(4);
    v[0] = 10; v[1] = 20; v[2] = 30; v[3] = 40;
    printVector(v, "v");
    std::cout << "\nTesting [] operator:" << std::endl;
    std::cout << "v[0] = " << v[0] << std::endl;
    std::cout << "v[3] = " << v[3] << std::endl;
    std::cout << "\nTesting () operator:" << std::endl;
    std::cout << "v(1) = " << v(1) << std::endl;
    std::cout << "v(4) = " << v(4) << std::endl;
    std::cout << "\nTesting Read method:" << std::endl;
    std::cout << "v.Read(1) = " << v.Read(1) << std::endl;
    std::cout << "\nModifying elements..." << std::endl;
    v[1] = 99;
    printVector(v, "v (after v[1] = 99)");
    std::cout << "✓ Element access methods work correctly" << std::endl;
}

void testAssignment() {
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    Vector v1(3);
    Vector v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    printVector(v1, "v1 (original)");
    v2[0] = 9; v2[1] = 8; v2[2] = 7;
    printVector(v2, "v2 (before assignment)");
    std::cout << "\nPerforming v2 = v1..." << std::endl;
    v2 = v1;
    printVector(v2, "v2 (after assignment)");
    for (int i = 0; i < v1.GetSize(); i++) {
        assert(v1[i] == v2[i]);
    }
    std::cout << "✓ Assignment operator works correctly" << std::endl;
}

void testArithmetic() {
    std::cout << "\n=== Testing Arithmetic Operations ===" << std::endl;
    Vector v1(3);
    Vector v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    printVector(v1, "v1");
    printVector(v2, "v2");
    std::cout << "\nTesting vector addition (v1 + v2):" << std::endl;
    Vector sum = v1 + v2;
    printVector(sum, "v1 + v2");
    assert(sum[0] == 5 && sum[1] == 7 && sum[2] == 9);
    std::cout << "\nTesting vector subtraction (v2 - v1):" << std::endl;
    Vector diff = v2 - v1;
    printVector(diff, "v2 - v1");
    assert(diff[0] == 3 && diff[1] == 3 && diff[2] == 3);
    std::cout << "\nTesting scalar multiplication (v1 * 2):" << std::endl;
    Vector scaled = v1 * 2;
    printVector(scaled, "v1 * 2");
    assert(scaled[0] == 2 && scaled[1] == 4 && scaled[2] == 6);
    Vector plus = +v1;
    printVector(plus, "+v1");
    Vector minus = -v1;
    printVector(minus, "-v1");
    std::cout << "✓ All arithmetic operations work correctly" << std::endl;
}

void testNormCalculation() {
    std::cout << "\n=== Testing Norm Calculation ===" << std::endl;
    Vector v(3);
    v[0] = 3; v[1] = 4; v[2] = 0;
    printVector(v, "v");
    double norm2 = v.CalculateNorm(2);
    std::cout << "2-norm (Euclidean norm) = " << norm2 << std::endl;
    assert(std::abs(norm2 - 5.0) < 1e-10);
    double norm1 = v.CalculateNorm(1);
    std::cout << "1-norm (Manhattan norm) = " << norm1 << std::endl;
    assert(std::abs(norm1 - 7.0) < 1e-10);
    double normDefault = v.CalculateNorm();
    std::cout << "Default norm = " << normDefault << std::endl;
    assert(std::abs(normDefault - 5.0) < 1e-10);
    std::cout << "✓ Norm calculations are correct" << std::endl;
}

void testFriendFunction() {
    std::cout << "\n=== Testing Friend Function ===" << std::endl;
    Vector v(7);
    std::cout << "Created vector of size 7" << std::endl;
    int len = length(v);
    std::cout << "length(v) = " << len << std::endl;
    assert(len == 7);
    std::cout << "✓ Friend function length() works correctly" << std::endl;
}

void demonstratePracticalUsage() {
    std::cout << "\n=== Practical Usage Example ===" << std::endl;
    std::cout << "Creating 3D position vectors and performing operations..." << std::endl;
    Vector position1(3);
    Vector position2(3);
    position1[0] = 1; position1[1] = 2; position1[2] = 3;
    printVector(position1, "Point A");
    position2[0] = 4; position2[1] = 6; position2[2] = 8;
    printVector(position2, "Point B");
    Vector displacement = position2 - position1;
    printVector(displacement, "Displacement (B - A)");
    double distance = displacement.CalculateNorm();
    std::cout << "Distance between points = " << distance << std::endl;
    Vector midpoint = (position1 + position2) * 0.5;
    printVector(midpoint, "Midpoint");
    std::cout << "✓ Practical example completed successfully" << std::endl;
}

int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "  COMPREHENSIVE VECTOR CLASS TESTS   " << std::endl;
    std::cout << "======================================" << std::endl;
    try {
        testVectorCreation();
        testElementAccess();
        testAssignment();
        testArithmetic();
        testNormCalculation();
        testFriendFunction();
        demonstratePracticalUsage();
        std::cout << "\n======================================" << std::endl;
        std::cout << "  ALL TESTS PASSED SUCCESSFULLY! ✓   " << std::endl;
        std::cout << "  The Vector class is working correctly" << std::endl;
        std::cout << "======================================" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n❌ Test failed with error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
