#ifndef LINEARPROBLEM_H_
#define LINEARPROBLEM_H_

#include <list>

#include "Problem.h"
#include "Objective.h"
#include "Constraint.h"

#include "Variable.h"
#include "VariableFloat.h"

class LinearProblem : public Problem {
private:
	Objective objective;
	std::list<Constraint> constraints;
	std::list<Variable> variables;

public:
	LinearProblem();
	virtual ~LinearProblem();
	
	virtual float objectiveFunction() const;
	virtual Solution getNeighbour(Solution x, int size) const;
	virtual void getReglage(float temp) const;
	
	virtual void addVariable(Variable &var);
	virtual std::list<Variable>* getVariables();
};

#endif /*LINEARPROBLEM_H_*/
