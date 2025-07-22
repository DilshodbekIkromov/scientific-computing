#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector.hpp"

/**
 * Comprehensive test program for the Vector class
 * This program tests all functionality of the Vector class with clear explanations
 * for beginners to understand what each operation does.
 */

// Function to print a vector's contents for visualization
void printVector(const Vector& v, const std::string& name) {
    std::cout << name << " = [";
    for (int i = 0; i < v.GetSize(); i++) {
        std::cout << v.Read(i);
        if (i < v.GetSize() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Function to test basic vector creation and initialization
void testVectorCreation() {
    std::cout << "\n=== Testing Vector Creation ===" << std::endl;
    
    // Test 1: Create a vector of size 5 (all elements initialized to 0)
    std::cout << "Creating a vector of size 5..." << std::endl;
    Vector v1(5);
    printVector(v1, "v1");
    assert(v1.GetSize() == 5);
    std::cout << "✓ Vector created successfully with size: " << v1.GetSize() << std::endl;
    
    // Test 2: Fill the vector with some values
    std::cout << "\nFilling vector with values 1, 2, 3, 4, 5..." << std::endl;
    for (int i = 0; i < v1.GetSize(); i++) {
        v1[i] = i + 1;  // Fill with values 1, 2, 3, 4, 5
    }
    printVector(v1, "v1 (after filling)");
    
    // Test 3: Test copy constructor (create a new vector by copying v1)
    std::cout << "\nTesting copy constructor..." << std::endl;
    Vector v2(v1);  // This calls the copy constructor
    printVector(v2, "v2 (copy of v1)");
    assert(v2.GetSize() == v1.GetSize());
    std::cout << "✓ Copy constructor works correctly" << std::endl;
}

// Function to test element access methods
void testElementAccess() {
    std::cout << "\n=== Testing Element Access ===" << std::endl;
    
    Vector v(4);
    // Fill vector with values 10, 20, 30, 40
    v[0] = 10; v[1] = 20; v[2] = 30; v[3] = 40;
    printVector(v, "v");
    
    // Test 1: Using [] operator (0-based indexing)
    std::cout << "\nTesting [] operator (0-based indexing):" << std::endl;
    std::cout << "v[0] = " << v[0] << " (first element)" << std::endl;
    std::cout << "v[3] = " << v[3] << " (last element)" << std::endl;
    
    // Test 2: Using () operator (1-based indexing)
    std::cout << "\nTesting () operator (1-based indexing):" << std::endl;
    std::cout << "v(1) = " << v(1) << " (first element, 1-based)" << std::endl;
    std::cout << "v(4) = " << v(4) << " (last element, 1-based)" << std::endl;
    
    // Test 3: Using Read method (read-only access)
    std::cout << "\nTesting Read method (read-only):" << std::endl;
    std::cout << "v.Read(1) = " << v.Read(1) << " (second element)" << std::endl;
    
    // Test 4: Modifying elements
    std::cout << "\nModifying elements..." << std::endl;
    v[1] = 99;  // Change second element to 99
    printVector(v, "v (after v[1] = 99)");
    std::cout << "✓ Element access methods work correctly" << std::endl;
}

// Function to test assignment operator
void testAssignment() {
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    
    // Create two vectors of the same size
    Vector v1(3);
    Vector v2(3);
    
    // Fill v1 with values
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    printVector(v1, "v1 (original)");
    
    // Fill v2 with different values
    v2[0] = 9; v2[1] = 8; v2[2] = 7;
    printVector(v2, "v2 (before assignment)");
    
    // Assign v1 to v2
    std::cout << "\nPerforming v2 = v1..." << std::endl;
    v2 = v1;  // This calls the assignment operator
    printVector(v2, "v2 (after assignment)");
    
    // Verify the assignment worked
    for (int i = 0; i < v1.GetSize(); i++) {
        assert(v1[i] == v2[i]);
    }
    std::cout << "✓ Assignment operator works correctly" << std::endl;
}

// Function to test arithmetic operations
void testArithmetic() {
    std::cout << "\n=== Testing Arithmetic Operations ===" << std::endl;
    
    // Create two vectors for testing
    Vector v1(3);
    Vector v2(3);
    
    // Fill vectors with test values
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    
    printVector(v1, "v1");
    printVector(v2, "v2");
    
    // Test 1: Vector addition
    std::cout << "\nTesting vector addition (v1 + v2):" << std::endl;
    Vector sum = v1 + v2;  // Add corresponding elements: [1+4, 2+5, 3+6] = [5, 7, 9]
    printVector(sum, "v1 + v2");
    assert(sum[0] == 5 && sum[1] == 7 && sum[2] == 9);
    
    // Test 2: Vector subtraction
    std::cout << "\nTesting vector subtraction (v2 - v1):" << std::endl;
    Vector diff = v2 - v1;  // Subtract corresponding elements: [4-1, 5-2, 6-3] = [3, 3, 3]
    printVector(diff, "v2 - v1");
    assert(diff[0] == 3 && diff[1] == 3 && diff[2] == 3);
    
    // Test 3: Scalar multiplication
    std::cout << "\nTesting scalar multiplication (v1 * 2):" << std::endl;
    Vector scaled = v1 * 2;  // Multiply each element by 2: [1*2, 2*2, 3*2] = [2, 4, 6]
    printVector(scaled, "v1 * 2");
    assert(scaled[0] == 2 && scaled[1] == 4 && scaled[2] == 6);
    
    // Test 4: Unary plus (creates a copy)
    std::cout << "\nTesting unary plus (+v1):" << std::endl;
    Vector plus = +v1;  // Creates a positive copy of v1
    printVector(plus, "+v1");
    
    // Test 5: Unary minus (negates all elements)
    std::cout << "\nTesting unary minus (-v1):" << std::endl;
    Vector minus = -v1;  // Negates each element: [-1, -2, -3]
    printVector(minus, "-v1");
    assert(minus[0] == -1 && minus[1] == -2 && minus[2] == -3);
    
    std::cout << "✓ All arithmetic operations work correctly" << std::endl;
}

// Function to test norm calculation
void testNormCalculation() {
    std::cout << "\n=== Testing Norm Calculation ===" << std::endl;
    
    // Create a vector with known values for easy norm calculation
    Vector v(3);
    v[0] = 3; v[1] = 4; v[2] = 0;  // 3-4-0 triangle (Pythagorean triple)
    printVector(v, "v");
    
    // Test 1: Calculate 2-norm (Euclidean norm)
    // For vector [3, 4, 0]: 2-norm = sqrt(3² + 4² + 0²) = sqrt(9 + 16 + 0) = sqrt(25) = 5
    double norm2 = v.CalculateNorm(2);
    std::cout << "2-norm (Euclidean norm) = " << norm2 << std::endl;
    assert(std::abs(norm2 - 5.0) < 1e-10);  // Should be exactly 5
    
    // Test 2: Calculate 1-norm (Manhattan norm)
    // For vector [3, 4, 0]: 1-norm = |3| + |4| + |0| = 3 + 4 + 0 = 7
    double norm1 = v.CalculateNorm(1);
    std::cout << "1-norm (Manhattan norm) = " << norm1 << std::endl;
    assert(std::abs(norm1 - 7.0) < 1e-10);  // Should be exactly 7
    
    // Test 3: Default norm (should be 2-norm)
    double normDefault = v.CalculateNorm();
    std::cout << "Default norm = " << normDefault << std::endl;
    assert(std::abs(normDefault - 5.0) < 1e-10);  // Should be same as 2-norm
    
    std::cout << "✓ Norm calculations are correct" << std::endl;
}

// Function to test friend function
void testFriendFunction() {
    std::cout << "\n=== Testing Friend Function ===" << std::endl;
    
    Vector v(7);
    std::cout << "Created vector of size 7" << std::endl;
    
    // Test the friend function length()
    int len = length(v);
    std::cout << "length(v) = " << len << std::endl;
    assert(len == 7);
    
    std::cout << "✓ Friend function length() works correctly" << std::endl;
}

// Function to demonstrate practical vector operations
void demonstratePracticalUsage() {
    std::cout << "\n=== Practical Usage Example ===" << std::endl;
    std::cout << "Creating 3D position vectors and performing operations..." << std::endl;
    
    // Create 3D position vectors
    Vector position1(3);  // Point A
    Vector position2(3);  // Point B
    
    // Set coordinates for point A: (1, 2, 3)
    position1[0] = 1; position1[1] = 2; position1[2] = 3;
    printVector(position1, "Point A");
    
    // Set coordinates for point B: (4, 6, 8)
    position2[0] = 4; position2[1] = 6; position2[2] = 8;
    printVector(position2, "Point B");
    
    // Calculate displacement vector from A to B
    Vector displacement = position2 - position1;
    printVector(displacement, "Displacement (B - A)");
    
    // Calculate distance between points (magnitude of displacement)
    double distance = displacement.CalculateNorm();
    std::cout << "Distance between points = " << distance << std::endl;
    
    // Calculate midpoint
    Vector midpoint = (position1 + position2) * 0.5;
    printVector(midpoint, "Midpoint");
    
    std::cout << "✓ Practical example completed successfully" << std::endl;
}

// Main function that runs all tests
int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "  COMPREHENSIVE VECTOR CLASS TESTS   " << std::endl;
    std::cout << "======================================" << std::endl;
    
    try {
        // Run all test functions
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
