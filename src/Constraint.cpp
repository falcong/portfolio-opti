#include "Constraint.h"

Constraint::Constraint() {
}

Constraint::~Constraint() {
}

float Constraint::getBound() const {
	return bound;
}

void Constraint::setBound(float bound) {
	this->bound = bound;
}

int Constraint::getOperator() const {
	return operat;
}

void Constraint::setOperator(int operat) {
	this->operat = operat;
}

std::list<Term> Constraint::getTerms() const {
	return terms;
}

void Constraint::addTerm(Term term) {
	terms.push_back(term);
}

std::string Constraint::toString() const {
	std::ostringstream os;
	// TODO: make symbols a static variable
	const std::string symbols[6] = { "<", "<=", ">", ">=", "=", "!=" };
	for (TermList::const_iterator it = terms.begin(); it != terms.end(); ++it) {
		if (it != terms.begin()) {
			os << "+";
		}
		os << it->toString();
	}
	os << symbols[operat]<< bound;
	return os.str();
}

void Constraint::print() const {
	std::cout << toString()<< std::endl;
}
