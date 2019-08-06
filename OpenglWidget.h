/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：绘图界面类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once

#include<qwindow.h>
#include<qwidget.h>
#include<qcoreapplication.h>
#include<qopenglwidget.h>
#include<qopenglfunctions.h>
#include<qopenglshaderprogram.h>
#include<qevent.h>
#include<GL/glut.h>
#include"BallShader.h"
#include"planet.h"
#include"solarSystem.h"
#include"Camera.h"

class OpenglWidget:public QOpenGLWidget,protected QOpenGLFunctions
{
	Q_OBJECT

public:
	explicit OpenglWidget(QWidget *parent = nullptr);
	~OpenglWidget();
	void timeset(GLint tim);
	void speedset(GLint spe);

public slots:
	//指定星球按钮而改变相机目标的槽函数
	void sun();
	void mercury();
	void venus();
	void earth();
	void mars();
	void jupiter();
	void saturn();
	void uranus();
	void neptune();
	//设置渲染场景暂停与运动的槽函数
	void set_pause();
	void set_start();
	//设置渲染场景全局灯亮和灯灭的槽函数
	void set_light_switch_off();
	void set_light_switch_on();
	//改变渲染背景图片的槽函数
	void set_star_mode1();
	void set_star_mode2();

signals:
	void fpschanged(int value) const;

protected:
	void initializeGL() Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void resizeGL(int w, int h) Q_DECL_OVERRIDE;

	void OpenglWidget::mousePressEvent(QMouseEvent *event);
	void OpenglWidget::mouseMoveEvent(QMouseEvent *event);

	void check_current_planet();//确定当前观察星球，指定相机目标
	void calculate_frame_rate();//计算帧率

private:
	QMatrix4x4 projM;
	solarSystem *solarsystem;
	Camera *camera;
	GLint times;
	QPoint lastPos;
	currentplanet current_planet;
	GLint speed;
	GLboolean pause;
	GLboolean lightSwitch;
};

