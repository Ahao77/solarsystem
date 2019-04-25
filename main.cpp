/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：主程序入口
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
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
