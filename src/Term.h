#ifndef TERM_H_
#define TERM_H_

#include "Variable.h"

class Term {
private:
	Variable var;
	float coeff;
public:
	Term();
	virtual ~Term();
};

#endif /*TERM_H_*/
