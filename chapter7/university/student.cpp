#include "student.hpp"
#include <stdexcept>

// Constructor
Student::Student(const std::string& name, double tuition_fees)
    : mName(name), mTuitionFees(tuition_fees), mLibraryFines(0.0) {
}

// Destructor
Student::~Student() {
}

// Method to get total money owed (library fines + tuition fees)
double Student::GetTotalMoneyOwed() const {
    return mLibraryFines + mTuitionFees;
}

// Method to set library fines (with validation for non-negative values)
void Student::SetLibraryFines(double fines) {
    if (fines < 0.0) {
        throw std::invalid_argument("Library fines must be non-negative");
    }
    mLibraryFines = fines;
}

// Method to access private library fines variable
double Student::GetLibraryFines() const {
    return mLibraryFines;
}

// Virtual method for calculating total money owed
double Student::CalculateTotalMoney() const {
    return GetTotalMoneyOwed();
}
