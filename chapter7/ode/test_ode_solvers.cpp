#include "ForwardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

// Define the right-hand side function: dy/dt = 1 + t
double rightHandSideFunction(double t, double y) {
    return 1.0 + t;
}

// Analytical solution for comparison: y(t) = t + t²/2 + 2
double analyticalSolution(double t) {
    return t + t*t/2.0 + 2.0;
}

void compareResults(const std::vector<double>& numerical, double stepSize, 
                   double initialTime, const std::string& methodName) {
    std::cout << "\n" << methodName << " Results (step size = " << stepSize << "):\n";
    std::cout << std::setw(8) << "Time" << std::setw(15) << "Numerical" 
              << std::setw(15) << "Analytical" << std::setw(15) << "Error\n";
    std::cout << std::string(60, '-') << "\n";
    
    double maxError = 0.0;
    for (size_t i = 0; i < numerical.size(); ++i) {
        double t = initialTime + i * stepSize;
        double analytical = analyticalSolution(t);
        double error = std::abs(numerical[i] - analytical);
        maxError = std::max(maxError, error);
        
        // Print every 5th point to avoid too much output
        if (i % 5 == 0 || i == numerical.size() - 1) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(3) << t
                      << std::setw(15) << std::setprecision(6) << numerical[i]
                      << std::setw(15) << std::setprecision(6) << analytical
                      << std::setw(15) << std::scientific << std::setprecision(2) << error << "\n";
        }
    }
    std::cout << "Maximum error: " << std::scientific << std::setprecision(2) << maxError << "\n";
}

int main() {
    try {
        std::cout << "=== ODE Solver Testing ===\n";
        std::cout << "Solving: dy/dt = 1 + t, y(0) = 2, t ∈ [0, 1]\n";
        std::cout << "Analytical solution: y(t) = t + t²/2 + 2\n";

        // Test different step sizes
        std::vector<double> stepSizes = {0.1, 0.05, 0.01};
        
        for (double h : stepSizes) {
            std::cout << "\n" << std::string(70, '=') << "\n";
            std::cout << "Testing with step size h = " << h << "\n";
            
            // Test Forward Euler method
            ForwardEulerSolver eulerSolver;
            eulerSolver.SetStepSize(h);
            eulerSolver.SetTimeInterval(0.0, 1.0);
            eulerSolver.SetInitialValue(2.0);
            eulerSolver.SetRightHandSide(rightHandSideFunction);
            
            std::vector<double> eulerSolution = eulerSolver.SolveEquation();
            compareResults(eulerSolution, h, 0.0, "Forward Euler");
            
            // Write Euler solution to file
            std::string eulerFilename = "euler_solution_h" + std::to_string(h) + ".dat";
            eulerSolver.WriteToFile(eulerSolution, eulerFilename);
            
            // Test Runge-Kutta method
            RungeKuttaSolver rkSolver;
            rkSolver.SetStepSize(h);
            rkSolver.SetTimeInterval(0.0, 1.0);
            rkSolver.SetInitialValue(2.0);
            rkSolver.SetRightHandSide(rightHandSideFunction);
            
            std::vector<double> rkSolution = rkSolver.SolveEquation();
            compareResults(rkSolution, h, 0.0, "Runge-Kutta 4th Order");
            
            // Write RK solution to file
            std::string rkFilename = "rk_solution_h" + std::to_string(h) + ".dat";
            rkSolver.WriteToFile(rkSolution, rkFilename);
        }
        
        std::cout << "\n" << std::string(70, '=') << "\n";
        std::cout << "Analysis:\n";
        std::cout << "1. Forward Euler is a first-order method - error decreases linearly with step size\n";
        std::cout << "2. Runge-Kutta 4th order is much more accurate - error decreases as h⁴\n";
        std::cout << "3. For this simple linear ODE, RK4 gives very accurate results even with larger step sizes\n";
        std::cout << "4. Solution files have been generated for plotting and further analysis\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
