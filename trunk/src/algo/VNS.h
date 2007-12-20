#ifndef VNS_H_
#define VNS_H_

#include "Algo.h"
#include "../solver/Solver.h"

class VNS : public Algo {
private:
	int iterationLimit;
public:
	VNS();
	VNS(int _iterationLimit);

	~VNS();

	Solution getOptimumLocal(DetQuadProblem pb, Solver &s, const Solution& sol) const;
	
	virtual Solution solve(DetQuadProblem& pb, Solver &s) const;
};

#endif /*VNS_H_*/
