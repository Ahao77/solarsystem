#version 330 core
uniform mat4 uPMatrix, camMatrix, uMmatrix;
layout(location = 0) in vec3 aPosition;
smooth out vec vPosition;

void main(void)
{
	gl_Position = uPMatrix * camMatrix * uMMatrix * vec4(aPosition, 1);
	vPosition = aPosition;
}