#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include <iostream>
#include <sstream>

class Variable {
public:
	virtual ~Variable();

	friend std::ostream& operator<<(std::ostream& os, const Variable& v) {
		return os << v.toString();
	};
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*VARIABLE_H_*/
