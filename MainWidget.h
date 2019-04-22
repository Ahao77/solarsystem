#pragma once
#include <qwidget.h>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include<qslider.h>
#include<qdatetimeedit.h>
#include <OpenglWidget.h>

class MainWidget :
	public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();
	void set_widget_layout(OpenglWidget*openglwin);
	void set_speed();


	QPushButton *button1;
	QPushButton *button2;
	QPushButton *button3;
	QPushButton *button4;
	QPushButton *button5;
	QPushButton *button6;
	QPushButton *button7;
	QPushButton *button8;
	QPushButton *button9;

	QPushButton *button_pause;
	QPushButton *button_start;

	QPushButton *button_lighton;
	QPushButton *button_lightoff;

	QSlider *slider;

	QDateTimeEdit *date_time;

private:
	QHBoxLayout *main_vlayout;
	QVBoxLayout *leftlayout;
	QVBoxLayout *rightlayout;
	QGridLayout *layout;
	QVBoxLayout *layout1;
	QVBoxLayout *layout2;
};

