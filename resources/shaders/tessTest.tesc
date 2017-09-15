#version 450

//the magic line?
layout(vertices = 3) out;

in vec3 vPos[];
out vec3 tcPos[];

uniform float tessLevelInner;
uniform float tessLevelOuter;

void main()
{
	tcPos(ID == 0){
		gl_TessLevelInner[0] = tessLevelInner;
		gl_TessLevelOuter[0] = tessLevelOuter;
		gl_TessLevelOuter[1] = tessLevelOuter;
		gl_TessLevelOuter[2] = tessLevelOuter;
	}
}