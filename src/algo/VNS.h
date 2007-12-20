#ifndef VNS_H_
#define VNS_H_

#include "Algo.h"
#include "../solver/Solver.h"

class VNS {
private:
	int iterationLimit;
public:
	VNS(void);
	VNS( int _iterationLimit);

	~VNS();

	Solution getOptimumLocal(DetQuadProblem pb, Solver * s, const Solution& sol) const;
	
	virtual Solution solve(DetQuadProblem pb, Solver * s);
};

#endif /*VNS_H_*/
