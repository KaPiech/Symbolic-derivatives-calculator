#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "Derivative.h"

class GUI 
	:public QMainWindow, public Derivative
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::GUIClass ui;

	QPushButton *button1;
	QPushButton *button2;

	QLineEdit *lineedit1;
	QLineEdit *lineedit2;

	QLabel *label1;
	QLabel *label2;

private slots:
	void clean();

public slots:
	void calculate();
};
