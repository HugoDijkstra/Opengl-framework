#include <renderer.h>
#include <mesh.h>
#include <texture.h>
int main()
{
	Renderer* renderer = new Renderer();
	renderer->CreateShader("Default", "shaders/vertex.vert", "shaders/frag.frag");
	Shader s = renderer->GetShader("Default");
	s.Use();
	s.SetVector3("ColorIn", 1, 1, 1);
	Texture t("assets/uvTest.jpg");
	s.SetInt("textureIn", 0);
	std::vector<Mesh*> mesh = Mesh::LoadMeshes("assets/armadillo.obj");
	for (int i = 0; i < mesh.size(); i++)
	{
		mesh[i]->shader = &s;
	}
	renderer->camera.position = Vector3(0, 0, 0);
	do {
		for (int i = 0; i < mesh.size(); i++)
			renderer->RenderMesh(mesh[i], glm::mat4(1));
		renderer->SwapBuffer();
	} while (glfwGetKey(renderer->Window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->Window()) == 0);
}

