# ODE Solver Exercise - Detailed Analysis

## Problem Statement
We solved the initial value problem:
- **Differential Equation**: dy/dt = 1 + t
- **Initial Condition**: y(0) = 2  
- **Time Interval**: [0, 1]
- **Analytical Solution**: y(t) = t + t²/2 + 2

## Implementation Overview

### 1. Abstract Base Class (AbstractOdeSolver)
```cpp
class AbstractOdeSolver {
protected:
    double stepSize, initialTime, finalTime, initialValue;
    std::function<double(double, double)> rightHandSide;
public:
    virtual std::vector<double> SolveEquation() = 0;  // Pure virtual
    // Setter/getter methods for parameters
};
```

**Key Features:**
- Uses polymorphism with pure virtual function
- Encapsulates common ODE parameters
- Uses std::function for flexible right-hand side specification

### 2. Forward Euler Method (ForwardEulerSolver)
**Formula**: y_{i+1} = y_i + h * f(t_i, y_i)

**Implementation Logic:**
```cpp
for (int i = 0; i < numSteps; ++i) {
    y = y + stepSize * rightHandSide(t, y);
    t = initialTime + (i + 1) * stepSize;
    solution.push_back(y);
}
```

**Characteristics:**
- First-order method (error ∝ h)
- Simple and fast
- Less accurate for larger step sizes

### 3. Runge-Kutta 4th Order Method (RungeKuttaSolver)
**Formula**: y_{i+1} = y_i + (k1 + 2k2 + 2k3 + k4)/6

Where:
- k1 = h * f(t_i, y_i)
- k2 = h * f(t_i + h/2, y_i + k1/2)
- k3 = h * f(t_i + h/2, y_i + k2/2)  
- k4 = h * f(t_i + h, y_i + k3)

**Implementation Logic:**
```cpp
double k1 = stepSize * rightHandSide(t, y);
double k2 = stepSize * rightHandSide(t + stepSize/2.0, y + k1/2.0);
double k3 = stepSize * rightHandSide(t + stepSize/2.0, y + k2/2.0);
double k4 = stepSize * rightHandSide(t + stepSize, y + k3);
y = y + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
```

**Characteristics:**
- Fourth-order method (error ∝ h⁴)
- More computationally expensive (4 function evaluations per step)
- Much higher accuracy

## Results Analysis

### Error Comparison by Step Size:

| Step Size | Forward Euler Max Error | Runge-Kutta Max Error |
|-----------|------------------------|----------------------|
| h = 0.1   | 5.00e-02              | 8.88e-16             |
| h = 0.05  | 2.50e-02              | 8.88e-16             |
| h = 0.01  | 5.00e-03              | 4.44e-16             |

### Key Observations:

1. **Forward Euler Error Scaling:**
   - h = 0.1 → error = 0.05
   - h = 0.05 → error = 0.025 (half the step size, half the error)
   - h = 0.01 → error = 0.005 (1/10 step size, 1/10 error)
   - **Confirms O(h) convergence rate**

2. **Runge-Kutta Performance:**
   - Achieves machine precision (~10⁻¹⁶) for all step sizes
   - For this linear ODE, RK4 is essentially exact
   - Demonstrates O(h⁴) theoretical accuracy

3. **Computational Efficiency:**
   - Forward Euler: 1 function evaluation per step
   - Runge-Kutta: 4 function evaluations per step
   - For this problem, RK4's superior accuracy justifies the extra cost

## Why Runge-Kutta is So Accurate Here

For the linear ODE dy/dt = 1 + t, the Runge-Kutta method performs exceptionally well because:

1. **Linear Function**: f(t,y) = 1 + t doesn't depend on y
2. **Polynomial Solution**: The exact solution y(t) = t + t²/2 + 2 is a polynomial
3. **RK4 Exact for Polynomials**: Fourth-order methods are exact for polynomials up to degree 4

## Practical Applications

This implementation demonstrates several important OOP and numerical concepts:

### Object-Oriented Design Benefits:
- **Polymorphism**: Can switch between methods without changing client code
- **Encapsulation**: Method details hidden from users
- **Extensibility**: Easy to add new ODE methods (e.g., Adams-Bashforth)

### Numerical Method Selection:
- **Forward Euler**: Good for quick prototyping, educational purposes
- **Runge-Kutta**: Production code requiring accuracy
- **Step Size Choice**: Balance between accuracy and computational cost

## File Outputs

The program generates solution files in tab-separated format:
- `euler_solution_h*.dat`: Forward Euler results
- `rk_solution_h*.dat`: Runge-Kutta results

These can be easily imported into plotting tools (MATLAB, Python matplotlib, Excel) for visualization.

## Extensions and Future Work

1. **Adaptive Step Size**: Implement step size control based on error estimates
2. **Higher-Order Methods**: Add Runge-Kutta-Fehlberg or Dormand-Prince
3. **Systems of ODEs**: Extend to handle vector-valued functions
4. **Stiff ODEs**: Implement implicit methods for stiff equations
5. **Error Analysis**: Add automatic convergence rate verification

## Conclusion

This exercise successfully demonstrates:
- Clean OOP design for numerical libraries
- Implementation of two fundamental ODE methods
- Quantitative comparison of numerical accuracy
- Proper software engineering practices (header files, testing, documentation)

The results clearly show why higher-order methods like Runge-Kutta are preferred for production numerical computing, while simple methods like Forward Euler remain valuable for educational purposes and quick estimates.
