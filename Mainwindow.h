#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mainwindow.h"

class Mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	Mainwindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainwindowClass ui;
};
