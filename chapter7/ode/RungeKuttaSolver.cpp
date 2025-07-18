#include "RungeKuttaSolver.hpp"
#include <stdexcept>
#include <iostream>

RungeKuttaSolver::RungeKuttaSolver() : AbstractOdeSolver() {
}

std::vector<double> RungeKuttaSolver::SolveEquation() {
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
    
    // Apply Fourth-order Runge-Kutta method
    for (int i = 0; i < numSteps; ++i) {
        // Calculate the four k values
        double k1 = stepSize * rightHandSide(t, y);
        double k2 = stepSize * rightHandSide(t + stepSize/2.0, y + k1/2.0);
        double k3 = stepSize * rightHandSide(t + stepSize/2.0, y + k2/2.0);
        double k4 = stepSize * rightHandSide(t + stepSize, y + k3);
        
        // Update y using weighted average: y_{i+1} = y_i + (k1 + 2k2 + 2k3 + k4)/6
        y = y + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
        t = initialTime + (i + 1) * stepSize;
        solution.push_back(y);
    }
    
    return solution;
}

void RungeKuttaSolver::WriteToFile(const std::vector<double>& solution, const std::string& filename) {
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
