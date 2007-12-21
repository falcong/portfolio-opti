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
#ifdef DEBUG
	std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
#endif
	
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
#ifdef DEBUG
			std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
#endif
		} else {
			++i;
		}
	}
	sol.setZ(min);
	return sol;
}
