/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：球渲染类
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

class BallShader:public ball
{
public:
	BallShader();
	~BallShader();
	void render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera,
		 GLfloat* position, float rotation, float ro_angle,GLuint texture, GLfloat distanceFromSun);
	void send_radius(float r);
protected:
	GLUquadricObj* text;
};

