#include "ForwardEulerSolver.hpp"
#include <stdexcept>
#include <iostream>

ForwardEulerSolver::ForwardEulerSolver() : AbstractOdeSolver() {
}

std::vector<double> ForwardEulerSolver::SolveEquation() {
    // Check if all parameters are set
    if (stepSize <= 0.0) {
        throw std::runtime_error("Step size must be set and positive");
    }
    if (!rightHandSide) {
        throw std::runtime_error("Right-hand side function must be set");
    }
    
    // Calculate number of steps
    int numSteps = static_cast<int>((finalTime - initialTime) / stepSize);
    std::vector<double> solution;
    solution.reserve(numSteps + 1);
    
    // Set initial conditions
    double t = initialTime;
    double y = initialValue;
    solution.push_back(y);
    
    // Apply Forward Euler method: y_{i+1} = y_i + h * f(t_i, y_i)
    for (int i = 0; i < numSteps; ++i) {
        y = y + stepSize * rightHandSide(t, y);
        t = initialTime + (i + 1) * stepSize;
        solution.push_back(y);
    }
    
    return solution;
}

void ForwardEulerSolver::WriteToFile(const std::vector<double>& solution, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }
    
    file << "# Time\tSolution\n";
    for (size_t i = 0; i < solution.size(); ++i) {
        double t = initialTime + i * stepSize;
        file << t << "\t" << solution[i] << "\n";
    }
    
    file.close();
    std::cout << "Solution written to file: " << filename << std::endl;
}
