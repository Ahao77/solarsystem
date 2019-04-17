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


