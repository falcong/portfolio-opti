#include "FileParser.h"

FileParser::FileParser() {
}

FileParser::~FileParser() {
}

DetQuadProblem* FileParser::parseDetModel(std::string filepath,
		std::string fileFEpath) {
	DetQuadProblem* dqp= NULL;
	Objective obj = Objective();

	std::ifstream file(filepath.data());
	if (file.is_open()) {
		std::string line;
		int state = FIRST;
		int total = 0, current = 0;
		std::vector<float> variances;

		while (std::getline(file, line) && line.size() > 1) {
			std::istringstream iss(line.substr(line.find_first_of(" ")).c_str() );
			std::vector<std::string> str_list;
			std::string value;
			while (std::getline(iss, value, ' ') ) {
				str_list.push_back(value);
			}
			float meanYield, variance, correlation, covariance;
			int line, column;
			VariableFloat * var;

			switch (state) {
			case FIRST:
				*(new std::istringstream(str_list[1])) >> total;
				state = STOCKS;
				// TODO arbitrary stock selection size and minimum yield
				dqp = new DetQuadProblem(total, total/2, 0.01);
				break;
			case STOCKS:
				*(new std::istringstream(str_list[1])) >> meanYield;
				*(new std::istringstream(str_list[2])) >> variance;
				dqp->addMeanValue(meanYield);
				variances.push_back(variance);
				dqp->getCovariances()[current][current] = variance;
				// TODO this is hardcoding the lower and upper bound
				var = new VariableFloat(0,1);
				obj.addTerm(*new Term(var, variance));
				dqp->addVariable(var);

				// TODO concurrent way to build a DetQuadPb with a list of stocks;
				dqp->addStock(*new Stock(current, meanYield, variance, 0, 1));
				
				if (++current == total) {
					state = CORR;
					current = 0;
				}
				break;
			case CORR:
				*(new std::istringstream(str_list[1])) >> line;
				*(new std::istringstream(str_list[2])) >> column;
				*(new std::istringstream(str_list[3])) >> correlation;
				covariance = correlation*sqrt(dqp->getCovariances()[line-1][line-1])*sqrt(dqp->getCovariances()[column-1][column-1]);
				dqp->getCovariances()[line-1][column-1] = covariance;
				dqp->getCovariances()[column-1][line-1] = covariance;

				if (++current == total*total) {
					state = -1;
					current = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	if(dqp != NULL) {
		dqp->setObjective(obj);
	}
	return dqp;
}

StochLinearProblem* FileParser::parseStochModel(std::string filepath) {
	return NULL;
}
