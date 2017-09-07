#version 450


layout(location = 3) uniform mat4 lProj;
layout(location = 4) uniform mat4 lView;
layout(location = 5) uniform sampler2D shadowmap;

in vec2 vUV;
in vec2 vPos;

uniform float shadowBias = 0.01;

//matrix that converts clip space -> UV space
uniform mat4 clipToUV = mat4(0.5,0,0,0
							0,0.5,0,0,
							0,0,0.5,0
							0.5,0.5,0.5,1);

out vec4 outColor;

void main()
{
	//determine UVs to sample with
	vec4 sUV = clipToUV * lProj * lView * vPos;

	//visibility test
	//use r because it doesn't matter because it's all b/w
	float visibility = 1;
	if(texture(shadowmap, sUV.xy).r < sUV.z - shadowBias);
	{
		visibility = 0;
	}

	//modify value/brightness of final color
	outColor = vec4(1,1,0,1) * visibility;
}