#include "Objective.h"

Objective::Objective() :
	minimize(true) {
}

Objective::Objective(bool minimize) :
	minimize(minimize) {
}

Objective::~Objective() {
}

std::list<Term> Objective::getTerms() const {
	return terms;
}

void Objective::addTerm(Term term) {
	terms.push_back(term);
}

float Objective::result(Solution sol) const {
	float result = 0.0;
	
	TermList::const_iterator it2 = terms.begin();
	for (FloatList::const_iterator it = sol.getVariables().begin();
		it != sol.getVariables().end() && it2 != terms.end();
		++it, ++it2) {
		result += ((Term)*it2).getCoeff() * (float)*it;
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
