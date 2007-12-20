/********************************************************************************
** Form generated from reading ui file 'GUI.ui'
**
** Created: Thu Dec 20 19:01:43 2007
**      by: Qt User Interface Compiler version 4.3.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QTabWidget *modelChoice;
    QWidget *determinist;
    QComboBox *comboBox_filename;
    QTabWidget *tabWidget_algo;
    QWidget *tab;
    QLineEdit *lineEdit_nbIterationsVNS;
    QLabel *label_10;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label_6;
    QSpacerItem *spacerItem;
    QLineEdit *lineEdit_initialTemp;
    QHBoxLayout *hboxLayout1;
    QLabel *label_7;
    QSpacerItem *spacerItem1;
    QLineEdit *lineEdit_nbIterationsRecuit;
    QWidget *tab_3;
    QWidget *layoutWidget1;
    QHBoxLayout *hboxLayout2;
    QLabel *label_8;
    QSpacerItem *spacerItem2;
    QLineEdit *lineEdit_constraintToRelax;
    QWidget *layoutWidget2;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout3;
    QLabel *label_4;
    QSpacerItem *spacerItem3;
    QLineEdit *lineEdit_nbAvalableTitles;
    QHBoxLayout *hboxLayout4;
    QLabel *label_2;
    QSpacerItem *spacerItem4;
    QDoubleSpinBox *doubleSpinBox_esperance;
    QHBoxLayout *hboxLayout5;
    QLabel *label_3;
    QSpacerItem *spacerItem5;
    QSpinBox *spinBox_K;
    QLabel *label_9;
    QTableWidget *tableWidget_proportionsMinMax;
    QTableWidget *tableWidget_resultProportions;
    QLabel *label_resultat;
    QWidget *layoutWidget3;
    QVBoxLayout *vboxLayout2;
    QLabel *label;
    QTimeEdit *timeEdit_maxComputation;
    QPushButton *pushButton_run;
    QWidget *stochastic;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *hboxLayout6;
    QLabel *label_11;
    QSlider *horizontalSlider_2;
    QLCDNumber *lcdNumber_2;
    QWidget *tab_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *hboxLayout7;
    QLabel *label_12;
    QSpacerItem *spacerItem6;
    QLineEdit *lineEdit_5;
    QHBoxLayout *hboxLayout8;
    QLabel *label_13;
    QSpacerItem *spacerItem7;
    QLineEdit *lineEdit_6;
    QWidget *tab_6;
    QWidget *layoutWidget_4;
    QHBoxLayout *hboxLayout9;
    QLabel *label_14;
    QSpacerItem *spacerItem8;
    QLineEdit *lineEdit_7;
    QWidget *layoutWidget_5;
    QVBoxLayout *vboxLayout4;
    QLabel *label_15;
    QTimeEdit *timeEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(815, 506);
    modelChoice = new QTabWidget(Form);
    modelChoice->setObjectName(QString::fromUtf8("modelChoice"));
    modelChoice->setGeometry(QRect(10, 10, 801, 491));
    modelChoice->setTabPosition(QTabWidget::West);
    determinist = new QWidget();
    determinist->setObjectName(QString::fromUtf8("determinist"));
    comboBox_filename = new QComboBox(determinist);
    comboBox_filename->setObjectName(QString::fromUtf8("comboBox_filename"));
    comboBox_filename->setGeometry(QRect(10, 10, 151, 26));
    comboBox_filename->setEditable(false);
    tabWidget_algo = new QTabWidget(determinist);
    tabWidget_algo->setObjectName(QString::fromUtf8("tabWidget_algo"));
    tabWidget_algo->setGeometry(QRect(20, 210, 558, 91));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    lineEdit_nbIterationsVNS = new QLineEdit(tab);
    lineEdit_nbIterationsVNS->setObjectName(QString::fromUtf8("lineEdit_nbIterationsVNS"));
    lineEdit_nbIterationsVNS->setGeometry(QRect(180, 10, 110, 27));
    label_10 = new QLabel(tab);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(10, 10, 132, 27));
    tabWidget_algo->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    layoutWidget = new QWidget(tab_2);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(30, 0, 298, 66));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label_6 = new QLabel(layoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    hboxLayout->addWidget(label_6);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    lineEdit_initialTemp = new QLineEdit(layoutWidget);
    lineEdit_initialTemp->setObjectName(QString::fromUtf8("lineEdit_initialTemp"));

    hboxLayout->addWidget(lineEdit_initialTemp);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    label_7 = new QLabel(layoutWidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    hboxLayout1->addWidget(label_7);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    lineEdit_nbIterationsRecuit = new QLineEdit(layoutWidget);
    lineEdit_nbIterationsRecuit->setObjectName(QString::fromUtf8("lineEdit_nbIterationsRecuit"));

    hboxLayout1->addWidget(lineEdit_nbIterationsRecuit);


    vboxLayout->addLayout(hboxLayout1);

    tabWidget_algo->addTab(tab_2, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    layoutWidget1 = new QWidget(tab_3);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    layoutWidget1->setGeometry(QRect(11, 10, 389, 29));
    hboxLayout2 = new QHBoxLayout(layoutWidget1);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    hboxLayout2->setContentsMargins(0, 0, 0, 0);
    label_8 = new QLabel(layoutWidget1);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    hboxLayout2->addWidget(label_8);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem2);

    lineEdit_constraintToRelax = new QLineEdit(layoutWidget1);
    lineEdit_constraintToRelax->setObjectName(QString::fromUtf8("lineEdit_constraintToRelax"));

    hboxLayout2->addWidget(lineEdit_constraintToRelax);

    tabWidget_algo->addTab(tab_3, QString());
    layoutWidget2 = new QWidget(determinist);
    layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
    layoutWidget2->setGeometry(QRect(225, 0, 445, 101));
    vboxLayout1 = new QVBoxLayout(layoutWidget2);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(0, 0, 0, 0);
    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    label_4 = new QLabel(layoutWidget2);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    hboxLayout3->addWidget(label_4);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout3->addItem(spacerItem3);

    lineEdit_nbAvalableTitles = new QLineEdit(layoutWidget2);
    lineEdit_nbAvalableTitles->setObjectName(QString::fromUtf8("lineEdit_nbAvalableTitles"));
    lineEdit_nbAvalableTitles->setReadOnly(true);

    hboxLayout3->addWidget(lineEdit_nbAvalableTitles);


    vboxLayout1->addLayout(hboxLayout3);

    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    label_2 = new QLabel(layoutWidget2);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout4->addWidget(label_2);

    spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout4->addItem(spacerItem4);

    doubleSpinBox_esperance = new QDoubleSpinBox(layoutWidget2);
    doubleSpinBox_esperance->setObjectName(QString::fromUtf8("doubleSpinBox_esperance"));

    hboxLayout4->addWidget(doubleSpinBox_esperance);


    vboxLayout1->addLayout(hboxLayout4);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    label_3 = new QLabel(layoutWidget2);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    hboxLayout5->addWidget(label_3);

    spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout5->addItem(spacerItem5);

    spinBox_K = new QSpinBox(layoutWidget2);
    spinBox_K->setObjectName(QString::fromUtf8("spinBox_K"));
    spinBox_K->setMinimum(1);

    hboxLayout5->addWidget(spinBox_K);


    vboxLayout1->addLayout(hboxLayout5);

    label_9 = new QLabel(determinist);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(20, 350, 198, 18));
    tableWidget_proportionsMinMax = new QTableWidget(determinist);
    tableWidget_proportionsMinMax->setObjectName(QString::fromUtf8("tableWidget_proportionsMinMax"));
    tableWidget_proportionsMinMax->setGeometry(QRect(20, 100, 741, 111));
    tableWidget_proportionsMinMax->setAutoFillBackground(true);
    tableWidget_proportionsMinMax->setAlternatingRowColors(false);
    tableWidget_resultProportions = new QTableWidget(determinist);
    tableWidget_resultProportions->setObjectName(QString::fromUtf8("tableWidget_resultProportions"));
    tableWidget_resultProportions->setGeometry(QRect(20, 370, 741, 75));
    tableWidget_resultProportions->setShowGrid(false);
    tableWidget_resultProportions->setGridStyle(Qt::NoPen);
    tableWidget_resultProportions->setWordWrap(true);
    tableWidget_resultProportions->setCornerButtonEnabled(false);
    label_resultat = new QLabel(determinist);
    label_resultat->setObjectName(QString::fromUtf8("label_resultat"));
    label_resultat->setGeometry(QRect(280, 310, 235, 31));
    QPalette palette;
    QBrush brush(QColor(255, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    QBrush brush1(QColor(127, 125, 123, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
    label_resultat->setPalette(palette);
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setWeight(75);
    label_resultat->setFont(font);
    layoutWidget3 = new QWidget(determinist);
    layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
    layoutWidget3->setGeometry(QRect(584, 210, 167, 96));
    vboxLayout2 = new QVBoxLayout(layoutWidget3);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    vboxLayout2->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(layoutWidget3);
    label->setObjectName(QString::fromUtf8("label"));

    vboxLayout2->addWidget(label);

    timeEdit_maxComputation = new QTimeEdit(layoutWidget3);
    timeEdit_maxComputation->setObjectName(QString::fromUtf8("timeEdit_maxComputation"));
    timeEdit_maxComputation->setTime(QTime(5, 0, 0));

    vboxLayout2->addWidget(timeEdit_maxComputation);

    pushButton_run = new QPushButton(layoutWidget3);
    pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
    pushButton_run->setFont(font);

    vboxLayout2->addWidget(pushButton_run);

    modelChoice->addTab(determinist, QString());
    stochastic = new QWidget();
    stochastic->setObjectName(QString::fromUtf8("stochastic"));
    tabWidget_2 = new QTabWidget(stochastic);
    tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
    tabWidget_2->setGeometry(QRect(26, 220, 558, 91));
    tab_4 = new QWidget();
    tab_4->setObjectName(QString::fromUtf8("tab_4"));
    layoutWidget_2 = new QWidget(tab_4);
    layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
    layoutWidget_2->setGeometry(QRect(21, 10, 294, 25));
    hboxLayout6 = new QHBoxLayout(layoutWidget_2);
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    hboxLayout6->setContentsMargins(0, 0, 0, 0);
    label_11 = new QLabel(layoutWidget_2);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    hboxLayout6->addWidget(label_11);

    horizontalSlider_2 = new QSlider(layoutWidget_2);
    horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
    horizontalSlider_2->setValue(50);
    horizontalSlider_2->setOrientation(Qt::Horizontal);

    hboxLayout6->addWidget(horizontalSlider_2);

    lcdNumber_2 = new QLCDNumber(layoutWidget_2);
    lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
    lcdNumber_2->setProperty("value", QVariant(50));

    hboxLayout6->addWidget(lcdNumber_2);

    tabWidget_2->addTab(tab_4, QString());
    tab_5 = new QWidget();
    tab_5->setObjectName(QString::fromUtf8("tab_5"));
    layoutWidget_3 = new QWidget(tab_5);
    layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
    layoutWidget_3->setGeometry(QRect(30, 0, 298, 66));
    vboxLayout3 = new QVBoxLayout(layoutWidget_3);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    vboxLayout3->setContentsMargins(0, 0, 0, 0);
    hboxLayout7 = new QHBoxLayout();
    hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
    label_12 = new QLabel(layoutWidget_3);
    label_12->setObjectName(QString::fromUtf8("label_12"));

    hboxLayout7->addWidget(label_12);

    spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout7->addItem(spacerItem6);

    lineEdit_5 = new QLineEdit(layoutWidget_3);
    lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

    hboxLayout7->addWidget(lineEdit_5);


    vboxLayout3->addLayout(hboxLayout7);

    hboxLayout8 = new QHBoxLayout();
    hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
    label_13 = new QLabel(layoutWidget_3);
    label_13->setObjectName(QString::fromUtf8("label_13"));

    hboxLayout8->addWidget(label_13);

    spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout8->addItem(spacerItem7);

    lineEdit_6 = new QLineEdit(layoutWidget_3);
    lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

    hboxLayout8->addWidget(lineEdit_6);


    vboxLayout3->addLayout(hboxLayout8);

    tabWidget_2->addTab(tab_5, QString());
    tab_6 = new QWidget();
    tab_6->setObjectName(QString::fromUtf8("tab_6"));
    layoutWidget_4 = new QWidget(tab_6);
    layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
    layoutWidget_4->setGeometry(QRect(11, 10, 389, 29));
    hboxLayout9 = new QHBoxLayout(layoutWidget_4);
    hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
    hboxLayout9->setContentsMargins(0, 0, 0, 0);
    label_14 = new QLabel(layoutWidget_4);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    hboxLayout9->addWidget(label_14);

    spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout9->addItem(spacerItem8);

    lineEdit_7 = new QLineEdit(layoutWidget_4);
    lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

    hboxLayout9->addWidget(lineEdit_7);

    tabWidget_2->addTab(tab_6, QString());
    layoutWidget_5 = new QWidget(stochastic);
    layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
    layoutWidget_5->setGeometry(QRect(590, 220, 167, 96));
    vboxLayout4 = new QVBoxLayout(layoutWidget_5);
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    vboxLayout4->setContentsMargins(0, 0, 0, 0);
    label_15 = new QLabel(layoutWidget_5);
    label_15->setObjectName(QString::fromUtf8("label_15"));

    vboxLayout4->addWidget(label_15);

    timeEdit_2 = new QTimeEdit(layoutWidget_5);
    timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));

    vboxLayout4->addWidget(timeEdit_2);

    pushButton_2 = new QPushButton(layoutWidget_5);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setFont(font);

    vboxLayout4->addWidget(pushButton_2);

    modelChoice->addTab(stochastic, QString());

    retranslateUi(Form);

    modelChoice->setCurrentIndex(0);
    tabWidget_algo->setCurrentIndex(1);
    tabWidget_2->setCurrentIndex(2);


    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
    comboBox_filename->clear();
    comboBox_filename->insertItems(0, QStringList()
     << QApplication::translate("Form", "Choisir r\303\251pertoire...", 0, QApplication::UnicodeUTF8)
    );
    lineEdit_nbIterationsVNS->setInputMask(QApplication::translate("Form", "D999999999; ", 0, QApplication::UnicodeUTF8));
    lineEdit_nbIterationsVNS->setText(QApplication::translate("Form", "3", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("Form", "Nombre d'it\303\251rations :", 0, QApplication::UnicodeUTF8));
    tabWidget_algo->setTabText(tabWidget_algo->indexOf(tab), QApplication::translate("Form", "VNS", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("Form", "Temp\303\251rature initiale :", 0, QApplication::UnicodeUTF8));
    lineEdit_initialTemp->setInputMask(QApplication::translate("Form", "d999999999; ", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("Form", "Nombre d'it\303\251rations :", 0, QApplication::UnicodeUTF8));
    lineEdit_nbIterationsRecuit->setInputMask(QApplication::translate("Form", "d999999999; ", 0, QApplication::UnicodeUTF8));
    tabWidget_algo->setTabText(tabWidget_algo->indexOf(tab_2), QApplication::translate("Form", "Recuit simul\303\251", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("Form", "Num\303\251ro de la (ou les) contrainte(s) \303\240 relacher:", 0, QApplication::UnicodeUTF8));
    tabWidget_algo->setTabText(tabWidget_algo->indexOf(tab_3), QApplication::translate("Form", "Relaxation Lagrangienne", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("Form", "Nombre n de titres disponibles :", 0, QApplication::UnicodeUTF8));
    lineEdit_nbAvalableTitles->setText(QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Form", "Esp\303\251rance d\303\251sir\303\251e du rendement :", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Form", "Nombre K de titres \303\240 retenir pour constituer le portefeuille :", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("Form", "Proportions des titres retenus :", 0, QApplication::UnicodeUTF8));
    if (tableWidget_proportionsMinMax->columnCount() < 5)
        tableWidget_proportionsMinMax->setColumnCount(5);
    if (tableWidget_proportionsMinMax->rowCount() < 2)
        tableWidget_proportionsMinMax->setRowCount(2);

    QTableWidgetItem *__rowItem = new QTableWidgetItem();
    __rowItem->setText(QApplication::translate("Form", "Proportion minimale", 0, QApplication::UnicodeUTF8));
    tableWidget_proportionsMinMax->setVerticalHeaderItem(0, __rowItem);

    QTableWidgetItem *__rowItem1 = new QTableWidgetItem();
    __rowItem1->setText(QApplication::translate("Form", "Proportion maximale", 0, QApplication::UnicodeUTF8));
    tableWidget_proportionsMinMax->setVerticalHeaderItem(1, __rowItem1);
    if (tableWidget_resultProportions->columnCount() < 5)
        tableWidget_resultProportions->setColumnCount(5);
    if (tableWidget_resultProportions->rowCount() < 1)
        tableWidget_resultProportions->setRowCount(1);

    QTableWidgetItem *__rowItem2 = new QTableWidgetItem();
    __rowItem2->setText(QApplication::translate("Form", "Proportion", 0, QApplication::UnicodeUTF8));
    tableWidget_resultProportions->setVerticalHeaderItem(0, __rowItem2);
    label_resultat->setText(QString());
    label->setText(QApplication::translate("Form", "Temps maximum de calcul:", 0, QApplication::UnicodeUTF8));
    pushButton_run->setText(QApplication::translate("Form", "Run!", 0, QApplication::UnicodeUTF8));
    modelChoice->setTabText(modelChoice->indexOf(determinist), QApplication::translate("Form", "Mod\303\250le d\303\251terministe", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("Form", "Nombre d'it\303\251rations :", 0, QApplication::UnicodeUTF8));
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Form", "VNS", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("Form", "Temp\303\251rature initiale :", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("Form", "Nombre d'it\303\251rations :", 0, QApplication::UnicodeUTF8));
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("Form", "Recuit simul\303\251", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("Form", "Num\303\251ro de la (ou les) contrainte(s) \303\240 relacher:", 0, QApplication::UnicodeUTF8));
    tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("Form", "Relaxation Lagrangienne", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("Form", "Temps maximum de calcul:", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("Form", "Run!", 0, QApplication::UnicodeUTF8));
    modelChoice->setTabText(modelChoice->indexOf(stochastic), QApplication::translate("Form", "Mod\303\250le stochastique", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_GUI_H
