#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_

#include <list>
#include <string>
#include <iostream>
#include <sstream>

#include "Term.h"

typedef const std::list<Term> TermList;

class Constraint {
private:
	float bound;
	int operat;
	std::list<Term> terms;

public:
	static const int cLE = 1;
	static const int cGE = 2;
	static const int cEQ = 3;

	Constraint();
	virtual ~Constraint();

	virtual float getBound() const;
	virtual void setBound(float bound);
	virtual int getOperator() const;
	virtual void setOperator(int operat);
	virtual std::list<Term> getTerms() const;
	virtual void addTerm(Term term);

	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*CONSTRAINT_H_*/
