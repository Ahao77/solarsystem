/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：主界面类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once
#include <qwidget.h>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include<qslider.h>
#include<qdatetimeedit.h>
#include<qdockwidget.h>
#include <OpenglWidget.h>

class MainWidget :
	public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

	void set_widget_layout(OpenglWidget*openglwin);

	QPushButton *button_pause;
	QPushButton *button_start;
	QLabel *fps_label;

	QPushButton *button_lighton;
	QPushButton *button_lightoff;

	QPushButton *button_starmode1;
	QPushButton *button_starmode2;

	QDateTimeEdit *date_time;
	QSlider *slider;
public slots:
	void on_fps_changed(int num) const;
private:
	QHBoxLayout *main_vlayout;
	QVBoxLayout *leftlayout;
	QVBoxLayout *rightlayout;
	QVBoxLayout *layout1;
	QVBoxLayout *layout2;
};

