#version 450

//wtf??
layout(triangles, invocations = 3) in;
//layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

//this is used to do wireframes otherwise it's garbage
layout(location = 1)uniform mat4 view;
layout(location = 2)uniform mat4 model;
layout(location = 12)uniform mat3 normalMat;

in vec3 tePos[3];
in vec3 tePatchDistance[3];

out vec3 gFacetNormal;	
out vec3 gPatchDistance;
out vec3 gTriDistance;

void main()
{
	vec3 a = tePos[2] - tePos[0];
	vec3 b = tePos[1] - tePos[0];
	gFacetNormal = normalMat * normalize(cross(a,b));

	gPatchDistance = tePatchDistance[0];
	gTriDistance = vec3(1,0,0);
	gl_Position = gl_in[0].gl_Position;	//wtf is gl_in???
	EmitVertex();	//WHAT IS THIS?????

	gPatchDistance = tePatchDistance[1];
	gTriDistance = vec3(0,1,0);
	gl_Position = gl_in[1].gl_Position;
	EmitVertex();

	gPatchDistance = tePatchDistance[2];
	gTriDistance = vec3(0,0,1);
	gl_Position = gl_in[2].gl_Position;
	EmitVertex();

	EndPrimitive();
}