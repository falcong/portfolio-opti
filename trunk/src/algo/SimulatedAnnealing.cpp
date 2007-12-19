#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing() {
}

SimulatedAnnealing::~SimulatedAnnealing() {
}


Solution SimulatedAnnealing::solve(LinearProblem pb, Solver * is) const {
	Solution sol = is->getAdmissibleSolution(&pb);
	float coolingFactor = 0.85, temp = 10, acceptRate = 0.0, variation = 0.0;

	for (int i = 0; acceptRate < getAdaptativeRate(variation, temp) && i < pb.getK()
			* ((pb.getK()> 1) ? pb.getK()-1 : 1)/ 2; ++i) {
		Solution sol_altered = pb.getNeighbour(sol, 1);
		variation = pb.objectiveFunction(sol) - pb.objectiveFunction(sol_altered);
	}
	return sol;
}

float SimulatedAnnealing::getAdaptativeRate(float variation, float temperature) const {
	return 1 / (1 + std::exp( std::abs(variation) / temperature));
}
