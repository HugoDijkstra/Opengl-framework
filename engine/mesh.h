#ifndef _MESH
#define _MESH

//Standard libraries
#include <iostream>
#include <vector>

//Opengl libraries
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

static const GLfloat triangle[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
};

class Mesh
{
public:
	Mesh();
	~Mesh();
	void Draw();
	void SetVertices(std::vector<GLfloat> vertices);
	GLuint VertexBuffer() {
		return vertexBuffer;
	}
private:
	GLuint vertexArrayID;
	GLuint vertexBuffer;
	std::vector<GLfloat> vertices;

};



#endif