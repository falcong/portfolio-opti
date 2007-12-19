#ifndef LINEARPROBLEM_H_
#define LINEARPROBLEM_H_

#include <vector>

#include "Problem.h"
#include "Objective.h"
#include "Constraint.h"

#include "Variable.h"
#include "VariableFloat.h"

class LinearProblem : public Problem {
private:
	Objective objective;
	std::vector<Constraint> constraints;
	// Using pointers to ensure dynamic mapping of virtual functions to the real class
	std::vector<Variable*> variables;
	int n, k;
	float rho;

public:
	LinearProblem();
	LinearProblem(int nbTotalStocks, int stockSelSize, float yield);
	virtual ~LinearProblem();

	virtual float objectiveFunction(Solution sol) const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;

	virtual void addVariable(Variable * var);
	virtual std::vector<Variable*> getVariables() const;

	int getN() const;
	int getK() const;
	float getRho() const;
	
	virtual void addConstraint(Constraint constraint);
	virtual std::vector<Constraint> getConstraints() const;

	virtual Objective getObjective() const;
	virtual void setObjective(Objective &objective);
	
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*LINEARPROBLEM_H_*/
