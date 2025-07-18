#ifndef RUNGEKUTTASOLVER_HPP
#define RUNGEKUTTASOLVER_HPP

#include "AbstractOdeSolver.hpp"
#include <fstream>

class RungeKuttaSolver : public AbstractOdeSolver {
public:
    // Constructor
    RungeKuttaSolver();
    
    // Override the pure virtual function
    std::vector<double> SolveEquation() override;
    
    // Method to write solution to file
    void WriteToFile(const std::vector<double>& solution, const std::string& filename);
};

#endif
