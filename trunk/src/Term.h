#ifndef TERM_H_
#define TERM_H_

#include <string>
#include <iostream>
#include <sstream>

#include "Variable.h"

class Term {
private:
	Variable * var;
	float coeff;
public:
	Term(Variable * v, float c);
	virtual ~Term();

	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*TERM_H_*/
