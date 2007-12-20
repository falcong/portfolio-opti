#ifndef GUI_H
#define GUI_H

#include <string>
#include <iostream>

#include "ui_GUI.h"

#include "../util/FileParser.h"

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
	QStringList instancesFiles;
	QStringList instancesFilesFE;
	DetQuadProblem* detProblem;

	void activateAll();
	void desactivateAll();
	
};


#endif
