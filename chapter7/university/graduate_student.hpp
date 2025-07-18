#ifndef GRADUATE_STUDENT_HPP
#define GRADUATE_STUDENT_HPP

#include "student.hpp"

class GraduateStudent : public Student {
public:
    // Constructor
    GraduateStudent(const std::string& name, double tuition_fees, bool is_full_time = true);
    
    // Destructor
    virtual ~GraduateStudent();
    
    // Methods to access full-time status
    bool IsFullTime() const;
    void SetFullTimeStatus(bool is_full_time);
    
    // Override the virtual method
    virtual double CalculateTotalMoney() const override;
    
private:
    bool mIsFullTime;
};

#endif
