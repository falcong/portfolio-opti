#include "Solution.h"

Solution::Solution() {
}

Solution::~Solution() {
}

std::vector<float> Solution::getVariables() const {
	return variable_x;
}

void Solution::addVariable(float var) {
	variable_x.push_back(var);
}

void Solution::changeVariable(int at, float var) {
	if(at < (int)variable_x.size()) {
		variable_x[at] = var;
	}
}

void Solution::setZ(float z) {
	cost_z = z;
}

std::string Solution::toString() const {
	std::ostringstream os;
	os << "Solution: {";
	for(int i = 0; i < (int)variable_x.size(); ++i) {
		if (i != 0) {
			os << ", ";
		}
		os << variable_x[i];
	}
	os << "}";
	return os.str();
}

float Solution::getZ() {
	return cost_z;
}

void Solution::print() const {
	std::cout << toString() << std::endl;
}


