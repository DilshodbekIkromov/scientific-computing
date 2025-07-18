#include "student.hpp"
#include "graduate_student.hpp"
#include "phd_student.hpp"
#include <iostream>

int main() {
    std::cout << "University Student System - Exercise 7.1" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
    
    // Test 1: Regular Student
    Student student1("John Doe", 3000.0);
    student1.SetLibraryFines(25.0);
    std::cout << "Regular Student:" << std::endl;
    std::cout << "  Total owed: $" << student1.GetTotalMoneyOwed() << std::endl << std::endl;
    
    // Test 2: Graduate Student (Full-time)
    GraduateStudent gradStudent("Jane Smith", 5000.0, true);
    gradStudent.SetLibraryFines(15.0);
    std::cout << "Graduate Student (Full-time):" << std::endl;
    std::cout << "  Is full-time: " << (gradStudent.IsFullTime() ? "Yes" : "No") << std::endl;
    std::cout << "  Total owed: $" << gradStudent.GetTotalMoneyOwed() << std::endl << std::endl;
    
    // Test 3: PhD Student (no library fines)
    PhDStudent phdStudent("Dr. Wilson", 8000.0);
    phdStudent.SetLibraryFines(100.0); // This won't count for PhD students
    std::cout << "PhD Student:" << std::endl;
    std::cout << "  Library fines set: $" << phdStudent.GetLibraryFines() << std::endl;
    std::cout << "  Total owed (polymorphic): $" << phdStudent.CalculateTotalMoney() << std::endl;
    std::cout << "  (PhD students don't pay library fines)" << std::endl;
    
    return 0;
}
