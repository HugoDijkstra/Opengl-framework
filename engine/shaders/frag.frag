#version 330 core

out vec3 color;

in vec2 UV;

uniform vec3 ColorIn;
uniform sampler2D textureIn;

void main() {
 color = ColorIn
}
