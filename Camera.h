/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*�������������
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
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


