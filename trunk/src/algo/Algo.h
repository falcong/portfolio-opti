#ifndef ALGO_H_
#define ALGO_H_

#include "../DetQuadProblem.h"
#include "../Solution.h"
#include "../solver/Solver.h"

class Algo {
public:
	virtual ~Algo();

	virtual Solution solve(DetQuadProblem& pb, Solver& s) const = 0;
};

#endif /*ALGO_H_*/
