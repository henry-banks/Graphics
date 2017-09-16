#version 450

out vec4 fragColor;

in vec3 gFacetNormal;
in vec3 gTriDistance;
in vec3 gPatchDistance;
in float gPrimitive;

//layout(location = 3)uniform sampler2D diffuse;
//layout(location = 4)uniform sampler2D specular
//layout(location = 5)uniform sampler2D normal;

layout(location = 11)uniform vec3 diffuseMat;
layout(location = 7)uniform vec3 ambient;
layout(location = 8)uniform vec3 lightPos;

float amplify(float d, float scale, float offset)
{
	d = scale * d + offset;
	d = clamp(d,0,1);
	d = 1-exp2(-2*d*d);
	return d;
}

void main()
{
	vec3 N = normalize(gFacetNormal);
	vec3 L = lightPos;
	float df = abs(dot(N,L));
	vec3 color = ambient + df * diffuseMat;

	float d1 = min(min(gTriDistance.x,gTriDistance.y),gTriDistance.z);
	float d2 = min(min(gPatchDistance.x,gPatchDistance.y),gPatchDistance.z);
	color = amplify(d1,40,-.05) * amplify(d2, 60, -0.5) * color;

	fragColor = vec4(color,1.0);
}