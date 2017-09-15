#version 450

layout(location = 0) vec3 pos;
out vec3 vPos;

void main()
{
    vPos = pos.xyz;
}