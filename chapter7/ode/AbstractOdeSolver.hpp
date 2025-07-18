#ifndef ABSTRACTODESOLVER_HPP
#define ABSTRACTODESOLVER_HPP

#include <vector>
#include <functional>

class AbstractOdeSolver {
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
    std::function<double(double, double)> rightHandSide;
    
public:
    // Constructor
    AbstractOdeSolver();
    
    // Virtual destructor
    virtual ~AbstractOdeSolver() = default;
    
    // Set methods for problem parameters
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    void SetRightHandSide(std::function<double(double, double)> f);
    
    // Pure virtual method that derived classes must implement
    virtual std::vector<double> SolveEquation() = 0;
    
    // Get methods for accessing private data
    double GetStepSize() const;
    double GetInitialTime() const;
    double GetFinalTime() const;
    double GetInitialValue() const;
};

#endif
