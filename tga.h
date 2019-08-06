/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：tga文件处理类
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/

#pragma once
#include<GL/glut.h>

// This is a class that loads TGA files into opengl textures
class TGA
{
private:
	// the handle for the texture in opengl
	GLuint textureHandle;
public:
	// Constructs and loads a TGA into opengl from the given image file path
	TGA(char* imagePath);

	// Returns the handle to the texture created from the image, for binding to opengl
	GLuint getTextureHandle(void);
};
