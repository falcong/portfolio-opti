#ifndef ALGO_H_
#define ALGO_H_

#include "../Problem.h"
#include "../Solution.h"

class Algo {
public:
	virtual ~Algo();
	
	// TODO: I don't know how to have an abstract type as a parameter
	// virtual Solution solve(Problem pb) const = 0;
};

#endif /*ALGO_H_*/
