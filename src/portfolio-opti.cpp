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

typedef std::vector<float> vf;
typedef std::vector< std::vector<float> > vvf;

int main(void) {
	FileParser* fp = new FileParser();
	DetQuadProblem * dqp = fp->parseDetModel("../benchmark/SIMPLE.txt",
			"../benchmark/SIMPLE_FE.txt");

	dqp->print();
	dqp->getLinearProblem().print();

	return EXIT_SUCCESS;
}
