#include "Term.h"

Term::Term(Variable * var, float coeff) :
	var(var), coeff(coeff) {
}

Term::~Term() {
}

float Term::getCoeff() const {
	return coeff;
}

std::string Term::toString() const {
	std::ostringstream os;
	os << coeff << "*"<< *var;
	return os.str();
}

void Term::print() const {
	std::cout << toString()<< std::endl;
}
