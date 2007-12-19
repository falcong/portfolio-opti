#include "LinearProblem.h"

LinearProblem::LinearProblem() {
}

LinearProblem::LinearProblem(int nbTotalStocks, int stockSelSize, float yield) :
	n(nbTotalStocks), k(stockSelSize), rho(yield) {
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

int LinearProblem::getN() const {
	return n;
}

int LinearProblem::getK() const {
	return k;
}

float LinearProblem::getRho() const {
	return rho;
}

void LinearProblem::addConstraint(Constraint constraint) {
	constraints.push_back(constraint);
}

std::vector<Constraint> LinearProblem::getConstraints() const {
	return constraints;
}

Objective LinearProblem::getObjective() const {
	return objective;
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
		os << *(variables[i])<< ", ";
	}
	os << std::endl << (int)constraints.size() << " Constraits:"<< std::endl;
	for (int i = 0; i != (int)constraints.size(); ++i) {
		os << constraints[i].toString() << std::endl;
	}
	return os.str();
}

void LinearProblem::print() const {
	std::cout << toString() << std::endl;
}
