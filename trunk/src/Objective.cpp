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
