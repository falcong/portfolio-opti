#ifndef SIMULATEDANNEALING_H_
#define SIMULATEDANNEALING_H_

#include <cmath>

#include "Algo.h"
#include "../solver/Solver.h"

class SimulatedAnnealing : public Algo {
private:
	virtual float getAdaptativeRate(float variation, float temperature) const;
public:
	SimulatedAnnealing();
	virtual ~SimulatedAnnealing();

	virtual Solution solve(LinearProblem pb, Solver * is) const;
};

#endif /*SIMULATEDANNEALING_H_*/
