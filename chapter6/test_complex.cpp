#include <iostream>
#include <iomanip>
#include <cmath>
#include "ComplexNumber.hpp"

int main() {
    std::cout << "=== ComplexNumber Class Test ===" << std::endl << std::endl;
    
    // Test 1: Constructors
    std::cout << "1. Testing Constructors:" << std::endl;
    ComplexNumber z1;           // Default constructor
    ComplexNumber z2(3, 4);     // Parameterized constructor  
    ComplexNumber z3(-2, -5);   // Negative values
    ComplexNumber z4(0, 1);     // Pure imaginary
    ComplexNumber z5(7, 0);     // Pure real
    
    std::cout << "z1 (default): " << z1 << std::endl;
    std::cout << "z2 (3, 4): " << z2 << std::endl;
    std::cout << "z3 (-2, -5): " << z3 << std::endl;
    std::cout << "z4 (0, 1): " << z4 << std::endl;
    std::cout << "z5 (7, 0): " << z5 << std::endl << std::endl;
    
    // Test 2: Modulus and Argument
    std::cout << "2. Testing Modulus and Argument:" << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "  Modulus: " << z2.CalculateModulus() << std::endl;
    std::cout << "  Argument: " << z2.CalculateArgument() << " radians" << std::endl;
    std::cout << "  Argument: " << z2.CalculateArgument() * 180.0 / M_PI << " degrees" << std::endl;
    
    // Test known values
    ComplexNumber z_test(1, 1);  // Should have modulus = sqrt(2), argument = 45°
    std::cout << "\nz_test = " << z_test << std::endl;
    std::cout << "  Modulus: " << z_test.CalculateModulus() << " (should be ~1.414)" << std::endl;
    std::cout << "  Argument: " << z_test.CalculateArgument() * 180.0 / M_PI << "° (should be 45°)" << std::endl << std::endl;
    
    // Test 3: Assignment Operator
    std::cout << "3. Testing Assignment Operator:" << std::endl;
    ComplexNumber z6;
    z6 = z2;
    std::cout << "z6 = z2: " << z6 << std::endl;
    
    // Test chaining
    ComplexNumber z7, z8;
    z7 = z8 = z2;
    std::cout << "z7 = z8 = z2: z7 = " << z7 << ", z8 = " << z8 << std::endl << std::endl;
    
    // Test 4: Unary Minus
    std::cout << "4. Testing Unary Minus:" << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "-z2 = " << (-z2) << std::endl;
    std::cout << "z3 = " << z3 << std::endl;
    std::cout << "-z3 = " << (-z3) << std::endl << std::endl;
    
    // Test 5: Addition
    std::cout << "5. Testing Addition:" << std::endl;
    ComplexNumber sum1 = z2 + z3;
    ComplexNumber sum2 = z4 + z5;
    std::cout << "z2 + z3 = " << z2 << " + " << z3 << " = " << sum1 << std::endl;
    std::cout << "z4 + z5 = " << z4 << " + " << z5 << " = " << sum2 << std::endl << std::endl;
    
    // Test 6: Subtraction
    std::cout << "6. Testing Subtraction:" << std::endl;
    ComplexNumber diff1 = z2 - z3;
    ComplexNumber diff2 = z5 - z4;
    std::cout << "z2 - z3 = " << z2 << " - " << z3 << " = " << diff1 << std::endl;
    std::cout << "z5 - z4 = " << z5 << " - " << z4 << " = " << diff2 << std::endl << std::endl;
    
    // Test 7: Powers
    std::cout << "7. Testing Powers:" << std::endl;
    ComplexNumber base(1, 1);  // 1 + i
    std::cout << "base = " << base << std::endl;
    
    for (int n = 0; n <= 4; n++) {
        ComplexNumber power = base.CalculatePower(n);
        std::cout << "base^" << n << " = " << power << std::endl;
    }
    
    // Test fractional powers
    ComplexNumber sqrt_result = base.CalculatePower(0.5);
    std::cout << "base^0.5 = " << sqrt_result << std::endl << std::endl;
    
    // Test 8: Mathematical Properties
    std::cout << "8. Testing Mathematical Properties:" << std::endl;
    
    ComplexNumber a(2, 3);
    ComplexNumber b(1, -2);
    ComplexNumber c(-1, 4);
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    
    // Commutative property: a + b = b + a
    ComplexNumber ab = a + b;
    ComplexNumber ba = b + a;
    std::cout << "\nCommutative property (a + b = b + a):" << std::endl;
    std::cout << "a + b = " << ab << std::endl;
    std::cout << "b + a = " << ba << std::endl;
    
    // Associative property: (a + b) + c = a + (b + c)
    ComplexNumber abc1 = (a + b) + c;
    ComplexNumber abc2 = a + (b + c);
    std::cout << "\nAssociative property ((a + b) + c = a + (b + c)):" << std::endl;
    std::cout << "(a + b) + c = " << abc1 << std::endl;
    std::cout << "a + (b + c) = " << abc2 << std::endl;
    
    // Distributive-like: a - b = a + (-b)
    ComplexNumber sub1 = a - b;
    ComplexNumber sub2 = a + (-b);
    std::cout << "\nSubtraction property (a - b = a + (-b)):" << std::endl;
    std::cout << "a - b = " << sub1 << std::endl;
    std::cout << "a + (-b) = " << sub2 << std::endl << std::endl;
    
    // Test 9: Edge Cases
    std::cout << "9. Testing Edge Cases:" << std::endl;
    
    ComplexNumber zero(0, 0);
    ComplexNumber real_only(5, 0);
    ComplexNumber imag_only(0, -3);
    
    std::cout << "zero = " << zero << std::endl;
    std::cout << "zero modulus = " << zero.CalculateModulus() << std::endl;
    std::cout << "real_only = " << real_only << std::endl;
    std::cout << "imag_only = " << imag_only << std::endl;
    
    // Powers of zero and one
    ComplexNumber one(1, 0);
    std::cout << "1^5 = " << one.CalculatePower(5) << std::endl;
    std::cout << "i^2 = " << z4.CalculatePower(2) << " (should be -1)" << std::endl;
    std::cout << "i^4 = " << z4.CalculatePower(4) << " (should be 1)" << std::endl << std::endl;
    
    // Test 10: Complex Expressions
    std::cout << "10. Testing Complex Expressions:" << std::endl;
    ComplexNumber expr1 = (a + b) - (c + a);  // Should equal b - c
    ComplexNumber expr2 = b - c;
    std::cout << "(a + b) - (c + a) = " << expr1 << std::endl;
    std::cout << "b - c = " << expr2 << std::endl;
    
    // Chain operations
    ComplexNumber chain = a + b - c + (-a);  // Should equal b - c
    std::cout << "a + b - c + (-a) = " << chain << std::endl << std::endl;
    
    std::cout << "=== All Tests Completed! ===" << std::endl;
    
    return 0;
}
