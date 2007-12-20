#ifndef GUI_H
#define GUI_H

#include <string>
#include <iostream>

#include "ui_GUI.h"



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

	void activateAll();
	void desactivateAll();
	
};


#endif
