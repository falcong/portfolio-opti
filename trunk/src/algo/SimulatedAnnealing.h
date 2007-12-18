#ifndef SIMULATEDANNEALING_H_
#define SIMULATEDANNEALING_H_

#include <cmath>

#include "Algo.h"

class SimulatedAnnealing : public Algo {
private:
	virtual float getAdaptativeRate(float variation, float temperature) const;
public:
	SimulatedAnnealing();
	virtual ~SimulatedAnnealing();

	virtual Solution solve(DetQuadProblem pb, InitialSolver * is) const;
};

#endif /*SIMULATEDANNEALING_H_*/
