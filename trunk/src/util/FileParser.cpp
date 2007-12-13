#include "FileParser.h"

FileParser::FileParser() {
}

FileParser::~FileParser() {
}

LinearProblem* FileParser::parseDetModel(std::string filepath) {
	LinearProblem* lp= NULL;
	std::ifstream file(filepath.data());
	if (file.is_open()) {
		std::string line;
		int state = FIRST;
		int total = 0, current = 0;

		while (std::getline(file, line) && line.size() > 1) {

			std::istringstream iss(line.substr(line.find_first_of(" ")).c_str() );
			std::vector<std::string> str_list;
			std::string value;
			while (std::getline(iss, value, ' ') ) {
				str_list.push_back(value);
			}
			float inf, sup;

			switch (state) {
			case FIRST:
				*(new std::istringstream(str_list[1])) >> total;
				std::cout << total << std::endl;
				state = STOCKS;
				lp = new LinearProblem();
				break;
			case STOCKS:
				*(new std::istringstream(str_list[1])) >> inf;
				*(new std::istringstream(str_list[2])) >> sup;
				lp->addVariable(*(new VariableFloat(inf, sup)));
				if (++current == total) {
					state = CORR;
					current = 0;
				}
				break;
			case CORR:
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
	return lp;
}

StochLinearProblem* FileParser::parseStochModel(std::string filepath) {
	return NULL;
}
