#ifndef SOLUTION_H_
#define SOLUTION_H_ 

#include <list>

#include "Variable.h"
#include "VariableFloat.h"

typedef const std::list<float> FloatList;

class Solution {
private:
	// TODO: give better names to variables
	std::list<float> variable_x;
	float cost_z;

public:
	Solution();
	virtual ~Solution();
	
	virtual std::list<float> getVariables() const;
	virtual void addVariable(float var);
	
	virtual void setZ(float z);
	
	friend std::ostream& operator<<(std::ostream& os, const Solution& s) {
		return os << s.toString();
	};
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*SOLUTION_H_*/