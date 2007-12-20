#include "VNS.h"

VNS::VNS() {
	iterationLimit = 0;
}

VNS::VNS(int _iterationLimit) {
	iterationLimit = _iterationLimit;
}

VNS::~VNS() {

}

Solution VNS::solve(DetQuadProblem& pb, Solver& s) const {
	int itLim = iterationLimit;
	if (itLim == 0) {
		itLim = pb.getK()/2;
	}

	LinearProblem lp = pb.getSimpleLinearProblem();

	int i = 2;
	Solution sol = s.getAdmissibleSolution(&lp);
	if(sol.isNull()) {
		return sol;
	}
	Solution xPrim, xSecond;

	float min = pb.objectiveFunction(sol);
	std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
	
	while (i < itLim) {
		xPrim = lp.getNeighbour(sol, i);
		lp = pb.getFixedLP(xPrim);
		xPrim = s.getBestSolution(&lp);
		if(xPrim.isNull()) {
			++i;
			continue;
		}

		float risk = pb.objectiveFunction(xPrim);
		if (risk < min) {
			sol = xPrim;
			min = risk;
			i=2;
			std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
		} else {
			++i;
		}
	}
	sol.setZ(min);
	return sol;
}
