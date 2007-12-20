#include <QtGui> 
#include "GUI.h"

// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

GUI::GUI(QWidget *parent) {
	setupUi(this); // this sets up GUI
	desactivateAll();

	connect( comboBox_filename, SIGNAL( activated(int) ), this, SLOT( setDirectory(int) ) );
	connect( comboBox_filename, SIGNAL( highlighted(int) ), this, SLOT( setDirectoryInit(int) ) );
	connect(pushButton_run, SIGNAL(clicked() ), this, SLOT(run() ) );
}

void GUI::setDirectoryInit(int index) {
	if (comboBox_filename->count() == 1) {
		setDirectory(index);
	}
}

void GUI::setDirectory(int index) {
	if (index == 0) {
		this->getPath();
	} else {
		string path = comboBox_filename->itemText(index).toLocal8Bit().constData();
		std::cout << "open file" << path << std::endl;
	//TODO : onpen file and handle it... see with parser
		detProblem = FileParser::parseDetModel(
				instancesFiles.at(index).toLocal8Bit().constData(), 
				instancesFilesFE.at(index).toLocal8Bit().constData());
		activateAll();
		setNumberOfTitles(10);
	}
}

void GUI::getPath() {
	QString path;

	path = QFileDialog::getExistingDirectory( this,
									"Choisir un répertoire à ouvrir.",
									QString::null);

if(!path.isEmpty()) {
	comboBox_filename->clear();
	comboBox_filename->addItem(path);
	QDir::setCurrent ( path );
	QDir dir = QDir ( path );
	QStringList files = dir.entryList (QDir::Files|QDir::Readable);
	files.sort();
	QStringList files1 = files.filter(QRegExp(QString("\\w+_FE(\\.\\w+)*"))); // FE
	QStringList files2 = QStringList(files1);
	files2.replaceInStrings(QRegExp("(\\w+)_FE((\\.\\w+)*)"), "\\1\\2"); //not FE
	
	QStringList instance = QStringList();
	for (int i = 0; i < files2.size(); ++i)
		if(files.contains(files2.at(i))) instance << files2.at(i);
		else {
			files2.removeAt(i);
			files1.removeAt(i);
		}
	
	instancesFiles.clear();
	instancesFiles << instance;
	
	instancesFilesFE.clear();
	instancesFilesFE << files1;
	
	files2.replaceInStrings(QRegExp("(\\w+)((\\.\\w+)*)"), "\\1");
	comboBox_filename->addItems(files2);
//comboBox_filename->setItemText(i+1, files.at(i));
	/*
	for (int i = 0; i < instancesFiles.size(); ++i)
		std::cout << instancesFiles.at(i).toLocal8Bit().constData() << std::endl;
	std::cout << ' ' << std::endl;
	for (int i = 0; i < instancesFilesFE.size(); ++i)
			std::cout << instancesFilesFE.at(i).toLocal8Bit().constData() << std::endl;
	*/
	
	}

}

void GUI::setNumberOfTitles(int nb) {
	std::cout << "set number of titles to " << nb << std::endl;
	lineEdit_nbAvalableTitles->setText(QString::number(nb));
	spinBox_K->setMaximum(nb);
	tableWidget_proportionsMinMax->setColumnCount(nb);
	//TODO put 0 / 1 by default to the min / max
	tableWidget_resultProportions->setColumnCount(nb);

}

void GUI::run() {
	char *algo;

	int max_iter;
	float init_temp;
	switch (tabWidget_algo->currentIndex()) {
	case 0:
		algo = "VNS";
		max_iter = lineEdit_nbIterationsVNS->text().toInt();
		std::cout << "nb iters : " << max_iter << std::endl;
		break;
	case 1:
		algo = "Recuit";
		init_temp = lineEdit_initialTemp->text().toFloat();
		max_iter = lineEdit_nbIterationsRecuit->text().toInt();
		std::cout << "nb iters : " << max_iter << ", init temp : "<< init_temp
				<< std::endl;
		break;
	case 2:
		algo = "Lagrange";

		break;
	}

	k = spinBox_K->value();
	e = doubleSpinBox_esperance->value();
	//QTime tmax = timeEdit_maxComputation->time();
	QString tmax = timeEdit_maxComputation->displayFormat();
	std::cout << "run on problem with algo " << algo << ", K=" << k
			<< ", esperance=" << e << ", tmax=" << tmax.toLocal8Bit().constData() << std::endl;

}

void GUI::activateAll() {
	spinBox_K->setEnabled(true);
	pushButton_run->setEnabled(true);
	tableWidget_proportionsMinMax->setEnabled(true);
	tableWidget_resultProportions->setEnabled(true);
	tabWidget_algo->setEnabled(true);
	timeEdit_maxComputation->setEnabled(true);
	doubleSpinBox_esperance->setEnabled(true);
	lineEdit_nbAvalableTitles->setEnabled(true);
}

void GUI::desactivateAll() {
	spinBox_K->setEnabled(false);
	pushButton_run->setEnabled(false);
	tableWidget_proportionsMinMax->setEnabled(false);
	tableWidget_resultProportions->setEnabled(false);
	tabWidget_algo->setEnabled(false);
	timeEdit_maxComputation->setEnabled(false);
	doubleSpinBox_esperance->setEnabled(false);
	lineEdit_nbAvalableTitles->setEnabled(false);
}

/*
 void Test1::about() 
 {
 QMessageBox::about(this, "About myQtApp",
 "This app was coded for educational purposes.\n"
 "Number 1 is: " + QString::number(spinBox1->value()) + "\n\n"
 "Bye.\n");
 }*/

