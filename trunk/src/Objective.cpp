#include "Objective.h"

Objective::Objective() :
	minimize(true) {
}

Objective::Objective(bool minimize) :
	minimize(minimize) {
}

Objective::~Objective() {
}

bool Objective::isMinimize() const {
	return minimize;
}

std::list<Term> Objective::getTerms() const {
	return terms;
}

void Objective::addTerm(Term term) {
	terms.push_back(term);
}


// TODO I really doubt this method works ...
float Objective::result(Solution sol) const {
	float result = 0.0;
	
	for(TermList::const_iterator it = terms.begin(); it != terms.end(); ++it) {
		Variable var = ((Term)*it).getVariable();
		float coef =  ((Term)*it).getCoeff();
		float var_value = sol.getVariables()[var.getPosition()-1];
		result += coef * var_value;
	}
	return result;
}

std::string Objective::toString() const {
	std::ostringstream os;
	os << ((minimize) ? "min": "max") << " z = ";
	for (TermList::const_iterator it = terms.begin(); it != terms.end(); ++it) {
		if (it != terms.begin()) {
			os << " + ";
		}
		os << it->toString();
	}
	return os.str();
}

void Objective::print() const {
	std::cout << toString()<< std::endl;
}
