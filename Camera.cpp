/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：摄像机类实现
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/
#include "Camera.h"
#include "constant.h"
#include<cmath>
#include<qcoreapplication.h>
#include<qopenglfunctions.h>
#include<qopenglshaderprogram.h>

Camera::Camera():m_up(0.0f,0.0f,1.0f)
{
	//初始化在球坐标系下的距离和角度
	distance = 5;
	angle_xy = PI;
	angle_z = PI / 8;

	//球坐标系计算出笛卡尔坐标系坐标
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