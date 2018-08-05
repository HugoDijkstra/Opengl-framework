#ifndef _RENDERER
#define _RENDERER

#define GLM_ENABLE_EXPERIMENTAL

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
#include <glm/gtx/euler_angles.hpp>

//Engine includes
#include <mesh.h>
#include <vector3.h>

class Shader {
public:
	Shader();
	//Variables
	std::string name;
	GLuint shaderID;
	std::map<std::string, GLuint> properties;

	//Functions
	void Use() {
		//std::cout << "Now using: " << name << std::endl;
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

class Camera {
public:
	Vector3 position;
	Vector3 eulerRotation;
	Vector3 direction;
	glm::mat4 cameraMatrix;

	void Update()
	{
		cameraMatrix = glm::lookAt(
			glm::vec3(sin(glfwGetTime()), 1 + tan(glfwGetTime()), 3), // Camera is at (4,3,3), in World Space
			glm::vec3(0, 0, 0), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);
	}

private:
};

class Renderer
{
public:
	//(Con/De)structor
	Renderer();
	~Renderer();

	void SwapBuffer();
	void RenderMesh(Mesh * mesh, glm::mat4 mvp);
	Camera camera;
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
