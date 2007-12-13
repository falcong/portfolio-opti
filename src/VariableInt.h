#ifndef VARIABLEINT_H_
#define VARIABLEINT_H_

#include "Variable.h"

class VariableInt : public Variable {
private:
	int lowerBound;
	int upperBound;

public:
	VariableInt();
	virtual ~VariableInt();
};

#endif /*VARIABLEINT_H_*/
