#ifndef SOLUTION_H_
#define SOLUTION_H_ 

#include <list>

class Solution {
private:
	// TODO: give better names to variables
	std::list<float> variable_x;
	float cost_z;

public:
	Solution();
	virtual ~Solution();
};

#endif /*SOLUTION_H_*/
