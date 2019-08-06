#version 330 core
in vec3 vPosition;
out vec4 fragColor;

void main(void)
{
	vec3 color;
	color = vec3(1.0, 1.0, 1.0);
	fragColor = vec4(color, 0);
}