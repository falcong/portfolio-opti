#ifndef TERM_H_
#define TERM_H_

#include <string>
#include <iostream>
#include <sstream>

#include "Variable.h"

class Term {
private:
	/* TODO it looks like using a reference number could do it
	 * of Variable needs a integer for its position e.g. x1 = 1
	 */
	Variable * var;
	float coeff;
public:
	Term(Variable * v, float c);
	virtual ~Term();

	virtual float getCoeff() const;
	virtual Variable getVariable() const;
	
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*TERM_H_*/
