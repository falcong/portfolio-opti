#ifndef DETQUADPROBLEM_H_
#define DETQUADPROBLEM_H_

#include <vector>

#include "Problem.h"
#include "LinearProblem.h"

class DetQuadProblem : public Problem {
private:
	// TODO: give explicit names to the variables
	int n;
	std::vector<float> mu;
	std::vector< std::vector<float> > sigma;
	float rho;
	int k;
	std::vector<float> epsilon;
	std::vector<float> delta;

public:
	DetQuadProblem();
	virtual ~DetQuadProblem();
	
	LinearProblem getLinearProblem() const;
};

#endif /*DETQUADPROBLEM_H_*/
