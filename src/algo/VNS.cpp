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
	Solution xPrim, xSecond;

	float min = pb.objectiveFunction(sol);
	std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
	
	while (i < itLim) {
		xPrim = lp.getNeighbour(sol, i);
		lp = pb.getFixedLP(xPrim);
		xPrim = s.getBestSolution(&lp);
		//xSecond = getOptimumLocal(pb, s, xPrim);

		float risk = pb.objectiveFunction(xPrim);
		if (risk < min) {
			sol = xPrim;
			min = risk;
			i=2;
			std::cout << "Risk = " << min << " : "<< sol.toString() << std::endl;
		} else {
			i++;
		}
	}
	return sol;
}

Solution VNS::getOptimumLocal(DetQuadProblem pb, Solver& s, const Solution& sol) const {
	Solution res = sol;
	LinearProblem lp = pb.getFixedLP(res);
	res = s.getAdmissibleSolution(&lp);

	float maxTemp = pb.objectiveFunction(res);

	Solution vTemp;

	int cpt = lp.getK() * (lp.getN() - lp.getK());

	for (int j = 0; j< cpt ; j++) {
		vTemp = lp.getNeighbour(sol, 1);
		lp = pb.getFixedLP(vTemp);
		vTemp = s.getAdmissibleSolution(&lp);
		if (pb.objectiveFunction(vTemp) < maxTemp) {
			maxTemp = pb.objectiveFunction(vTemp);
			res = vTemp;
			j = cpt;
			break;
		}
	}
	return res;
}
