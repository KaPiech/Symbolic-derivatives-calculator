#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "Derivative.h"



class GUI
	: public QMainWindow, public Derivative
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
private:
	Ui::GUIClass ui;

	QPushButton *button1;
	QPushButton *button2;
	QPushButton *button3;
	QPushButton *button4;

	QLineEdit *lineedit1;
	QLineEdit *lineedit2;
	QLineEdit *lineedit3;
	QLineEdit *lineedit4;

	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	QLabel *label4;

private slots:
	void clean();		//czyszczenie pól tekstowych

public slots:
	void calculate();		//pobieranie funkcji i obliczanie pochodnej
	void ONP();				//pobieranie funkcji i obliczanie ONP
	void infix();
};
