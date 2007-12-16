#include "Solution.h"

Solution::Solution() {
}

Solution::~Solution() {
}

std::list<float> Solution::getVariables() const {
	return variable_x;
}

void Solution::addVariable(float var) {
	variable_x.push_back(var);
}

std::string Solution::toString() const {
	std::ostringstream os;
	os << "Solution: {";
	for (FloatList::const_iterator it = variable_x.begin(); it != variable_x.end(); ++it) {
		if (it != variable_x.begin()) {
			os << ", ";
		}
		os << *it ;
	}
	os << "}";
	return os.str();
}

void Solution::print() const {
	std::cout << toString() << std::endl;
}


