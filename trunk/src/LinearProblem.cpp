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
	// TODO randomly exchange the value of size+1 Y_i, Y_j variables
	Random r = Random();
	int changed = 0;

	while (changed < size) {
		std::vector<double> v = r.Random::getrand_numbers(n, 2*n, 1, 2);
		float var0 = x.getVariables()[(int)v[0]];
		float var1 = x.getVariables()[(int)v[1]];
		if (var0+var1 == 1) {
			x.changeVariable((int)v[0], var1);
			x.changeVariable((int)v[1], var0);
			++changed;
		}
	}
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
		os << variables[i]->getPosition() << ":"<< *(variables[i])<< ", ";
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
