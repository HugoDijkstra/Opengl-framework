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

class Shader {
public:
	//Variables
	std::string name;
	GLuint shaderID;
	std::map<std::string, GLuint> properties;

	//Functions
	void Use() {
		std::cout << "Now using: " << name << std::endl;
		glUseProgram(shaderID);
	}

	void SetInt(std::string propertyName, int i)
	{
		GLuint location = GetPropertyID(propertyName);
		if (location == -1)
		{
			return;
		}
		glUniform1i(location, i);

	}

	void SetVector3(std::string propertyName, int x, int y, int z)
	{
		GLuint location = GetPropertyID(propertyName);
		if (location == -1)
		{
			return;
		}
		glUniform3f(location, x, y, z);


	}

	void SetMatrix4(std::string propertyName, const glm::mat4 i)
	{
		GLuint location = GetPropertyID(propertyName);
		if (location == -1)
		{
			return;
		}
		glUniformMatrix4fv(location, 1, GL_FALSE, &i[0][0]);
	}
private:
	GLuint GetPropertyID(std::string propertyName);

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
