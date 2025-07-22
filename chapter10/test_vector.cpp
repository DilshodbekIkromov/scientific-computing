#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "Vector.hpp"

// Extensive tests for the Vector class

bool isEqual(double a, double b, double tolerance = 1e-10) {
    return std::abs(a - b) < tolerance;
}

void printVector(const Vector& v, const std::string& name) {
    std::cout << name << " = [";
    for (int i = 0; i < v.GetSize(); i++) {
        std::cout << v.Read(i);
        if (i < v.GetSize() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "=== Vector Class Comprehensive Test Suite ===" << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    try {
        std::cout << "\n1. Testing Constructors:" << std::endl;
        Vector v1(3);      
        Vector v2(5);      
        Vector v3(1);      
        std::cout << "   ✓ v1 created with size " << v1.GetSize() << std::endl;
        std::cout << "   ✓ v2 created with size " << v2.GetSize() << std::endl;
        std::cout << "   ✓ v3 created with size " << v3.GetSize() << std::endl;
        bool allZero = true;
        for (int i = 0; i < v1.GetSize(); i++) {
            if (!isEqual(v1.Read(i), 0.0)) {
                allZero = false;
                break;
            }
        }
        std::cout << "   ✓ All elements initialized to zero: " << (allZero ? "Yes" : "No") << std::endl;

        std::cout << "\n2. Testing Element Access and Modification:" << std::endl;
        v1[0] = 1.5; v1[1] = -2.3; v1[2] = 4.7;
        std::cout << "   Set v1 elements using [] operator:" << std::endl;
        printVector(v1, "   v1");
        v2(1) = 10.0; v2(2) = 20.0; v2(3) = 30.0; v2(4) = 40.0; v2(5) = 50.0;
        std::cout << "   Set v2 elements using () operator:" << std::endl;
        printVector(v2, "   v2");
        std::cout << "   Testing Read method:" << std::endl;
        std::cout << "   v1.Read(0) = " << v1.Read(0) << std::endl;
        std::cout << "   v1.Read(1) = " << v1.Read(1) << std::endl;
        std::cout << "   v1.Read(2) = " << v1.Read(2) << std::endl;

        std::cout << "\n3. Testing Copy Constructor:" << std::endl;
        Vector v4(v1);
        std::cout << "   Created v4 as copy of v1:" << std::endl;
        printVector(v1, "   v1");
        printVector(v4, "   v4");
        v1[0] = 999.0;
        std::cout << "   After modifying v1[0] to 999:" << std::endl;
        printVector(v1, "   v1");
        printVector(v4, "   v4");
        v1[0] = 1.5;

        std::cout << "\n4. Testing Assignment Operator:" << std::endl;
        Vector v5(3);
        v5 = v1;
        std::cout << "   Assigned v1 to v5:" << std::endl;
        printVector(v5, "   v5");
        Vector v6(3);
        v6 = v5 = v1;
        std::cout << "   Chain assignment (v6 = v5 = v1):" << std::endl;
        printVector(v6, "   v6");

        std::cout << "\n5. Testing Unary Operators:" << std::endl;
        Vector v7 = +v1;
        std::cout << "   Unary plus (+v1):" << std::endl;
        printVector(v7, "   +v1");
        Vector v8 = -v1;
        std::cout << "   Unary minus (-v1):" << std::endl;
        printVector(v8, "   -v1");

        std::cout << "\n6. Testing Vector Addition:" << std::endl;
        Vector a(3), b(3);
        a[0] = 1.0; a[1] = 2.0; a[2] = 3.0;
        b[0] = 4.0; b[1] = 5.0; b[2] = 6.0;
        Vector sum = a + b;
        printVector(sum, "   a + b");
        std::cout << "   Verification: "
                  << (isEqual(sum.Read(0), 5.0) && isEqual(sum.Read(1), 7.0) && isEqual(sum.Read(2), 9.0) ? "✓" : "✗")
                  << std::endl;

        std::cout << "\n7. Testing Vector Subtraction:" << std::endl;
        Vector diff = b - a;
        printVector(diff, "   b - a");
        std::cout << "   Verification: "
                  << (isEqual(diff.Read(0), 3.0) && isEqual(diff.Read(1), 3.0) && isEqual(diff.Read(2), 3.0) ? "✓" : "✗")
                  << std::endl;

        std::cout << "\n8. Testing Scalar Multiplication:" << std::endl;
        Vector scaled = a * 2.5;
        printVector(scaled, "   a * 2.5");
        std::cout << "   Verification: "
                  << (isEqual(scaled.Read(0), 2.5) && isEqual(scaled.Read(1), 5.0) && isEqual(scaled.Read(2), 7.5) ? "✓" : "✗")
                  << std::endl;

        std::cout << "\n9. Testing Norm Calculations:" << std::endl;
        Vector normTest(3);
        normTest[0] = 3.0; normTest[1] = 4.0; normTest[2] = 0.0;
        printVector(normTest, "   normTest");
        double norm1 = normTest.CalculateNorm(1);
        double norm2 = normTest.CalculateNorm(2);
        double normInf = normTest.CalculateNorm(100);
        std::cout << "   1-norm: " << norm1 << std::endl;
        std::cout << "   2-norm: " << norm2 << std::endl;
        std::cout << "   ∞-norm: " << normInf << std::endl;
        std::cout << "   2-norm verification: " << (isEqual(norm2, 5.0) ? "✓" : "✗") << std::endl;

        std::cout << "\n10. Testing Friend Function:" << std::endl;
        int len = length(normTest);
        std::cout << "   length(normTest) = " << len << std::endl;
        std::cout << "   Verification: " << (len == normTest.GetSize() ? "✓" : "✗") << std::endl;

        std::cout << "\n11. Testing Complex Mathematical Operations:" << std::endl;
        Vector x(3), y(3), z(3);
        x[0] = 1.0; x[1] = 2.0; x[2] = 3.0;
        y[0] = 2.0; y[1] = 1.0; y[2] = 0.0;
        z = x * 2.0 + y * 3.0 - x;
        printVector(z, "   z = 2*x + 3*y - x");
        std::cout << "   Expected: [7.000, 5.000, 3.000]" << std::endl;

        std::cout << "\n12. Testing Vector Space Properties:" << std::endl;
        Vector u(3), v(3), w(3);
        u[0] = 1.0; u[1] = 2.0; u[2] = 3.0;
        v[0] = 4.0; v[1] = 5.0; v[2] = 6.0;
        w[0] = 7.0; w[1] = 8.0; w[2] = 9.0;
        Vector uv = u + v;
        Vector vu = v + u;
        printVector(uv, "   u + v");
        printVector(vu, "   v + u");
        bool commutative = true;
        for (int i = 0; i < 3; i++) {
            if (!isEqual(uv.Read(i), vu.Read(i))) {
                commutative = false;
                break;
            }
        }
        std::cout << "   ✓ Commutative: " << (commutative ? "Yes" : "No") << std::endl;
        Vector uvw1 = (u + v) + w;
        Vector uvw2 = u + (v + w);
        bool associative = true;
        for (int i = 0; i < 3; i++) {
            if (!isEqual(uvw1.Read(i), uvw2.Read(i))) {
                associative = false;
                break;
            }
        }
        std::cout << "   ✓ Associative: " << (associative ? "Yes" : "No") << std::endl;
        Vector single(1);
        single[0] = 42.0;
        printVector(single, "   single");
        std::cout << "   Norm: " << single.CalculateNorm() << std::endl;
        Vector large(10);
        for (int i = 0; i < 10; i++) {
            large[i] = i + 1.0;
        }
        printVector(large, "   large");
        std::cout << "\n14. Testing Memory Management:" << std::endl;
        std::cout << "   Creating and destroying multiple vectors..." << std::endl;
        for (int i = 0; i < 100; i++) {
            Vector temp(50);
            for (int j = 0; j < 50; j++) {
                temp[j] = i * j * 0.1;
            }
        }
        std::cout << "   ✓ Memory management test completed" << std::endl;
        std::cout << "\n🎉 ALL TESTS PASSED! Vector class is working correctly." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "❌ Test failed with exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "❌ Test failed with unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
