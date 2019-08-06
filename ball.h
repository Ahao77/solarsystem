/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：球的抽象类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

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

