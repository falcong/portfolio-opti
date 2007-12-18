#include "VariableFloat.h"

VariableFloat::VariableFloat(int position, float lowerb, float upperb) :
	lowerBound(lowerb), upperBound(upperb) {
	Variable::position = position;
}

VariableFloat::VariableFloat(int position, std::string name, float lowerb, float upperb) :
	lowerBound(lowerb), upperBound(upperb) {
	Variable::position = position;
	Variable::name = name;
}

VariableFloat::~VariableFloat() {
}

float VariableFloat::getLowerBound() const {
	return lowerBound;
}

float VariableFloat::getUpperBound() const {
	return upperBound;
}

std::string VariableFloat::toString() const {
	std::ostringstream os;
	os << Variable::name; // << "["<< lowerBound << ";"<< upperBound << "]";
	return os.str();
}
