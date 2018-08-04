#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform vec3 ColorIn;

void main()
{
  gl_Position.xyz = vertexPosition_modelspace;
  gl_Position.w = 1;
}
