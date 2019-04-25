/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：主窗口类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mainwindow.h"
#include<qlayout.h>
#include<qwidget.h>
#include<qpushbutton.h>
#include<qdockwidget.h>
#include<qboxlayout.h>
#include<MainWidget.h>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	
	void set_window_layout(MainWidget* mainwidget);
	void set_window_dock();

	QPushButton *button1;
	QPushButton *button2;
	QPushButton *button3;
	QPushButton *button4;
	QPushButton *button5;
	QPushButton *button6;
	QPushButton *button7;
	QPushButton *button8;
	QPushButton *button9;

private:
	Ui::MainwindowClass *ui;
	QHBoxLayout *mainwindow_hlayout;

	QDockWidget *right_dock1;
	QWidget *dock_widget_content;
	QWidget *dock_right1;

	QHBoxLayout *opengl_button_layout;
	QVBoxLayout *layout;
};
