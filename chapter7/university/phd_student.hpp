#ifndef PHD_STUDENT_HPP
#define PHD_STUDENT_HPP

#include "graduate_student.hpp"

class PhDStudent : public GraduateStudent {
public:
    // Constructor
    PhDStudent(const std::string& name, double tuition_fees, bool is_full_time = true);
    
    // Destructor
    virtual ~PhDStudent();
    
    // Override the virtual method - PhD students don't pay library fines
    virtual double CalculateTotalMoney() const override;
};

#endif
