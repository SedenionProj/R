#version 430 core
out vec4 FragColor;

layout(std140, binding = 0) uniform myvar {
    vec4 col;
};

layout(std140, binding = 0) uniform myvar1 {
    vec4 col1;
};

layout(std430, binding = 5) buffer buf
{
    vec4 col2[];
};


void main()
{
    FragColor = vec4(col2[0]);
} 