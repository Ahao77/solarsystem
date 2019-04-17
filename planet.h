#pragma once
#include<vector>
#include<BallShader.h>
#include"Camera.h"
#include"tga.h"

class planet:public BallShader
{
public:
	planet(float distanceFromSun, float orbitTime,float rotationTime,float radius,float ro_angle, char* imagePath);
	~planet();

	void calculatePosition(GLint time);
	void render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera);
	void draw_orbit(Camera* camera, GLfloat distanceFromSun);

	GLfloat position[3];
	GLfloat rotation;
	GLfloat radius;
	GLfloat ro_angle;
private:
	GLfloat distanceFromSun;
	GLint orbitTime;
	GLint rotationTime;
	
	QMatrix4x4 modelM;
	GLuint texture;
	TGA *tga;
};

