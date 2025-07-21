#include "phd_student.hpp"

// Constructor
PhDStudent::PhDStudent(const std::string& name, double tuition_fees, bool is_full_time)
    : GraduateStudent(name, tuition_fees, is_full_time) {
}

// Destructor
PhDStudent::~PhDStudent() {
}

// Override virtual method - PhD students don't pay library fines
double PhDStudent::CalculateTotalMoney() const {
    // PhD students only owe tuition fees, no library fines
    return mTuitionFees;
}
