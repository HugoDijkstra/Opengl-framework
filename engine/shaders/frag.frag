#version 330 core

out vec3 color;

in vec2 UV;
in vec3 pos;
uniform vec3 ColorIn;
uniform sampler2D textureIn;

void main() {
 color = texture(textureIn, UV).rgb;
}
