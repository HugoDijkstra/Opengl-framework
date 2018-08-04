#ifndef _RENDERER
#define _RENDERER

//Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

//include glew first
#include <GL/glew.h>

//include glfw and glm after
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Engine includes
#include <mesh.h>
#include <vector3.h>

struct Shader {
	GLuint shaderID;
	void Use() {
		glUseProgram(shaderID);
	}
};

struct Camera {
	Vector3 position;
	Vector3 eulerRotation;
};

class Renderer
{
public:
	//(Con/De)structor
	Renderer();
	~Renderer();

	void SwapBuffer();
	void RenderMesh(Mesh * mesh, glm::mat4 mvp);
	Shader GetShader(std::string name);
	GLFWwindow* Window() { return window; }
	void CreateShader(std::string shaderName, std::string vertexPath, std::string fragmentPath);
	glm::mat4 ProjectionMatrix() { return projectionMatrix; }
private:
	glm::mat4 projectionMatrix;
	GLuint LoadShaders(const char* vertex_file_path, const char*  fragment_file_path);
	GLFWwindow* window;
	std::map <std::string, Shader> shaders;
};




#endif // !_RENDERER
