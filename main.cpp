#include "GUI.h"
#include "Derivative.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUI w;
	w.show();

	return a.exec();
}