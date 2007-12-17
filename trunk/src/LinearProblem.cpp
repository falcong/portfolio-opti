#include "LinearProblem.h"

LinearProblem::LinearProblem() {
}

LinearProblem::~LinearProblem() {
}

float LinearProblem::objectiveFunction(Solution sol) const {
	return objective.result(sol);
}

Solution LinearProblem::getNeighbour(Solution x, int size) const {
	// TODO: not implemented
	return x;
}

void LinearProblem::getReglage(float temp) const {
	// TODO: I just don't remember what the Reglage is supposed to do
}

void LinearProblem::addVariable(Variable * var) {
	variables.push_back(var);
}

std::vector<Variable*> LinearProblem::getVariables() const {
	return variables;
}

void LinearProblem::addConstraint(Constraint constraint) {
	constraints.push_back(constraint);
}

std::vector<Constraint> LinearProblem::getConstraints() const {
	return constraints;
}

void LinearProblem::setObjective(Objective &objective) {
	this->objective = objective;
}

std::string LinearProblem::toString() const {
	std::ostringstream os;
	os << "Linear Problem:"<< std::endl;
	os << objective << std::endl;
	os << (int)variables.size() << " Variables:";
	for (int i = 0; i != (int)variables.size(); ++i) {
		os << "v"<< i << "-"<< *(variables[i])<< ", ";
	}
	os << std::endl << (int)constraints.size() << " Constraits:";
	for (int i = 0; i != (int)constraints.size(); ++i) {
		os << "c"<< i << "-"<< constraints[i].toString() << ", ";
	}
	return os.str();
}

void LinearProblem::print() const {
	std::cout << toString() << std::endl;
}
