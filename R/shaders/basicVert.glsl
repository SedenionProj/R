#version 330 core
layout (location = 0) in vec3 aPos;

layout (std140, binding = 1) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

uniform mat4 model;

void main()
{
    gl_Position = projection * view * vec4(aPos, 1.0);
} 