#include "DetQuadProblem.h"

DetQuadProblem::DetQuadProblem(int nbStocks) {
	for(int i = 0; i < nbStocks; ++i) {
		sigma.push_back(*(new std::vector<float>()));
		for(int j = 0; j < nbStocks; ++j) {
			sigma[i].push_back(0.0);
		}
	}
}

DetQuadProblem::~DetQuadProblem() {
}

float DetQuadProblem::objectiveFunction() const {
	// TODO: not implemented
	return 0.0;
}

Solution DetQuadProblem::getNeighbour(Solution x, int size) const {
	// TODO: not implemented
	return x;
}

void DetQuadProblem::getReglage(float temp) const {
	// TODO: I just don't remember what the Reglage is supposed to do
}

LinearProblem DetQuadProblem::getLinearProblem() const {
	// TODO: not implemented
	return LinearProblem();
}

void DetQuadProblem::addMeanValue(float mv) {
	mu.push_back(mv);
}

std::vector<float> DetQuadProblem::getMeanValues() const {
	return mu;
}
