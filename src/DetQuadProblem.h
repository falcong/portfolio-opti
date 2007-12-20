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
#include "VariableFloat.h"
#include "VariableBool.h"

class DetQuadProblem : public Problem {
private:
	Objective objective;
	std::vector<Variable*> variables;
	// TODO: give explicit names to the variables
	int n;
	int k;
	float rho;
	std::vector<float> mu;
	std::vector<float> epsilon;
	std::vector<float> delta;
	std::vector< std::vector<float> > sigma;

public:
	DetQuadProblem(int nbTotalStocks, int stockSelSize, float yield);
	virtual ~DetQuadProblem();

	virtual float objectiveFunction(Solution sol) const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;

	LinearProblem getLinearProblem() const;
	LinearProblem getRelaxedLinearProblem(float lambda1, float lambda2) const;
	LinearProblem getSimpleLinearProblem() const;
	LinearProblem getFixedLP(Solution sol) const;

	virtual Objective getObjective();
	virtual void setObjective(Objective &objective);

	virtual void addVariable(Variable * var);
	virtual std::vector<Variable*> getVariables() const;

	void addMeanValue(float mv);
	std::vector<float> getMeanValues() const;

	void addCovariance(float cov);
	std::vector< std::vector<float> > & getCovariances();

	virtual int getK() const;
	virtual float getRho() const;
	virtual int getN() const;

	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*DETQUADPROBLEM_H_*/
