#ifndef OBJECTIVE_H_
#define OBJECTIVE_H_

#include <list>

#include "Term.h"

class Objective {
private:
	std::list<Term> terms;
	bool minimize;

public:
	Objective();
	virtual ~Objective();
};

#endif /*OBJECTIVE_H_*/
