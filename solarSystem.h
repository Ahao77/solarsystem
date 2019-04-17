#pragma once
#include<vector>
#include"planet.h"
#include"Camera.h"

class solarSystem
{
public:
	solarSystem();
	~solarSystem();

	void calculatePositions(GLint time);
	void render_system(QOpenGLExtraFunctions *f, QMatrix4x4 &projM,Camera* camera);

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
	

};

