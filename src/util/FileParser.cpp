#include "FileParser.h"

FileParser::FileParser() {
}

FileParser::~FileParser() {
}

DetQuadProblem* FileParser::parseDetModel(std::string filepath, std::string fileFEpath) {
	DetQuadProblem* dqp= NULL;
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
			float mean_value, variance, correlation, covariance;
			int line, column;

			switch (state) {
			case FIRST:
				*(new std::istringstream(str_list[1])) >> total;
				std::cout << total << std::endl;
				state = STOCKS;
				dqp = new DetQuadProblem(total);
				break;
			case STOCKS:
				*(new std::istringstream(str_list[1])) >> mean_value;
				*(new std::istringstream(str_list[2])) >> variance;
				dqp->addMeanValue(mean_value);
				variances.push_back(variance);
				dqp->sigma[current][current] = variance;
				
				if (++current == total) {					
					state = CORR;
					current = 0;
				}
				break;
			case CORR:
				*(new std::istringstream(str_list[1])) >> line;
				*(new std::istringstream(str_list[2])) >> column;
				*(new std::istringstream(str_list[3])) >> correlation;
				covariance = correlation*sqrt(dqp->sigma[line-1][line-1])*sqrt(dqp->sigma[column-1][column-1]);
				dqp->sigma[line-1][column-1] = covariance;
				dqp->sigma[column-1][line-1] = covariance;
				
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
	return dqp;
}

StochLinearProblem* FileParser::parseStochModel(std::string filepath) {
	return NULL;
}
