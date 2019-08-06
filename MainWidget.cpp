/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：主界面类实现
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#include "MainWidget.h"
#include"Mainwindow.h"
#include"Camera.h"
#include"OpenglWidget.h"
#include<qslider.h>

MainWidget::MainWidget(QWidget *parent)
	:QWidget(parent)

{
	button_pause = new QPushButton("pause", this);
	button_start = new QPushButton("start", this);
	button_lighton = new QPushButton("light on", this);
	button_lightoff = new QPushButton("light off", this);
	button_starmode1= new QPushButton("star mode1", this);
	button_starmode2= new QPushButton("star mode2", this);

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

	fps_label = new QLabel();
	fps_label->setAlignment(Qt::AlignHCenter);
	fps_label->setMaximumHeight(20);


}

MainWidget::~MainWidget()
{
	delete[] button_pause;
	delete[] button_start;
	delete[] button_lighton;
	delete[] button_lightoff;
	delete[] slider;
	delete[] date_time;

	delete[] main_vlayout;
	delete[] leftlayout;
	delete[] rightlayout;

	delete[] layout1;
	delete[] fps_label;
}

void MainWidget::set_widget_layout(OpenglWidget*openglwin)
{
	//new the layout
	main_vlayout = new QHBoxLayout();
	leftlayout = new QVBoxLayout();
	rightlayout = new QVBoxLayout();

	layout1 = new QVBoxLayout();
	layout2 = new QVBoxLayout();

	//set the middle vlayout
	layout1->addSpacing(35);
	layout1->addWidget(button_pause, 0, 0);
	layout1->addWidget(button_start, 1, 0);
	layout1->addSpacing(20);
	layout1->addWidget(fps_label, 2, 0);

	layout1->addSpacing(15);
	layout2->addWidget(button_lighton, 0, 0);
	layout2->addWidget(button_lightoff, 1, 0);

	layout2->addSpacing(30);
	layout2->addWidget(button_starmode1, 0, 0);
	layout2->addWidget(button_starmode2, 1, 0);

	//set the mainwidget's left part
	leftlayout->addWidget(openglwin);

	//set the mainwidget's right part
	rightlayout->addLayout(layout1);
	rightlayout->addLayout(layout2);
	rightlayout->addStretch();
	rightlayout->addWidget(date_time);
	rightlayout->addStretch();
	rightlayout->addWidget(slider);
	rightlayout->addStretch();

	//set the main_vlayout
	main_vlayout->addLayout(leftlayout);
	main_vlayout->addLayout(rightlayout);
	this->setLayout(main_vlayout);
}

void MainWidget::on_fps_changed(int num) const
{
	fps_label->setText("fps:" +QString::number(num));
}

