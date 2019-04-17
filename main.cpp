#include "Mainwindow.h"
#include <QtWidgets/QApplication>
#include <gl/glut.h>
#include"ControlLayer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ControlLayer control;
	control.get_mainwindow()->show();
	return a.exec();
}
