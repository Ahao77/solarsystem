/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*������������
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
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

	void calculatePosition(GLint time);//���㵱ǰʱ�������������Ƕȣ������㹫תλ�ú���ת�Ƕ�
	void render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera);//�趨�뾶�����ƹ������Ⱦ��������
	void core_render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 projM, Camera* camera);
	void draw_orbit(Camera* camera, GLfloat distanceFromSun);//���ƹ��

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

