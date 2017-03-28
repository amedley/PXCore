#version 330 core

layout (location = 0) out vec4 color;

uniform vec3 light_pos;
varying vec3 model_pos;

void main()
{
	float intensity = 1.0f / length(light_pos - model_pos) * 0.1;
	color = vec4(1.0, 0.0, 1.0, 1.0) * intensity;
}