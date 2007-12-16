#ifndef NAIVEALGORITHM_H_
#define NAIVEALGORITHM_H_

#include "InitialSolver.h"
#include "../Problem.h"
#include "../DetQuadProblem.h"
#include "../Solution.h"
#include "../Variable.h"
#include "../VariableFloat.h"

class NaiveAlgorithm : public InitialSolver {
public:
	NaiveAlgorithm();
	virtual ~NaiveAlgorithm();
	
	virtual Solution getInitialSolution(LinearProblem &pb);
	virtual Solution getInitialSolution(DetQuadProblem &pb);
};

#endif /*NAIVEALGORITHM_H_*/
