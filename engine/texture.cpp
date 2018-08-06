#include "texture.h"

Texture::Texture(std::string path)
{


	width = 0;
	height = 0;
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	unsigned char* data = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	if (data != NULL && data[0] != 0) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(data);
	}
	else {
		std::cout << "could not open: " << path << std::endl;
	}
}

Texture::~Texture()
{
	glDeleteTextures(0, &textureID);
}
