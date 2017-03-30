#version 330 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;

uniform mat4 pr_matrix;
uniform mat4 ml_matrix;

varying vec4 out_color;

void main()
{
	gl_Position = pr_matrix * ml_matrix * in_position;
	out_color = in_color;
}