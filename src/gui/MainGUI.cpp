#include <QApplication>

#include "GUI.h"

#define DORECUIT

#ifdef DORECUIT
#include "../util/FileParser.h"
#include "../algo/Algo.h"
#include "../Solution.h"
#include <iostream>
using namespace std;
#endif //DOVNS
int main(int argc, char *argv[]) {
#ifdef GUI
	QApplication app(argc, argv);
	GUI *dialog = new GUI;

	dialog->show();
	return app.exec();
#endif //GUI
#ifdef DOVNS
	Solver *solver = new LpsolveAdaptator();
	DetQuadProblem *detQProblem;
	Algo *algo;
	char* file = argv[1];
	float rho = QString(argv[2]).toFloat();
	detQProblem = FileParser::parseDetModel(file, " ");
	detQProblem->setRho(rho);
	detQProblem->setK(detQProblem->getN()/2);
	algo = new VNS();
	Solution solution = algo->solve(*detQProblem, *solver);
	cout << solution.getZ() << endl;
#endif //DOVNS
#ifdef DORECUIT
	Solver *solver = new LpsolveAdaptator();
	DetQuadProblem *detQProblem;
	Algo *algo;
	char* file = argv[1];
	float rho = QString(argv[2]).toFloat();
	detQProblem = FileParser::parseDetModel(file, " ");
	detQProblem->setRho(rho);
	detQProblem->setK(detQProblem->getN()/2);
	algo = new SimulatedAnnealing();
	Solution solution = algo->solve(*detQProblem, *solver);
	cout << solution.getZ() << endl;
#endif
}

