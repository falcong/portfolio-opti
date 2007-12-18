#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include <iostream>
#include <sstream>

class Variable {
protected:
	// WARNING this must be a 1 based index
	int position;
	std::string name;
public:
	virtual ~Variable();

	virtual int getPosition() const;
	
	virtual std::string getName() const;
	virtual char * getNameToChar() const; 
	
	friend std::ostream& operator<<(std::ostream& os, const Variable& v) {
		return os << v.toString();
	};
	virtual std::string toString() const;
	virtual void print() const;
};

#endif /*VARIABLE_H_*/
