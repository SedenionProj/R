#version 430 core
out vec4 FragColor;

layout(std430, binding = 5) buffer buf
{
    vec4 col2[];
};

layout (std140, binding = 1) uniform test
{
    vec4 lol[100];
};


void main()
{
    FragColor = vec4(lol[0].xyz,1);
    col2[0].x = 1;
} 