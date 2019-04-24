#pragma once
#include<vector>
#include"planet.h"
#include"Camera.h"
#include"tga.h"

class solarSystem
{
public:
	solarSystem();
	~solarSystem();

	void calculatePositions(GLint time);
	void render_system(QOpenGLExtraFunctions *f, QMatrix4x4 projM,Camera* camera,GLboolean lightSwitch);
	void draw_star();

	planet *sun;
	planet *mercury;
	planet *venus;
	planet *earth;
	planet *mars;
	planet *jupiter;
	planet *saturn;
	planet *uranus;
	planet *neptune;
	planet *pluto;

	TGA *background_tga1;
	GLuint background_texture1;
	TGA *background_tga2;
	GLuint background_texture2;
	GLint star_mode;
};

