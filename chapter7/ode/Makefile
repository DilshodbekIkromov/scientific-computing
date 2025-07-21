# Makefile for ODE Solver Library

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Object files
OBJS = AbstractOdeSolver.o ForwardEulerSolver.o RungeKuttaSolver.o

# Targets
all: test_ode_solvers

test_ode_solvers: test_ode_solvers.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Individual object files
AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	$(CXX) $(CXXFLAGS) -c AbstractOdeSolver.cpp

ForwardEulerSolver.o: ForwardEulerSolver.cpp ForwardEulerSolver.hpp AbstractOdeSolver.hpp
	$(CXX) $(CXXFLAGS) -c ForwardEulerSolver.cpp

RungeKuttaSolver.o: RungeKuttaSolver.cpp RungeKuttaSolver.hpp AbstractOdeSolver.hpp
	$(CXX) $(CXXFLAGS) -c RungeKuttaSolver.cpp

test_ode_solvers.o: test_ode_solvers.cpp ForwardEulerSolver.hpp RungeKuttaSolver.hpp
	$(CXX) $(CXXFLAGS) -c test_ode_solvers.cpp

# Clean up
clean:
	rm -f *.o test_ode_solvers *.exe *.dat

# Run the test
run: test_ode_solvers
	./test_ode_solvers

.PHONY: all clean run
