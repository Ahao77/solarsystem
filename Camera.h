/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：摄像机类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/
#pragma once
#include<qcoreapplication.h>
#include<qopenglfunctions.h>
#include<qopenglshaderprogram.h>

class Camera
{
public:
	Camera();
	~Camera();	
	QMatrix4x4 cameraM;
	QVector3D m_eye, m_target,m_up;
	GLfloat distance;
	GLfloat angle_z;
	GLfloat angle_xy;
};


