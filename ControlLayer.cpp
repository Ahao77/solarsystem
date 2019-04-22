#include "ControlLayer.h"
#include<qdebug.h>


ControlLayer::ControlLayer()
{
	//initial the mainwindow <- mainwidget <-  openglwidget
	mainwindow = new MainWindow();
	mainwidget = new MainWidget(mainwindow);
	openglwin = new OpenglWidget(mainwidget);

	//set their size
	mainwindow->setMinimumWidth(1100);
	mainwindow->setMinimumHeight(900);
	mainwidget->setMinimumSize(1100, 900);
	openglwin->setMinimumSize(900, 900);

	//set their layout
	mainwindow->set_window_layout(mainwidget);	
	mainwidget->set_widget_layout(openglwin);

	//set the signal and slot
	set_connect();

	now_time = new QDateTimeEdit(QDateTime::currentDateTime());
	initial_time();


}


ControlLayer::~ControlLayer()
{
}

MainWindow* ControlLayer::get_mainwindow()
{
	return mainwindow;
}

void ControlLayer::set_connect()
{
	QObject::connect(mainwidget->button1, SIGNAL(clicked()), openglwin, SLOT(sun()));
	QObject::connect(mainwidget->button2, SIGNAL(clicked()), openglwin, SLOT(mercury()));
	QObject::connect(mainwidget->button3, SIGNAL(clicked()), openglwin, SLOT(venus()));
	QObject::connect(mainwidget->button4, SIGNAL(clicked()), openglwin, SLOT(earth()));
	QObject::connect(mainwidget->button5, SIGNAL(clicked()), openglwin, SLOT(mars()));
	QObject::connect(mainwidget->button6, SIGNAL(clicked()), openglwin, SLOT(jupiter()));
	QObject::connect(mainwidget->button7, SIGNAL(clicked()), openglwin, SLOT(saturn()));
	QObject::connect(mainwidget->button8, SIGNAL(clicked()), openglwin, SLOT(uranus()));
	QObject::connect(mainwidget->button9, SIGNAL(clicked()), openglwin, SLOT(neptune()));

	QObject::connect(mainwidget->button_pause, &QPushButton::clicked, openglwin, &OpenglWidget::set_pause);
	QObject::connect(mainwidget->button_start, &QPushButton::clicked, openglwin, &OpenglWidget::set_start);
	QObject::connect(mainwidget->button_lighton, &QPushButton::clicked, openglwin, &OpenglWidget::set_light_switch_on);
	QObject::connect(mainwidget->button_lightoff, &QPushButton::clicked, openglwin, &OpenglWidget::set_light_switch_off);

	QObject::connect(mainwidget->slider, &QSlider::valueChanged, this, &ControlLayer::set_speed);

	QObject::connect(mainwidget->date_time, &QDateTimeEdit::dateChanged, this, &ControlLayer::set_times);

}

void ControlLayer::set_speed()
{
	openglwin->speedset(mainwidget->slider->value());
}

void ControlLayer::initial_time()
{
	GLint standard_time = getDays(1982, 3, 10);
	QString date = now_time->date().toString("yyyy/MM/dd");
	GLint year = date.mid(0, 4).toInt();
	GLint month = date.mid(5, 2).toInt();
	GLint day = date.mid(8, 2).toInt();
	GLint now_time = getDays(year, month, day);
	GLint delta = (now_time - standard_time) * 24;
	openglwin->timeset(delta);
}

void ControlLayer::set_times()
{
	GLint standard_time = getDays(1982, 3, 10);
	QString date = mainwidget->date_time->date().toString("yyyy/MM/dd");
	GLint year = date.mid(0, 4).toInt();
	GLint month = date.mid(5, 2).toInt();
	GLint day = date.mid(8, 2).toInt();
	GLint select_time = getDays(year, month, day);
	GLint delta = (select_time - standard_time) * 24;
	openglwin->timeset(delta);
}

GLboolean ControlLayer::isLeapYear(GLint year)
{
	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}


GLint ControlLayer::getDays(GLint year, GLint month, GLint day)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year))
		m[2]++;
	int result = 0;
	for (int i = 1; i < year; i++)
	{
		result += 365;
		if (isLeapYear(i))
			result++;
	}
	for (int i = 1; i < month; i++)
	{
		result += m[i];
	}
	result += day;

	return result;
}