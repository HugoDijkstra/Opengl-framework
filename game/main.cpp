#include <renderer.h>
#include <mesh.h>

int main()
{
	Renderer* renderer = new Renderer();
	renderer->CreateShader("Default", "shaders/vertex.vert", "shaders/frag.frag");
	Shader s = renderer->GetShader("Default");
	s.Use();
	s.SetVector3("ColorIn", 0, 1, 0);

	Mesh* mesh = new Mesh(&s);

	renderer->camera.position = Vector3(0, 0, 0);
	do {
		renderer->RenderMesh(mesh, glm::mat4(1));
		renderer->SwapBuffer();
	} while (glfwGetKey(renderer->Window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->Window()) == 0);
}

