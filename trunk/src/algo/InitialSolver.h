#ifndef INITIALSOLVER_H_
#define INITIALSOLVER_H_

#include "../Solution.h"
#include "../Problem.h"
#include "../LinearProblem.h"
#include "../DetQuadProblem.h"

class InitialSolver {
public:
	virtual ~InitialSolver();
	
	//virtual Solution getInitialSolution(Problem &pb) = 0;
	virtual Solution getInitialSolution(LinearProblem &pb) = 0;
	virtual Solution getInitialSolution(DetQuadProblem &pb, float totalRatio) = 0;
};

#endif /*INITIALSOLVER_H_*/
