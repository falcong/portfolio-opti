#ifndef SIMULATEDANNEALING_H_
#define SIMULATEDANNEALING_H_

#include <cmath>

#include "Algo.h"
#include "../solver/Solver.h"

class SimulatedAnnealing : public Algo {
private:
	float initialTemp;
	int nbIter;
	virtual float getAdaptativeRate(float variation, float temperature) const;
public:
	SimulatedAnnealing();
	SimulatedAnnealing(float initialTemp, int nbIter);
	virtual ~SimulatedAnnealing();

	virtual Solution solve(DetQuadProblem& pb, Solver& s) const;
};

#endif /*SIMULATEDANNEALING_H_*/
