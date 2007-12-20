#ifndef LAGRANGE_H_
#define LAGRANGE_H_

#include "Algo.h"

class Lagrange : public Algo {
public:
	Lagrange();
	virtual ~Lagrange();
	
	virtual Solution solve(DetQuadProblem& pb, Solver& s) const;
};

#endif /*LAGRANGE_H_*/
