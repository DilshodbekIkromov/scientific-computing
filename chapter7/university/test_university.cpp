#include "student.hpp"
#include "graduate_student.hpp"
#include "phd_student.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "=== University Student Management System ===" << std::endl << std::endl;
    
    // Create different types of students
    Student regular_student("Alice Johnson", 5000.0);
    GraduateStudent grad_student_full("Bob Smith", 8000.0, true);
    GraduateStudent grad_student_part("Carol Wilson", 4000.0, false);
    PhDStudent phd_student("David Brown", 12000.0);
    
    // Set some library fines
    regular_student.SetLibraryFines(25.50);
    grad_student_full.SetLibraryFines(15.75);
    grad_student_part.SetLibraryFines(30.00);
    phd_student.SetLibraryFines(50.00); // This won't affect total for PhD student
    
    std::cout << "=== Regular Student ===" << std::endl;
    std::cout << "Library fines: $" << regular_student.GetLibraryFines() << std::endl;
    std::cout << "Total money owed: $" << regular_student.GetTotalMoneyOwed() << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== Graduate Student (Full-time) ===" << std::endl;
    std::cout << "Is full-time: " << (grad_student_full.IsFullTime() ? "Yes" : "No") << std::endl;
    std::cout << "Library fines: $" << grad_student_full.GetLibraryFines() << std::endl;
    std::cout << "Total money owed: $" << grad_student_full.GetTotalMoneyOwed() << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== Graduate Student (Part-time) ===" << std::endl;
    std::cout << "Is full-time: " << (grad_student_part.IsFullTime() ? "Yes" : "No") << std::endl;
    std::cout << "Library fines: $" << grad_student_part.GetLibraryFines() << std::endl;
    std::cout << "Total money owed: $" << grad_student_part.GetTotalMoneyOwed() << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== PhD Student ===" << std::endl;
    std::cout << "Is full-time: " << (phd_student.IsFullTime() ? "Yes" : "No") << std::endl;
    std::cout << "Library fines: $" << phd_student.GetLibraryFines() << std::endl;
    std::cout << "Total money owed (without library fines): $" << phd_student.CalculateTotalMoney() << std::endl;
    std::cout << "Note: PhD students don't pay library fines!" << std::endl;
    std::cout << std::endl;
    
    // Demonstrate polymorphism
    std::cout << "=== Polymorphism Demonstration ===" << std::endl;
    std::vector<std::unique_ptr<Student>> students;
    students.push_back(std::make_unique<Student>("Eve Davis", 3000.0));
    students.push_back(std::make_unique<GraduateStudent>("Frank Miller", 6000.0, true));
    students.push_back(std::make_unique<PhDStudent>("Grace Lee", 10000.0));
    
    // Set library fines for all
    students[0]->SetLibraryFines(20.0);
    students[1]->SetLibraryFines(35.0);
    students[2]->SetLibraryFines(45.0);
    
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << (i + 1) << " total money owed: $" 
                  << students[i]->CalculateTotalMoney() << std::endl;
    }
    
    return 0;
}
