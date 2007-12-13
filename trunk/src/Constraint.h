#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_

#include <string>
#include <list>

#include "Term.h"

class Constraint {
private:
	float bound;
	std::string operat;
	std::list<Term> terms;

public:
	Constraint();
	virtual ~Constraint();
};

#endif /*CONSTRAINT_H_*/
