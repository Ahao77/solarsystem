/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：球渲染core方法类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once
#include<qopenglextrafunctions.h>
#include<qopenglshaderprogram.h>
#include<qopenglbuffer.h>
#include<constant.h>
#include"Camera.h"
#include"ball.h"
#include"GL/glut.h"

class CoreBallShader:public ball
{
public:
	CoreBallShader();
	~CoreBallShader();
	void render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM, Camera* camera,
		QMatrix4x4 *modelM, GLfloat* position, float rotation, float ro_angle, GLuint texture, GLfloat distanceFromSun);
	void send_radius(float r);
	void calculate_m_points();

private:
	QOpenGLShaderProgram m_program;
	QOpenGLBuffer m_vbo;
	QVector<GLfloat> m_points;
};

