#ifndef SOLVER_H_
#define SOLVER_H_

#include "../Solution.h"
#include "../Problem.h"
#include "../LinearProblem.h"

class Solver {
public:
	virtual ~Solver();

	virtual Solution getBestSolution(LinearProblem *lp) = 0;
	virtual Solution getAdmissibleSolution(LinearProblem *lp) = 0;
};

#endif /*SOLVER_H_*/
