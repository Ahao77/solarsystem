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

