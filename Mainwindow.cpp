#include "Mainwindow.h"
#include<qlayout.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	,ui(new Ui::MainwindowClass)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete[] ui;
	delete[] mainwindow_hlayout;
}

void MainWindow::set_window_layout(MainWidget* mainwidget)
{
	mainwindow_hlayout = new QHBoxLayout(this);
	mainwindow_hlayout->addWidget(mainwidget);
	setLayout(mainwindow_hlayout);
}
