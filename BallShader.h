#pragma once

#include<qopenglextrafunctions.h>
#include<qopenglshaderprogram.h>
#include<qopenglbuffer.h>
#include<constant.h>
#include"Camera.h"
#include"GL/glut.h"

class BallShader
{
public:
	BallShader();
	~BallShader();

	void calculate_m_points(float r);
	void render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera,
		QMatrix4x4 &modelM, GLfloat* position, float rotation, float ro_angle,GLuint texture, GLfloat distanceFromSun);
	


protected:
	float m_r;
	QOpenGLShaderProgram m_program;
	QOpenGLBuffer m_vbo;
	QVector<GLfloat> m_points;
	GLUquadricObj* text;
};

