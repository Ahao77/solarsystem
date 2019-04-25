/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*���������Ʋ���
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
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

