#version 450

///////////////Camera
//0 = mat4 proj
//1 = mat4 view
///////////////

///////////////SpecGloss
//2 = mat4 model
//3 = sampler2D diffuse
//4 = sampler2D specular
//5 = sampler2D normal
//6 = float gloss
///////////////

//7 = vec3 ambient
//8 = vec3 lightPos
//9 = float tessLevelInner
//10 = float tessLevelOuter
//11 = vec3 diffuseMaterial?
//12 = mat3 normalMat

layout(location = 0)in vec4 pos;
out vec3 vPos;

void main()
{
    vPos = pos.xyz;
}