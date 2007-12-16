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
	int nbStocks;
	Objective objective;
	std::vector<Constraint> constraints;
	// Using pointers to ensure dynamic mapping of virtual functions to the real class
	std::vector<Variable*> variables;

public:
	LinearProblem();
	virtual ~LinearProblem();

	virtual float objectiveFunction() const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;

	virtual void addVariable(Variable * var);
	virtual std::vector<Variable*> getVariables() const;

	virtual void addConstraint(Constraint constraint);
	virtual std::vector<Constraint> getConstraints() const;

	virtual void setObjective(Objective &objective);
	
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*LINEARPROBLEM_H_*/
