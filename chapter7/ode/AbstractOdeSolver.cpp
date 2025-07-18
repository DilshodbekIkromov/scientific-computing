#include "AbstractOdeSolver.hpp"
#include <stdexcept>

AbstractOdeSolver::AbstractOdeSolver() :
    stepSize(0.0),
    initialTime(0.0),
    finalTime(1.0),
    initialValue(0.0),
    rightHandSide(nullptr) {
}

void AbstractOdeSolver::SetStepSize(double h) {
    if (h <= 0.0) {
        throw std::runtime_error("Step size must be positive");
    }
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1) {
    if (t1 <= t0) {
        throw std::runtime_error("Final time must be greater than initial time");
    }
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0) {
    initialValue = y0;
}

void AbstractOdeSolver::SetRightHandSide(std::function<double(double, double)> f) {
    rightHandSide = f;
}

double AbstractOdeSolver::GetStepSize() const {
    return stepSize;
}

double AbstractOdeSolver::GetInitialTime() const {
    return initialTime;
}

double AbstractOdeSolver::GetFinalTime() const {
    return finalTime;
}

double AbstractOdeSolver::GetInitialValue() const {
    return initialValue;
}
