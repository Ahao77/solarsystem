#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mainwindow.h"
#include<qlayout.h>
#include<MainWidget.h>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	void set_window_layout(MainWidget* mainwidget);

private:
	Ui::MainwindowClass *ui;
	QHBoxLayout *mainwindow_hlayout;
};
