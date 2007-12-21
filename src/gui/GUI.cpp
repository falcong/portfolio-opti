#include <QtGui> 
#include "GUI.h"

// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

GUI::GUI(QWidget *parent) {
	solver = new LpsolveAdaptator();
	setupUi(this); // this sets up GUI
	setWindowTitle(QString("Optimisation de gestion de portefeuilles"));
	setMessage(QString(""));
	doubleSpinBox_esperance->setDecimals(2);
	doubleSpinBox_esperance->setSingleStep(0.1);
	doubleSpinBox_esperance->setSuffix(QString("%"));
	desactivateAll();

	connect( comboBox_filename, SIGNAL( activated(int) ), this, SLOT( setDirectory(int) ) );
	connect( comboBox_filename, SIGNAL( highlighted(int) ), this, SLOT( setDirectoryInit(int) ) );
	connect(pushButton_run, SIGNAL(clicked() ), this, SLOT(run() ) );
	connect(spinBox_K, SIGNAL(valueChanged(int) ), this, SLOT(updateK(int) ) );
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
		index--;
		detQProblem = FileParser::parseDetModel(
				instancesFiles.at(index).toLocal8Bit().constData(), 
				instancesFilesFE.at(index).toLocal8Bit().constData());
		if(detQProblem == NULL) {
			setMessage(QString("Instance non valide."));
			instancesFiles.removeAt(index);
			instancesFilesFE.removeAt(index);
			comboBox_filename->removeItem(index+1);
		}
		else {
			setMessage(QString(""));
			setNumberOfTitles(detQProblem->getN());
			activateAll();
		}
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

void GUI::updateK(int i) {
	k = i;
	setMinMaxTitles();
}

void GUI::setMinMaxTitles() {
	double min_val = 1.0/(2.0*double(k));
	double max_val = 2.0/double(k);
	for(int i = 0; i<n; i++) {
		QDoubleSpinBox *s1 = new QDoubleSpinBox(), *s2 = new QDoubleSpinBox();
		s1->setMaximum(1.0); s1->setMinimum(0.0); s1->setValue(min_val);
		s2->setMaximum(1.0); s2->setMinimum(0.0); s2->setValue(max_val); 
		s1->setSingleStep(0.05); s2->setSingleStep(0.05);
		tableWidget_proportionsMinMax->setCellWidget(0, i, s1);
		tableWidget_proportionsMinMax->setCellWidget(1, i, s2);
	}
}

void GUI::setNumberOfTitles(int nb) {
	std::cout << "set number of titles to " << nb << std::endl;
	n = nb;
	lineEdit_nbAvalableTitles->setText(QString::number(nb));
	tableWidget_proportionsMinMax->setColumnCount(nb);
	tableWidget_resultProportions->setColumnCount(nb);
	spinBox_K->setMaximum(nb);
	spinBox_K->setValue(nb/2);
}

void GUI::updateY() {
	cout << "update problem with k=" << k << " and rho=" << rho << endl;
	detQProblem->setK(k);
	detQProblem->setRho(rho);
	float min, max;
	for(int i=0; i<n; i++) {
		cout << i << endl;
		min = ((QDoubleSpinBox*)(tableWidget_proportionsMinMax->cellWidget(0, i)))->text().toFloat();
		max = ((QDoubleSpinBox*)(tableWidget_proportionsMinMax->cellWidget(1, i)))->text().toFloat();
		detQProblem->setBounds(i, min, max);
	}
	
}

void GUI::run() {
	char *algo_str;
	int max_iter;
	float init_temp;
	algo = NULL;
	rho = doubleSpinBox_esperance->value()/100.0;
	
	updateY();
	
	switch (tabWidget_algo->currentIndex()) {
	case 0:
		desactivateVeryAll();
		algo_str = "VNS";
		max_iter = lineEdit_nbIterationsVNS->text().toInt();
		if(max_iter != 0) algo = new VNS(max_iter);
		else algo = new VNS();
		std::cout << "nb iters : " << max_iter << std::endl;
		break;
	case 1:
		desactivateVeryAll();
		algo_str = "Recuit";
		init_temp = lineEdit_initialTemp->text().toFloat();
		max_iter = lineEdit_nbIterationsRecuit->text().toInt();
		std::cout << "nb iters : " << max_iter << ", init temp : "<< init_temp
				<< std::endl;
		//TODO: make it possible to put init temp and number of iterations
		if(init_temp > 0.0 && max_iter > 0) 
			algo = new SimulatedAnnealing(init_temp, max_iter);
		else algo = new SimulatedAnnealing();
		
		break;
	case 2:
		desactivateVeryAll();
		algo_str = "Lagrange";

		break;
	}

	//QTime tmax = timeEdit_maxComputation->time();
	QString tmax = timeEdit_maxComputation->displayFormat();
	std::cout << "run on problem with algo " << algo_str << ", K=" << k
			<< ", esperance=" << rho << ", tmax=" << tmax.toLocal8Bit().constData() << std::endl;

	if(algo != NULL) {
		Solution solution = algo->solve(*detQProblem, *solver);
		if(solution.isNull()) {
			setMessage(QString("No solution."));
		}
		else {
			vector<float> vars_x = solution.getVariables();
			for(int i = 0; i < (int)vars_x.size(); ++i) {
				tableWidget_resultProportions->setCellWidget(
						0, i, new QLabel(QString::number(vars_x[i])));
			}
			tableWidget_resultProportions->setEnabled(true);
			setMessage(QString("Risque : ") + QString::number(double(solution.getZ())*100,'g', 5)+ QString("%"));
		}
		comboBox_filename->setEnabled(true);
		cout << "z : " << solution.getZ() << endl;
		
	}
	else {
		activateAll();
		comboBox_filename->setEnabled(true);
	}
}

void GUI::activateAll() {
	spinBox_K->setEnabled(true);
	pushButton_run->setEnabled(true);
	tableWidget_proportionsMinMax->setEnabled(true);
	tableWidget_resultProportions->setEnabled(true);
	tabWidget_algo->setEnabled(true);
	//timeEdit_maxComputation->setEnabled(true);
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

void GUI::desactivateVeryAll() {
	desactivateAll();
	comboBox_filename->setEnabled(false);
}

void GUI::setMessage(QString s) {
	label_resultat->setText(s);
}


