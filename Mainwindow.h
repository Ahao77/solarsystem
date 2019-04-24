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
