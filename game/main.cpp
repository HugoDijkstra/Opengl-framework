#include <renderer.h>
#include <mesh.h>

int main()
{
	Renderer* renderer = new Renderer();
	Mesh* mesh = new Mesh();
	renderer->CreateShader("Default", "shaders/vertex.vert", "shaders/frag.frag");
	renderer->GetShader("Default").Use();
	do {
		mesh->Draw();
		renderer->SwapBuffer();
	} while (glfwGetKey(renderer->Window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->Window()) == 0);
	delete renderer;
	delete mesh;
}