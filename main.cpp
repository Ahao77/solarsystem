/**
*��˾������ͼ���Ƽ����޹�˾
*��Ȩ��Ϣ��ͼ������
*����̫��ϵģ�⹹��ʵϰ��ҵ
*���������������
*
*�汾��1.1
*���ߣ�Ҷ��ƽ
*���ڣ�2019/4/25
**/
#include "Mainwindow.h"
#include <QtWidgets/QApplication>
#include <GL/glut.h>
#include"ControlLayer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ControlLayer control;
	control.get_mainwindow()->show();
	return a.exec();
}
