#ifndef DETQUADPROBLEM_H_
#define DETQUADPROBLEM_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "Problem.h"
#include "LinearProblem.h"
#include "Objective.h"
#include "Constraint.h"
#include "Term.h"
#include "Variable.h"
#include "VariableFloat.h"

class DetQuadProblem : public Problem {
private:
	// TODO: give explicit names to the variables
	int n;
	std::vector<float> mu;
	float rho;
	int k;
	std::vector<float> epsilon;
	std::vector<float> delta;
	std::vector< std::vector<float> > sigma;

public:
	DetQuadProblem(int nbStocks);
	virtual ~DetQuadProblem();

	virtual float objectiveFunction() const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;

	LinearProblem getLinearProblem() const;
	void addMeanValue(float mv);
	std::vector<float> getMeanValues() const;
	void addCovariance(float cov);
	std::vector< std::vector<float> > & getCovariances();

	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*DETQUADPROBLEM_H_*/
