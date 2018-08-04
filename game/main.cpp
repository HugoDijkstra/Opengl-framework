#include <renderer.h>
#include <mesh.h>

int main()
{
	Renderer* renderer = new Renderer();
	Mesh* mesh = new Mesh();
	renderer->CreateShader("Default", "shaders/vertex.vert", "shaders/frag.frag"); //iew
	Shader s = renderer->GetShader("Default"); //name is Default (iew)
	s.Use(); //name
	s.SetVector3("ColorIn", 0, 1, 0); // nice
	do {
		renderer->RenderMesh(mesh, glm::mat4()); //iew
		renderer->SwapBuffer(); 
	} while (glfwGetKey(renderer->Window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->Window()) == 0);
} 

