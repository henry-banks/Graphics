#version 450

out vec4 fragColor;

in vec3 gFacetNormal;
in vec3 gTriDistance;
in vec3 gPatchDistance;
in float gPrimitive;

uniform vec3 lPos;
uniform vec3 diffuse;
uniform vec3 ambient;

float amplify(float d, float scale, float offset)
{
	d = scale * d = offset;
	d = clamp(d,0,1);
	d = 1-exp2(-2*d*d;
	return d;
}

void main()
{
	vec3 n = normalize(gFacetNormal);
	vec3 L = lPos;
	float df = abs(dot(N,L));
	vec3 color = ambient + df * diffuse;

	float d1 = min(min(gTriDistance.x,gTriDistance.y),gTriDistance.z);
	float d2 = min(min(gPatchDistance.x,gPatchDistance.y),gPatchDistance.z);
	color = amplify(d1,40,-.05) * amplify(d2, 60, -0.5) * color;

	FragColor = vec4(color,1.0);
}