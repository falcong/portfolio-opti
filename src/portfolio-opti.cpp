//============================================================================
// Name        : portfolio-opti.cpp
// Author      : Mathieu
// Version     :
// Copyright   : GPL3
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "util/FileParser.h"

typedef	std::list<Variable> lv;

int main(void) {
	puts("Hello World!!!");

	FileParser* fp = new FileParser();
	LinearProblem * lp = fp->parseDetModel("../benchmark/DAX.txt");

	for (lv::iterator i = lp->getVariables()->begin(); i != lp->getVariables()->end(); ++i) {
		/* Nothing is going to be print out because:
		   while the actual variables are of VariableFloat class 
		   the class expected if of type Variable */
		std::cout << i->toString() << std::endl;
	}
	return EXIT_SUCCESS;
}
