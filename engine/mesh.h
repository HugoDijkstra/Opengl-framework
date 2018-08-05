#ifndef _MESH
#define _MESH

//Standard libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

//Opengl libraries
#include <glad.h>
#include <glfw3.h>
#include <glm/glm.hpp>

//Engine includes
#include <vector3.h>
#include <utils.hpp>

static const GLfloat triangle[] = {
	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end
	1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f, // triangle 2 : end
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
};

class Shader;
class Texture;

struct Vertex {
	Vector3 postion;
	Vector3 normal;
	glm::vec2 uv;
	int normalAmount;
};

class Mesh
{
public:
	Mesh();
	Mesh(Shader* s);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	~Mesh();
	std::string name;
	void Draw();
	void SetVertices(std::vector<GLfloat> vertices);
	GLuint VertexBuffer() {
		return vertexBuffer;
	}
	GLuint VertexArrayID() { return vertexArrayID; };

	Shader* shader;

	static Mesh* LoadMesh(std::string);

	std::vector<Vertex> Vertices() { return vertices; }
	std::vector<unsigned int> Indices() { return indices; }
private:
	GLuint vertexArrayID;
	GLuint vertexBuffer;
	GLuint elementBuffer;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	Texture* t;
};



#endif