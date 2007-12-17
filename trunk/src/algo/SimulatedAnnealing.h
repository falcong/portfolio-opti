#ifndef SIMULATEDANNEALING_H_
#define SIMULATEDANNEALING_H_

#include "Algo.h"

class SimulatedAnnealing : public Algo
{
public:
	SimulatedAnnealing();
	virtual ~SimulatedAnnealing();
	
	virtual Solution solve(DetQuadProblem pb, InitialSolver * is) const;
};

#endif /*SIMULATEDANNEALING_H_*/
