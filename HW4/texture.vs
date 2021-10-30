
#version 330 core
layout (location = 0) in vec3 position;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

uniform mat4 model; //3rd to multiply in gl_Position
uniform mat4 view; //2nd to multiply in gl_Position
uniform mat4 projection; //1st to multiply in gl_Position

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    UV = vertexUV;
}
