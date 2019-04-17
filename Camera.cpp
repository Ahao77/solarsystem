#include "Camera.h"
#include "constant.h"
#include<cmath>
#include<qcoreapplication.h>
#include<qopenglfunctions.h>
#include<qopenglshaderprogram.h>



Camera::Camera():m_up(0.0f,0.0f,1.0f)
{
	distance = 5;
	angle_xy = PI;
	angle_z = PI / 8;
	m_eye[0] = distance * cos(angle_z)*cos(angle_xy);
	m_eye[1] = distance * cos(angle_z)*sin(angle_xy);
	m_eye[2] = distance*sin(angle_z);

	m_target[0] = 0.0f;
	m_target[1] = 0.0f;
	m_target[2] = 0.0f;

	cameraM.lookAt(m_eye, m_target, m_up);
}


Camera::~Camera()
{

}