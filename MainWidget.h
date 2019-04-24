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
	void set_speed();

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

