#include "LinearProblem.h"

LinearProblem::LinearProblem() {
}

LinearProblem::~LinearProblem() {
}

float LinearProblem::objectiveFunction() const {
	// TODO: not implemented
	return 0.0;
}

Solution LinearProblem::getNeighbour(Solution x, int size) const {
	// TODO: not implemented
	return x;
}

void LinearProblem::getReglage(float temp) const {
	// TODO: I just don't remember what the Reglage is supposed to do
}

void LinearProblem::addVariable(Variable &var) {
	variables.push_back(var);
}

std::list<Variable> LinearProblem::getVariables() const {
	return variables;
}
