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

void BallShader::calculate_m_points(float r)
{
	m_points.clear();

	m_r = r * planetSizeScale;

	/*int angleSpan = 10;

	for (int vAngle = -90; vAngle < 90; vAngle += angleSpan)
	{
		for (int hAngle = 0; hAngle <= 360; hAngle += angleSpan)
		{
			float x0 = m_r * ::cos(vAngle * PI / 180) * ::cos(hAngle * PI / 180);
			float y0 = m_r * ::cos(vAngle * PI / 180) * ::sin(hAngle * PI / 180);
			float z0 = m_r * ::sin(vAngle * PI / 180);

			float x1 = m_r * ::cos(vAngle * PI / 180) * ::cos((hAngle + angleSpan) * PI / 180);
			float y1 = m_r * ::cos(vAngle * PI / 180) * ::sin((hAngle + angleSpan) * PI / 180);
			float z1 = m_r * ::sin(vAngle * PI / 180);

			float x2 = m_r * ::cos((vAngle + angleSpan) * PI / 180) * ::cos((hAngle + angleSpan) * PI / 180);
			float y2 = m_r * ::cos((vAngle + angleSpan) * PI / 180) * ::sin((hAngle + angleSpan) * PI / 180);
			float z2 = m_r * ::sin((vAngle + angleSpan) * PI / 180);

			float x3 = m_r * ::cos((vAngle + angleSpan) * PI / 180) * ::cos(hAngle * PI / 180);
			float y3 = m_r * ::cos((vAngle + angleSpan) * PI / 180) * ::sin(hAngle * PI / 180);
			float z3 = m_r * ::sin((vAngle + angleSpan) * PI / 180);


			m_points << x1 << y1 << z1 << x3 << y3 << z3
				<< x0 << y0 << z0 << x1 << y1 << z1
				<< x2 << y2 << z2 << x3 << y3 << z3;

		}
	}*/
}


void BallShader::render(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera,
	 QMatrix4x4 &modelM,GLfloat* position, float rotation,float ro_angle, GLuint texture, GLfloat distanceFromSun)
{
	m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Vertex,
		"vsrc.glsl");
	m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Fragment,
		"fsrc.glsl");
	m_program.link();
	m_program.bind();

	//m_vbo.create();
	//m_vbo.bind();
	//m_vbo.allocate(m_points.constData(), m_points.count() * sizeof(GLfloat));
	//m_program.enableAttributeArray(0);
	
	

	

	/*m_program.setUniformValue("uPMatrix", projM);
	m_program.setUniformValue("camMatrix", camera->cameraM);
	m_program.setUniformValue("uPMatrix", modelM);
	m_program.setUniformValue("uR", m_r);*/



	glPushMatrix();
	text = gluNewQuadric();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera->m_eye[0], camera->m_eye[1], camera->m_eye[2],
		camera->m_target[0], camera->m_target[1], camera->m_target[1],
		camera->m_up[0], camera->m_up[1], camera->m_up[2]);
	
	glTranslatef(position[0] * distanceScale, position[1] * distanceScale, position[2] * distanceScale);
	glRotatef(ro_angle, 1,0, 0);
	glRotatef(rotation, 0, 0, 1 );

	/*m_program.setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);*/
	//f->glDrawArrays(GL_TRIANGLES, 0, m_points.count() / 3);

	glViewport(0, 0, 900, 900);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluQuadricTexture(text, GL_TRUE);
	gluSphere(text, m_r, 64, 64);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	//m_program.disableAttributeArray(0);
	m_vbo.release();
	m_program.release();
}



