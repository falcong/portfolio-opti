#include "VariableFloat.h"

VariableFloat::VariableFloat(float lowerb, float upperb) :
	lowerBound(lowerb), upperBound(upperb) {
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
	os << "[" << lowerBound << ";" << upperBound << "]";
	return os.str();
}

void VariableFloat::print() const {
	std::cout << this->toString()<< std::endl;
}
