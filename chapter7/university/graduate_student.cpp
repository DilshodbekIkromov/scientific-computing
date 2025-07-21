#include "graduate_student.hpp"

// Constructor
GraduateStudent::GraduateStudent(const std::string& name, double tuition_fees, bool is_full_time)
    : Student(name, tuition_fees), mIsFullTime(is_full_time) {
}

// Destructor
GraduateStudent::~GraduateStudent() {
}

// Method to check if student is full-time
bool GraduateStudent::IsFullTime() const {
    return mIsFullTime;
}

// Method to set full-time status
void GraduateStudent::SetFullTimeStatus(bool is_full_time) {
    mIsFullTime = is_full_time;
}

// Override virtual method for calculating total money owed
double GraduateStudent::CalculateTotalMoney() const {
    return GetTotalMoneyOwed();
}
