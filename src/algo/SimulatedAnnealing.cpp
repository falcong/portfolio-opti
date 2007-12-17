#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing() {
}

SimulatedAnnealing::~SimulatedAnnealing() {
}

Solution SimulatedAnnealing::solve(DetQuadProblem pb, InitialSolver * is) const {
	Solution sol = is->getInitialSolution(pb, 1.0);
	
	return sol;
}
