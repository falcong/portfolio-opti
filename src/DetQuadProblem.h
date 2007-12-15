#ifndef DETQUADPROBLEM_H_
#define DETQUADPROBLEM_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Problem.h"
#include "LinearProblem.h"

class DetQuadProblem : public Problem {
private:
	// TODO: give explicit names to the variables
	int n;
	std::vector<float> mu;
	float rho;
	int k;
	std::vector<float> epsilon;
	std::vector<float> delta;

public:
	//float sigma[100][100];
	std::vector< std::vector<float> > sigma;
	DetQuadProblem(int nbStocks);
	virtual ~DetQuadProblem();
	
	virtual float objectiveFunction() const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;
	
	LinearProblem getLinearProblem() const;
	void addMeanValue(float mv);
	std::vector<float> getMeanValues() const;
};

#endif /*DETQUADPROBLEM_H_*/
