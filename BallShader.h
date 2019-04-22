#pragma once

#include<qopenglextrafunctions.h>
#include<qopenglshaderprogram.h>
#include<qopenglbuffer.h>
#include<constant.h>
#include"Camera.h"
#include"ball.h"
#include"GL/glut.h"

class BallShader:public ball
{
public:
	BallShader();
	~BallShader();
	void render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera,
		 GLfloat* position, float rotation, float ro_angle,GLuint texture, GLfloat distanceFromSun);
	void send_radius(float r);

protected:
	GLUquadricObj* text;
};

