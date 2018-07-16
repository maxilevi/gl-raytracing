#version 330 core

layout(location = 0) in vec2 in_vertex;

out vec2 uvs;

void main(void)
{
	gl_Position = vec4(in_vertex, 0.0, 1.0);
	uvs = vec2((in_vertex.x + 1.0) / 2.0, 1.0 - (in_vertex.y + 1.0) / 2.0);
}
