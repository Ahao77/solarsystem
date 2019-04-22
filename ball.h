#pragma once
#include"constant.h"

class ball
{
public:
	ball();
	~ball();
	float m_r;
	virtual void send_radius(float r)=0;
	



};

