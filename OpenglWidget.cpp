#include "OpenglWidget.h"
#include "Mainwindow.h"
#include "MainWidget.h"
#include"constant.h"
#include<gl/glut.h>
#include"planet.h"
#include<ctime>
#include<Windows.h>



OpenglWidget::OpenglWidget(QWidget *parent)
	:QOpenGLWidget(parent),current_planet(Sun),speed(12),pause(GL_FALSE)
{

}


OpenglWidget::~OpenglWidget()
{
	delete[] solarsystem;
	delete[] camera;
}


void OpenglWidget::initializeGL()
{	
	solarsystem = new solarSystem();
	camera=new Camera();
	solarsystem->calculatePositions(times);
}

void OpenglWidget::paintGL() 
{
	solarsystem->calculatePositions(times);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 1000);

	check_current_planet();

	solarsystem->render_system(QOpenGLContext::currentContext()->extraFunctions(),
		m_pMatrix,camera);

	if (pause == GL_FALSE)
		times += speed;
	else if(pause == GL_TRUE)
		times = times;
	update();
}

void OpenglWidget::resizeGL(int w, int h)
{
	m_pMatrix.setToIdentity();
	m_pMatrix.perspective(45.0f, GLfloat(w) / (GLfloat)h, 0.01f, 100.0f);
}

void OpenglWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}

void OpenglWidget::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton)
	{
		camera->angle_xy += dx * rate;
		camera->angle_z += dy * rate;

		if (camera->angle_xy > PI*3/2)
			camera->angle_xy = PI*3/2;
		if (camera->angle_xy < PI / 2)
			camera->angle_xy = PI / 2;

		if (camera->angle_z > PI / 6)
			camera->angle_z = PI / 6 ;
		if (camera->angle_z < PI/32)
			camera->angle_z = PI/32;

	}
	else if (event->buttons() & Qt::RightButton)
	{
		camera->distance += dy*15*rate;
	if (camera->distance > 200)
		camera->distance = 200;
	if (camera->distance < 2)
		camera->distance = 2;
	}
	lastPos = event->pos();
}

void OpenglWidget::check_current_planet()
{
	switch (current_planet)
	{
	case Sun:
	{
		camera->m_target[0] = 0.0f;
		camera->m_target[1] = 0.0f;
		camera->m_target[2] = 0.0f;

		camera->m_eye[0] = camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));

		break;
	}

	case Mercury:
	{
		camera->m_target[0] = solarsystem->mercury->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->mercury->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->mercury->position[2] * distanceScale;

		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Venus:
	{
		camera->m_target[0] = solarsystem->venus->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->venus->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->venus->position[2] * distanceScale;


		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Earth:
	{
		camera->m_target[0] = solarsystem->earth->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->earth->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->earth->position[2] * distanceScale;


		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Mars:
	{
		camera->m_target[0] = solarsystem->mars->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->mars->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->mars->position[2] * distanceScale;

		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Jupiter:
	{
		camera->m_target[0] = solarsystem->jupiter->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->jupiter->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->jupiter->position[2] * distanceScale;

		camera->m_eye[0] =(camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy));
		camera->m_eye[1] = (camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy));
		camera->m_eye[2] =(camera->m_target[2] + camera->distance * sin(camera->angle_z));
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	} /*(solarsystem->jupiter->radius)/10000**/
	case Saturn:
	{
		camera->m_target[0] = solarsystem->saturn->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->saturn->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->saturn->position[2] * distanceScale;

		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Uranus:
	{
		camera->m_target[0] = solarsystem->uranus->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->uranus->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->uranus->position[2] * distanceScale;

		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	case Neptune:
	{
		camera->m_target[0] = solarsystem->neptune->position[0] * distanceScale;
		camera->m_target[1] = solarsystem->neptune->position[1] * distanceScale;
		camera->m_target[2] = solarsystem->neptune->position[2] * distanceScale;

		camera->m_eye[0] = camera->m_target[0] + camera->distance * cos(camera->angle_z)*cos(camera->angle_xy);
		camera->m_eye[1] = camera->m_target[1] + camera->distance * cos(camera->angle_z)*sin(camera->angle_xy);
		camera->m_eye[2] = camera->m_target[2] + camera->distance * sin(camera->angle_z);
		camera->m_up = QVector3D::crossProduct(camera->m_eye - camera->m_target, QVector3D(0, -1, 0));
		break;
	}
	}

}

void OpenglWidget::sun()
{
	current_planet = Sun;
}

void OpenglWidget::mercury()
{
	current_planet = Mercury;
}

void OpenglWidget::venus()
{
	current_planet = Venus;
}

void OpenglWidget::earth()
{
	current_planet = Earth;
}

void OpenglWidget::mars()
{
	current_planet = Mars;
}

void OpenglWidget::jupiter()
{
	current_planet = Jupiter;
}

void OpenglWidget::saturn()
{
	current_planet = Saturn;
}

void OpenglWidget::uranus()
{
	current_planet = Uranus;
}

void OpenglWidget::neptune()
{
	current_planet = Neptune;
}

void OpenglWidget::speedset(GLint spe)
{
	speed = spe;
}

void OpenglWidget::timeset(GLint tim)
{
	times = tim;
}

void OpenglWidget::set_pause()
{
	pause = GL_TRUE;
}

void OpenglWidget::set_start()
{
	pause = GL_FALSE;
}

