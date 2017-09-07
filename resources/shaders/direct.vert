#version 450

layout(location = 0) in vec4 pos;
layout(location = 2) in vec4 texCoord;
layout(location = 3) in vec4 normal;

layout(location = 0) uniform vec4 pos;
layout(location = 1) uniform vec4 pos;
layout(location = 2) uniform vec4 pos;

out vec4 vPos;
out vec2 vUV;

void main()
{
	vUV = texCoord;
	vPos = model * pos;
	gl_Position = proj * view * model * pos;
}