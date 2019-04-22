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

	void calculatePosition(GLint time);
	void render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera);
	void planet::core_render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM, Camera* camera);
	void draw_orbit(Camera* camera, GLfloat distanceFromSun);

	GLfloat position[3];
	GLfloat rotation;
	GLfloat radius;
	GLfloat ro_angle;
	QMatrix4x4 modelM;

private:
	GLfloat distanceFromSun;
	GLint orbitTime;
	GLint rotationTime;
	GLuint texture;
	TGA *tga;
};

