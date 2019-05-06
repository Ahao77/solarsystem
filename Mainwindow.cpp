/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：主窗口实现
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#include "Mainwindow.h"
#include<qlayout.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainwindowClass)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete[] ui;
	delete[] mainwindow_hlayout;
	delete[] layout;

	delete[] right_dock1;
	delete[] dock_widget_content;
	delete[] dock_right1;

	delete[] button1;
	delete[] button2;
	delete[] button3;
	delete[] button4;
	delete[] button5;
	delete[] button6;
	delete[] button7;
	delete[] button8;
	delete[] button9;
}

void MainWindow::set_window_layout(MainWidget* mainwidget)
{
	mainwindow_hlayout = new QHBoxLayout(this);
	mainwindow_hlayout->addWidget(mainwidget);
	setLayout(mainwindow_hlayout);
}

void MainWindow::set_window_dock()
{	
	right_dock1 = new QDockWidget(tr("choose the viewing target"), this);
	right_dock1->setAllowedAreas(Qt::RightDockWidgetArea);
	right_dock1->setMinimumSize(100, 400);

	dock_widget_content = new QWidget(right_dock1);
	dock_right1 = new QWidget(dock_widget_content);
	layout = new QVBoxLayout(dock_right1);

	button1 = new QPushButton("turnback_sun");
	button2 = new QPushButton("mercury");
	button3 = new QPushButton("venus");
	button4 = new QPushButton("earth");
	button5 = new QPushButton("mars");
	button6 = new QPushButton("jupiter");
	button7 = new QPushButton("saturn");
	button8 = new QPushButton("uranus");
	button9 = new QPushButton("nuptune");

	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);
	layout->addWidget(button5);
	layout->addWidget(button6);
	layout->addWidget(button7);
	layout->addWidget(button8);
	layout->addWidget(button9);

	right_dock1->setWidget(dock_widget_content);
	this->addDockWidget(Qt::RightDockWidgetArea,right_dock1);	
}