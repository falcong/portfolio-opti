#ifndef VARIABLEBOOL_H_
#define VARIABLEBOOL_H_

#include "Variable.h"

class VariableBool : public Variable {
private:
	bool value;
public:
	VariableBool(int position);
	VariableBool(int position, std::string name);
	virtual ~VariableBool();
	
	virtual bool isBinary() const;
};

#endif /*VARIABLEBOOL_H_*/
