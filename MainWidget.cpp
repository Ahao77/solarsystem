#include "MainWidget.h"
#include"Mainwindow.h"
#include"Camera.h"
#include"OpenglWidget.h"
#include<qslider.h>

MainWidget::MainWidget(QWidget *parent)
	:QWidget(parent)

{
	//new and set the button
	button1 = new QPushButton("turnback_sun", this);
	button2 = new QPushButton("mercury", this);
	button3 = new QPushButton("venus", this);
	button4 = new QPushButton("earth", this);
	button5 = new QPushButton("mars", this);
	button6 = new QPushButton("jupiter", this);
	button7 = new QPushButton("saturn", this); 
	button8 = new QPushButton("uranus", this);
	button9 = new QPushButton("nuptune", this);
	button_pause = new QPushButton("pause", this);
	button_start = new QPushButton("start", this);
	button_lighton = new QPushButton("light on", this);
	button_lightoff = new QPushButton("light off", this);

	slider = new QSlider(Qt::Horizontal);
	slider->setMinimum(1);
	slider->setMaximum(60*12);
	slider->setValue(60);
	slider->setSingleStep(1);

	date_time = new QDateTimeEdit(QDateTime::currentDateTime(), this);
	date_time->setDisplayFormat("yyyy.MM.dd");	
	date_time->setMinimumDate(QDate::currentDate().addYears(-30));
	date_time->setMaximumDate(QDate::currentDate().addYears(30));
	date_time->setCalendarPopup(true);

	
}


MainWidget::~MainWidget()
{
	delete[] button1;
	delete[] button2;
	delete[] button3;
	delete[] button4;
	delete[] button5;
	delete[] button6;
	delete[] button7;
	delete[] button8;
	delete[] button9;

	delete[] button_pause;
	delete[] button_start;
	delete[] button_lighton;
	delete[] button_lightoff;
	delete[] slider;
	delete[] date_time;

	delete[] main_vlayout;
	delete[] leftlayout;
	delete[] rightlayout;
	delete[] layout;
	delete[] layout1;
}

void MainWidget::set_widget_layout(OpenglWidget*openglwin)
{
	//new the layout
	main_vlayout = new QHBoxLayout();
	leftlayout = new QVBoxLayout();
	rightlayout = new QVBoxLayout();
	layout = new QGridLayout();
	layout1 = new QVBoxLayout();
	layout2 = new QVBoxLayout();

	//set the top grid layout
	layout->addWidget(button1, 0, 0, 1, 2);
	layout->addWidget(button2, 1, 0, 1, 2);
	layout->addWidget(button3, 2, 0, 1, 2);
	layout->addWidget(button4, 3, 0, 1, 2);
	layout->addWidget(button5, 4, 0, 1, 2);
	layout->addWidget(button6, 5, 0, 1, 2);
	layout->addWidget(button7, 6, 0, 1, 2);
	layout->addWidget(button8, 7, 0, 1, 2);
	layout->addWidget(button9, 8, 0, 1, 2);

	//set the middle vlayout
	layout1->addWidget(button_pause, 0, 0);
	layout1->addWidget(button_start, 1, 0);

	layout2->addWidget(button_lighton, 0, 0);
	layout2->addWidget(button_lightoff, 1, 0);

	//set the mainwidget's left part
	leftlayout->addWidget(openglwin);

	//set the mainwidget's right part
	rightlayout->addLayout(layout);
	rightlayout->addLayout(layout1);
	rightlayout->addLayout(layout2);
	rightlayout->addWidget(date_time);
	rightlayout->addWidget(slider);

	//set the main_vlayout
	main_vlayout->addLayout(leftlayout);
	main_vlayout->addLayout(rightlayout);
	this->setLayout(main_vlayout);
}



