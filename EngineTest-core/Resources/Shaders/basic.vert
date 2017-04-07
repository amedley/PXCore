#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec4 in_color;

varying vec4 out_color;

uniform mat4 pr_matrix;

void main()
{
	gl_Position = pr_matrix * vec4(in_position, 1.0);
	out_color = in_color;
}