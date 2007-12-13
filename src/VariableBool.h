#ifndef VARIABLEBOOL_H_
#define VARIABLEBOOL_H_

#include "Variable.h"

class VariableBool : public Variable {
private:
	bool value;
public:
	VariableBool();
	virtual ~VariableBool();
};

#endif /*VARIABLEBOOL_H_*/
