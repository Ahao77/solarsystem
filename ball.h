/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*��������ĳ�����
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
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

