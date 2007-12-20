#ifndef GUI_H
#define GUI_H

#include <string>
#include <iostream>

#include "ui_GUI.h"

#include "../util/FileParser.h"
#include "../algo/Algo.h"
#include "../algo/SimulatedAnnealing.h"
#include "../solver/Solver.h"
#include "../solver/LpsolveAdaptator.h"
#include "../Solution.h"

using namespace std;

class GUI : public QWidget, private Ui::Form
{
	Q_OBJECT

public:
	GUI(QWidget *parent = 0);
	void setNumberOfTitles(int nb);

public slots:
	void setDirectoryInit(int index);
	void setDirectory(int index);
	void getPath();
	void run();
	//void about();

private:
	int k; //number of titles
	double e; //rendement esperance
	Solver *solver;
	Algo *algo;
	DetQuadProblem *detQProblem;
	
	QStringList instancesFiles;
	QStringList instancesFilesFE;
	void setMessage(QString s);

	void activateAll();
	void desactivateAll();
	void desactivateVeryAll();
	
};


#endif
