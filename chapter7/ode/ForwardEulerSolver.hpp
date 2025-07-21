#ifndef FORWARDEULERSOLVER_HPP
#define FORWARDEULERSOLVER_HPP

#include "AbstractOdeSolver.hpp"
#include <fstream>

class ForwardEulerSolver : public AbstractOdeSolver {
public:
    // Constructor
    ForwardEulerSolver();
    
    // Override the pure virtual function
    std::vector<double> SolveEquation() override;
    
    // Method to write solution to file
    void WriteToFile(const std::vector<double>& solution, const std::string& filename);
};

#endif
