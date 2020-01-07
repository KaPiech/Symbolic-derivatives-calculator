#include "GUI.h"
#include "Derivative.h"


GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//tytu� okna
	this->setWindowTitle("Kalkulator pochodnych");

	//przyciski
	button1 = new QPushButton("Oblicz", this);
	button1->setGeometry(QRect(QPoint(50, 320),
		QSize(200, 50)));

	button2 = new QPushButton("Wyczysc", this);
	button2->setGeometry(QRect(QPoint(350, 320),
		QSize(200, 50)));

	//pola tekstowe
	lineedit1 = new QLineEdit(this);
	lineedit1->setGeometry(QRect(QPoint(50, 60),
		QSize(500, 80)));

	lineedit2 = new QLineEdit(this);
	lineedit2->setGeometry(QRect(QPoint(50, 200),
		QSize(500, 80)));

	//opisy
	label1 = new QLabel("Wpisz funkcje: ", this);
	label1->setGeometry(QRect(QPoint(50, 10),
		QSize(100, 80)));

	label2 = new QLabel("Pochodna: ", this);
	label2->setGeometry(QRect(QPoint(50, 150),
		QSize(100, 80)));

	//signals-slots
	connect(button2, SIGNAL(clicked()), this, SLOT(clean()));
	connect(button1, SIGNAL(clicked()), this, SLOT(calculate()));
}

//slots
void GUI::clean()
{
	lineedit1->clear();
	lineedit2->clear();
}

void GUI::calculate()
{
	//pobieranie tekstu z pola
	QString qtext = lineedit1->text();	

	
	//test pobierania tekstu 
	lineedit2->setText(qtext);		



}




