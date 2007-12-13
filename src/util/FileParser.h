#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#include "../DetQuadProblem.h"
#include "../StochLinearProblem.h"
#include "../VariableFloat.h"

class FileParser {
private:
	static const int FIRST = 0;
	static const int STOCKS = 1;
	static const int CORR = 2;
public:
	FileParser();
	virtual ~FileParser();
	
	LinearProblem* parseDetModel(std::string filepath);
	StochLinearProblem* parseStochModel(std::string filepath);
};

#endif /*FILEPARSER_H_*/
