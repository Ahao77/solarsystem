/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：控制层类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

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

