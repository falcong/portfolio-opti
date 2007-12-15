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

typedef	std::vector<float> vf;
typedef	std::vector< std::vector<float> > vvf;

int main(void) {
	puts("Hello World!!!");

	FileParser* fp = new FileParser();
	DetQuadProblem * dqp = fp->parseDetModel("../benchmark/DAX.txt", "../benchmark/DAX_FE.txt");

	for (vf::iterator i = dqp->getMeanValues().begin(); i != dqp->getMeanValues().end(); ++i) {
		std::cout << *i << std::endl;
	}
	for(int j = 0; j < 85; ++j) {
		for(int k = 0; k < 85; ++k) {
			std::cout << dqp->sigma[j][k] << " ";
		}
		std::cout << std::endl;
	}
	
	return EXIT_SUCCESS;
}
