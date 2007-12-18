#ifndef VARIABLEFLOAT_H_
#define VARIABLEFLOAT_H_

#include "Variable.h"

#include <string>
#include <iostream>
#include <sstream>

class VariableFloat : public Variable {
private:
	float lowerBound;
	float upperBound;
public:
	VariableFloat(int position, float lowerb, float upperb);
	VariableFloat(int position, std::string name, float lowerb, float upperb);
	virtual ~VariableFloat();
	
	virtual float getLowerBound() const;
	virtual float getUpperBound() const;
	
	virtual std::string toString() const;
};

#endif /*VARIABLEFLOAT_H_*/
