#ifndef INITIALSOLVER_H_
#define INITIALSOLVER_H_

#include "../Problem.h"
#include "../Solution.h"

class InitialSolver {
public:
	virtual ~InitialSolver();
	
	//virtual Solution getInitialSolution(Problem &pb) = 0;
};

#endif /*INITIALSOLVER_H_*/
