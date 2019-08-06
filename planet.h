/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：星球类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once
#include<vector>
#include"BallShader.h"
#include"CoreBallShader.h"
#include"Camera.h"
#include"tga.h"

class planet:public BallShader,public CoreBallShader
{
public:
	planet(float distanceFromSun, float orbitTime,float rotationTime,float radius,float ro_angle, char* imagePath);
	~planet();

	void calculatePosition(GLint time);//计算当前时间下星球所处角度，并计算公转位置和自转角度
	void render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera);//设定半径，绘制轨道，渲染单个星球
	void core_render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 projM, Camera* camera);
	void draw_orbit(Camera* camera, GLfloat distanceFromSun);//绘制轨道

	GLfloat position[3];
	GLfloat rotation;
	GLfloat radius;
	GLfloat ro_angle;
	QMatrix4x4 *modelM;
private:
	GLfloat distanceFromSun;
	GLint orbitTime;
	GLint rotationTime;
	GLuint texture;
	TGA *tga;
};

