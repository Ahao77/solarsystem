/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*����������Ⱦ��ʵ��
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
**/

#include "BallShader.h"
#include"Camera.h"
#include<GL/glut.h>
#include<tga.h>

BallShader::BallShader()
{
}


BallShader::~BallShader()
{
	delete[] text;
}

void BallShader::send_radius(float r)
{
	m_r = r * planetSizeScale;
}


void BallShader::render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera,
	GLfloat* position, float rotation,float ro_angle, GLuint texture, GLfloat distanceFromSun)
{
	glPushMatrix();

	//���ù۲�ģʽ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera->m_eye[0], camera->m_eye[1], camera->m_eye[2],
		camera->m_target[0], camera->m_target[1], camera->m_target[1],
		camera->m_up[0], camera->m_up[1], camera->m_up[2]);
	
	//���������λ�ƺ���ת��
	glTranslatef(position[0] * distanceScale, position[1] * distanceScale, position[2] * distanceScale);
	glRotatef(ro_angle, 1,0, 0);
	glRotatef(rotation, 0, 0, 1 );

	//�����۲���ӿ�
	glViewport(0, 0, 1300, 900);

	//��������л���
	glEnable(GL_TEXTURE_2D);
	text = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, texture);
	gluQuadricTexture(text, GL_TRUE);
	gluSphere(text, m_r, 64, 64);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}


