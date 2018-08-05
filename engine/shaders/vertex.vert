#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUV;

uniform vec3 ColorIn;
uniform mat4 MVP;

out vec2 UV;
out vec3 pos;
void main()
{
  gl_Position = MVP * vec4(vertexPosition_modelspace,1);
  //gl_Normal = normal;
  UV = vertexUV;
  pos = vertexPosition_modelspace;
}
