#ifndef PROBLEM_H_
#define PROBLEM_H_

#include "Solution.h"

class Problem {
public:
	virtual ~Problem();

	virtual float objectiveFunction() const = 0;
	// TODO: give a more explicit name to x
	virtual Solution getNeighbour(Solution x, int size) const = 0;
	virtual void getReglage(float temp) const = 0;
};

#endif /*PROBLEM_H_*/
