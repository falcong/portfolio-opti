#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include <iostream>
#include <sstream>

class Variable {
public:
	virtual ~Variable();
	
	virtual std::string toString() const { return "";};
	virtual void print() const {};
};

#endif /*VARIABLE_H_*/
