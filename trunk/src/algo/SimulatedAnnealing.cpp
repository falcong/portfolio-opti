#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing() {
}

SimulatedAnnealing::~SimulatedAnnealing() {
}

Solution SimulatedAnnealing::solve(LinearProblem pb, Solver * s) const {
	Solution sol = s->getAdmissibleSolution(&pb);
	float coolingFactor = 0.85, temp = 10, acceptRate = 0.0, variation = 0.0;

	for (int i = 0; acceptRate < getAdaptativeRate(variation, temp) && i
			< pb.getK()* ((pb.getK()> 1) ? pb.getK()-1 : 1)/ 2; ++i) {
		Solution sol_altered = pb.getNeighbour(sol, 1);
		variation = pb.objectiveFunction(sol)
				- pb.objectiveFunction(sol_altered);
	}
	return sol;
}

Solution SimulatedAnnealing::solve(DetQuadProblem pb, Solver *s) const {
	//return solve(pb.getSimpleLinearProblem(), s);
	LinearProblem lp;
	lp = pb.getSimpleLinearProblem();

	Solution sol = s->getAdmissibleSolution(&lp);
	Solution bestSol = sol;

	float solRisk = pb.objectiveFunction(sol);
	float bestRisk = solRisk;

	float coolingFactor = 0.85, temp = 10, acceptRate = 0.0, variation = 0.0;

	for (int tempChanges = 0; tempChanges < (pb.getK()* pb.getK())/ 2; ++tempChanges) {
#ifdef DEBUG
		std::cout << "Risk = " << solRisk << " : "<< sol.toString() << std::endl;
#endif
		for (int i = 0; acceptRate < getAdaptativeRate(variation, temp) && i
				< pb.getK()* ((pb.getK()> 1) ? pb.getK()-1 : 1)/ 2; ++i) {
			// At this point it may not be an admissible solution
			Solution sol_altered = lp.getNeighbour(sol, 1);
			// So we transform the pb to force the Y_i change
			lp = pb.getFixedLP(sol_altered);
			sol_altered = s->getAdmissibleSolution(&lp);

			float alteredRisk = pb.objectiveFunction(sol_altered);
			variation = solRisk - alteredRisk;

#ifdef DEBUG
			std::cout << "Risk = " << alteredRisk << " : "<< sol_altered.toString() << std::endl;
#endif
			int success = 0;
			if (variation > 0) {
				++success;
				std::cout << "Risk decreasing to "<< alteredRisk << std::endl;
				sol = sol_altered;
				solRisk = alteredRisk;
				if (alteredRisk < bestRisk) {
					bestSol = sol_altered;
					bestRisk = alteredRisk;
				}
			}
			temp = coolingFactor * temp;
		}
	}
	return bestSol;
}

float SimulatedAnnealing::getAdaptativeRate(float variation, float temperature) const {
	return ( (variation > 0) ? 1 : 1 / (1 + std::exp(std::abs(variation)
			/ temperature)));
}
