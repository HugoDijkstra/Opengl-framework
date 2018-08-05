#ifndef _TEXTURE
#define _TEXTURE

//Standard libraries
#include <string>

//GL libraries
#include <gl/glew.h>
#include <glfw3.h>

//Soil
#include <soil/SOIL.h>

//engine includes
#include <vector3.h>

class Texture {
public:
	Texture(std::string path);
	virtual ~Texture();

	int width, height;

	GLuint TextureID() { return textureID; }
private:
	GLuint textureID;
};

#endif // !_TEXTURE
