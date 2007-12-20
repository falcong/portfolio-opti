#include "Lagrange.h"

Lagrange::Lagrange() {
}

Lagrange::~Lagrange() {
}

Solution Lagrange::solve(DetQuadProblem& pb, Solver& s) const {
	LinearProblem lp = pb.getRelaxedLinearProblem(0, 0);
	Solution sol = s.getAdmissibleSolution(&lp);
	float solRisk = pb.objectiveFunction(sol);
		
	std::cout << "Risk = " << solRisk << " : "<< sol.toString() << std::endl;
	
	return sol;
}
