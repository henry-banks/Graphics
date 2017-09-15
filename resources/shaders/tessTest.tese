#version 450

//The MAGIC line??
layout(triangles, equal_spacing, cw) in;

in vec3 tcPos[];
out vec3 tePos;
//don't forget patches are 'tessellation geometry'
out vec3 tePatchDistance;

uniform mat4 proj;
uniform mat4 model;

void main()
{
	vec3 p0 gl_TessCoord.x * tcPos[0];
	vec3 p1 gl_TessCoord.y * tcPos[1];
	vec3 p2 gl_TessCoord.z * tcPos[2];

	tePatchDistance = gl_TessCoord;
	//this is ico-specific to turn it into a sphere?
	tePos = normalize(p0 + p1 + p2);
	gl_Position = proj * model * vec4(tePos, 1);
}