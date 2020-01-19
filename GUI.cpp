#pragma once
#include "GUI.h"
#include "Derivative.h"
#include "Derivative.cpp"


GUI::GUI(QWidget *parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);

	//tytu³ okna
	this->setWindowTitle("Kalkulator pochodnych--ONP--Infix");

	//rozmiar okna
	this->setFixedSize(600, 780);

	//przyciski
	button1 = new QPushButton("Pochodna", this);
	button1->setGeometry(QRect(QPoint(50, 620),
		QSize(120, 50)));

	button2 = new QPushButton("Wyczysc", this);
	button2->setGeometry(QRect(QPoint(240, 700),
		QSize(120, 50)));

	button3 = new QPushButton("ONP", this);
	button3->setGeometry(QRect(QPoint(240, 620),
		QSize(120, 50)));

	button4 = new QPushButton("Infix", this);
	button4->setGeometry(QRect(QPoint(430, 620),
		QSize(120, 50)));

	//pola tekstowe
	lineedit1 = new QLineEdit(this);
	lineedit1->setGeometry(QRect(QPoint(50, 60),
		QSize(500, 80)));

	lineedit2 = new QLineEdit(this);
	lineedit2->setGeometry(QRect(QPoint(50, 200),
		QSize(500, 80)));

	lineedit3 = new QLineEdit(this);
	lineedit3->setGeometry(QRect(QPoint(50, 345),
		QSize(500, 80)));

	lineedit4 = new QLineEdit(this);
	lineedit4->setGeometry(QRect(QPoint(50, 495),
		QSize(500, 80)));

	//opisy
	label1 = new QLabel("Wpisz funkcje f(x): ", this);
	label1->setGeometry(QRect(QPoint(50, 5),
		QSize(150, 80)));

	label2 = new QLabel("Pochodna f'(x): ", this);
	label2->setGeometry(QRect(QPoint(50, 150),
		QSize(150, 80)));

	label3 = new QLabel("ONP: ", this);
	label3->setGeometry(QRect(QPoint(50, 295),
		QSize(150, 80)));

	label4 = new QLabel("Infix: ", this);
	label4->setGeometry(QRect(QPoint(50, 440),
		QSize(150, 80)));


	//polaczenia signals-slots 
	connect(button1, SIGNAL(clicked()), this, SLOT(calculate()));
	connect(button2, SIGNAL(clicked()), this, SLOT(clean()));
	connect(button3, SIGNAL(clicked()), this, SLOT(ONP()));
	connect(button4, SIGNAL(clicked()), this, SLOT(infix()));
}

//slots
void GUI::clean()
{
	lineedit1->clear();
	lineedit2->clear();
	lineedit3->clear();
	lineedit4->clear();
}


void GUI::calculate()
{
	
	QString qtext = lineedit1->text();		//pobieranie tekstu z pola

	Derivative function;
	function.text = qtext.toStdString();		//konwersja qstring na std::string
	function.infixtoONP();
	//function.ONPtoTree();
	function.calc();


	QString result = QString::fromStdString(function.text);		//konwersja std::string na qstring
	lineedit2->setText(result);
	
}

void GUI::ONP()
{
	QString qtext = lineedit1->text();		//pobieranie tekstu z pola
	
	Derivative function2;
	function2.text = qtext.toStdString();		//konwersja qstring na std::string
	function2.infixtoONP();

	QString result2 = QString::fromStdString(function2.text);		//konwersja std::string na qstring
	lineedit3->setText(result2);
}

void GUI::infix()
{
	QString qtext = lineedit3->text();		//pobieranie tekstu z pola

	Derivative function3;
	function3.text = qtext.toStdString();
	function3.ONPtoinfix();

	QString result3 = QString::fromStdString(function3.text);		//konwersja std::string na qstring
	lineedit4->setText(result3);
}
