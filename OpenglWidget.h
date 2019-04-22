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
	void sun();
	void mercury();
	void venus();
	void earth();
	void mars();
	void jupiter();
	void saturn();
	void uranus();
	void neptune();

	void set_pause();
	void set_start();

	void set_light_switch_off();
	void set_light_switch_on();

protected:
	void initializeGL() Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void resizeGL(int w, int h) Q_DECL_OVERRIDE;
	void OpenglWidget::mousePressEvent(QMouseEvent *event);
	void OpenglWidget::mouseMoveEvent(QMouseEvent *event);
	void check_current_planet();


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

