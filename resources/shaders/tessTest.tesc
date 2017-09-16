#version 450

//the magic line?
layout(vertices = 3) out;

in vec3 vPos[];
out vec3 tcPos[];

layout(location = 9)uniform float tessLevelInner;
layout(location = 10)uniform float tessLevelOuter;

//woah what
#define ID gl_InvocationID

void main()
{
	tcPos[ID] = vPos[ID];
	if(ID == 0){
		gl_TessLevelInner[0] = tessLevelInner;
		gl_TessLevelOuter[0] = tessLevelOuter;
		gl_TessLevelOuter[1] = tessLevelOuter;
		gl_TessLevelOuter[2] = tessLevelOuter;
	}
}