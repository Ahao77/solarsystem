/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*�����������涨��ͷ�ļ�
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
**/
#pragma once

const float planetSizeScale = 0.000025f;//����뾶�ı�����

const float distanceScale = 0.00000001f;//������̫������ı�����

const float PI = 3.14159265f;

const float rate = 0.01f;//����ƶ�������

enum currentplanet//��ǰ�۲�������־
{
	Sun,Mercury,Venus,Earth,Mars,
	Jupiter,Saturn,Uranus,Neptune,Pluto
};

enum star_mode//�������ǵ�ģʽ��־
{
	SMALL_STAR,BIG_STAR
};