#include <iostream>
#include <iomanip>
#include "shape/shape.hpp"
#include "shape/circle.hpp"
#include "shape/rectangle.hpp"

int main() {
    std::cout << "=== Shape Testing Program ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    // Test Circle
    std::cout << "\n--- Testing Circle ---" << std::endl;
    circle c1(5.0);
    std::cout << "Circle with radius 5.0:" << std::endl;
    std::cout << "Area: " << c1.area() << std::endl;
    std::cout << "Perimeter: " << c1.periemetr() << std::endl;
    c1.printInfo();
    
    std::cout << "\n--- Testing Another Circle ---" << std::endl;
    circle c2(3.5);
    std::cout << "Circle with radius 3.5:" << std::endl;
    std::cout << "Area: " << c2.area() << std::endl;
    std::cout << "Perimeter: " << c2.periemetr() << std::endl;
    c2.printInfo();
    
    // Test Rectangle
    std::cout << "\n--- Testing Rectangle ---" << std::endl;
    rectangle r1(4.0, 6.0);
    std::cout << "Rectangle with width 4.0 and height 6.0:" << std::endl;
    std::cout << "Area: " << r1.area() << std::endl;
    std::cout << "Perimeter: " << r1.periemetr() << std::endl;
    r1.printInfo();
    
    std::cout << "\n--- Testing Another Rectangle ---" << std::endl;
    rectangle r2(2.5, 8.0);
    std::cout << "Rectangle with width 2.5 and height 8.0:" << std::endl;
    std::cout << "Area: " << r2.area() << std::endl;
    std::cout << "Perimeter: " << r2.periemetr() << std::endl;
    r2.printInfo();
    
    // Test Polymorphism
    std::cout << "\n--- Testing Polymorphism ---" << std::endl;
    shape* shapes[4] = {
        new circle(2.0),
        new rectangle(3.0, 4.0),
        new circle(1.5),
        new rectangle(5.0, 2.0)
    };
    
    for (int i = 0; i < 4; i++) {
        std::cout << "\nShape " << (i + 1) << ":" << std::endl;
        shapes[i]->printInfo();
    }
    
    // Clean up memory
    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }
    
    std::cout << "\n=== Testing Complete ===" << std::endl;
    return 0;
}
