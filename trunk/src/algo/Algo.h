#ifndef ALGO_H_
#define ALGO_H_

#include "../DetQuadProblem.h"
#include "../Solution.h"
#include "../solver/Solver.h"

class Algo {
public:
	virtual ~Algo();
	
	// TODO: I don't know how to have an abstract type as a parameter
	// virtual Solution solve(Problem pb) const = 0;
	virtual Solution solve(LinearProblem pb, Solver * is) const = 0;
};

#endif /*ALGO_H_*/
