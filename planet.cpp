#include "planet.h"

#include<cmath>
#include<constant.h>
#include<gl/freeglut.h>
#include<gl/glut.h>

planet::planet(float distanceFromSun, float orbitTime, float rotationTime, float radius,float ro_angle,char* imagePath)
{
	this->distanceFromSun = distanceFromSun;
	this->orbitTime = orbitTime;
	this->rotationTime = rotationTime;
	this->radius = radius;
	this->ro_angle = ro_angle;

	modelM.setToIdentity();

	tga = new TGA(imagePath);
	texture = tga->getTextureHandle();
}

planet::~planet()
{
	delete[] tga;
}

void planet::calculatePosition(GLint time)
{
	float angle= (-time%(orbitTime*24*60)) * 6.28f / (orbitTime*24*60);

	this->rotation = (time%(60*this->rotationTime)) * 360 / (60*this->rotationTime);

	this->position[0] = sin(angle) * this->distanceFromSun;
	this->position[1] = cos(angle) * this->distanceFromSun;
	this->position[2] = 0;
}

void planet::render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera)
{
		BallShader::send_radius(radius);

		draw_orbit(camera, distanceFromSun);

		BallShader::render(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera, this->position, this->rotation, this->ro_angle, this->texture, distanceFromSun);
}

void planet::core_render_planet(QOpenGLExtraFunctions *f, QMatrix4x4 &projM, Camera* camera)
{
		CoreBallShader::send_radius(radius);

		draw_orbit(camera, distanceFromSun);

		CoreBallShader::render(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera, modelM ,this->position, this->rotation, this->ro_angle, this->texture, distanceFromSun);
}

void planet::draw_orbit(Camera* camera, GLfloat distanceFromSun)
{
	glPushMatrix();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera->m_eye[0], camera->m_eye[1], camera->m_eye[2],
		camera->m_target[0], camera->m_target[1], camera->m_target[1],
		camera->m_up[0], camera->m_up[1], camera->m_up[2]);

	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINE_STRIP);

	for (float angle = 0.0f; angle < 6.28f; angle += 0.05f)
	{
		glVertex3f(sin(angle)*distanceFromSun*distanceScale, cos(angle)*distanceFromSun*distanceScale, 0.0f);

	}
	glVertex3f(0.0f, distanceFromSun*distanceScale, 0.0f);
	glEnd();

	glViewport(0, 0, 900, 900);

	glPopMatrix();
}