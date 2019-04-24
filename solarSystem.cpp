#include "solarSystem.h"



solarSystem::solarSystem()
{
	//the parameter:distanceFromSun(km),orbitTime(day),ratationTime(hour),rotation_angle(degree),image_path
	sun = new planet(0, 1, 601, 2500,7.25,"images/sun.tga");
	mercury = new planet(57910000, 88, 1407, 2440,0,"images/mercury.tga");
	venus = new planet(108200000, 225, 5832, 6052,177.4,"images/venus.tga");
	earth = new planet(149600000, 365, 24, 6371,23.44,"images/earth.tga");
	mars = new planet(227939100, 686, 24, 3389,25.19,"images/mars.tga");
	jupiter = new planet(778500000, 4332, 10, 69911,3.08,"images/jupiter.tga");
	saturn = new planet(1433000000, 10759, 10, 58232,26.7,"images/saturn.tga");
	uranus = new planet(2877000000, 30685, 17, 25362,97.9,"images/uranus.tga");
	neptune = new planet(4503000000, 60188, 16, 24622,27.8,"images/neptune.tga");
}

solarSystem::~solarSystem()
{
	delete[] sun;
	delete[] mercury;
	delete[] venus;
	delete[] earth;
	delete[] mars;
	delete[] jupiter;
	delete[] saturn;
	delete[] uranus;
	delete[] neptune;
}


void solarSystem::calculatePositions(GLint time)
{
		sun->calculatePosition(time);
		mercury->calculatePosition(time);
		venus->calculatePosition(time);
		earth->calculatePosition(time);			
		mars->calculatePosition(time);
		jupiter->calculatePosition(time);
		saturn->calculatePosition(time);
		uranus->calculatePosition(time);
		neptune->calculatePosition(time);
}

void solarSystem::render_system(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,
	Camera* camera, GLboolean lightSwitch)
{
	if (1 == 1)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(75, 1, 1, 1000);

		f->glClearColor(0.0, 0.0, 0.0, 0.0);
		f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		f->glEnable(GL_DEPTH_TEST);
		f->glEnable(GL_CULL_FACE);

		if (lightSwitch==GL_FALSE)
		{
			GLfloat LightAmbient[] = { 0.9f, 0.9f, 0.9f, 1.0f }; 
			GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
			GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };

			glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse); 
			glLightfv(GL_LIGHT1, GL_POSITION, LightPosition); 
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHTING); 
		}
		else
		{
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHTING);
		}
		

		sun->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
				projM, camera);
		mercury->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM,camera);
		venus->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM, camera );
		earth->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM,camera);
		mars->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM, camera );
		jupiter->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM,camera);
		saturn->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM, camera );
		uranus->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM, camera );
		neptune->render_planet(QOpenGLContext::currentContext()->extraFunctions(),
					projM, camera );
	
		f->glDisable(GL_DEPTH_TEST);
		f->glDisable(GL_CULL_FACE);
	}
	else
	{
		f->glClearColor(0.0, 0.0, 0.0, 0.0);
		f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		f->glEnable(GL_DEPTH_TEST);
		f->glEnable(GL_CULL_FACE);

		sun->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		mercury->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		venus->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		earth->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		mars->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		jupiter->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		saturn->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		uranus->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);
		neptune->core_render_planet(QOpenGLContext::currentContext()->extraFunctions(),
			projM, camera);

		f->glDisable(GL_DEPTH_TEST);
		f->glDisable(GL_CULL_FACE);
	}
}
