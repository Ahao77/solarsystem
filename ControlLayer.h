#pragma once
#include"Mainwindow.h"
#include"qdatetimeedit.h"

class ControlLayer:public QObject
{
public:
	ControlLayer();
	~ControlLayer();
	MainWindow* get_mainwindow();
	void set_connect();
	


public slots:
	void set_speed();
	void set_times();
	GLboolean isLeapYear(GLint yaer);
	GLint getDays(GLint year,GLint month,GLint day);
	void initial_time();

private:
	MainWindow *mainwindow;
	MainWidget *mainwidget;
	OpenglWidget *openglwin;
	QDateTimeEdit *now_time;
};

