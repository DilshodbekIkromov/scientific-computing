#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    // Constructor
    Student(const std::string& name, double tuition_fees);
    
    // Destructor
    virtual ~Student();
    
    // Public methods
    double GetTotalMoneyOwed() const;
    void SetLibraryFines(double fines);
    double GetLibraryFines() const;
    
    // Virtual method for polymorphism
    virtual double CalculateTotalMoney() const;
    
protected:
    std::string mName;
    double mTuitionFees;
    
private:
    double mLibraryFines;
};

#endif
