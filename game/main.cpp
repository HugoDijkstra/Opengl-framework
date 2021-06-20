#include <renderer.h>
#include <mesh.h>
#include <texture.h>
#include <input.h>

int main()
{
	Renderer *renderer = new Renderer();
	renderer->CreateShader("Default", "shaders/vertex.vert", "shaders/frag.frag");
	Shader s = renderer->GetShader("Default");
	s.Use();
	s.SetVector3("ColorIn", 1, 1, 1);
	Texture t("assets/uvTest.jpg");
	s.SetInt("textureIn", 0);
	std::vector<Mesh *> mesh = Mesh::LoadMeshes("assets/cube.obj");
	for (int i = 0; i < mesh.size(); i++)
	{
		mesh[i]->shader = &s;
	}
	renderer->camera.position = Vector3(0, 0, 0);
	Input* input = Input::GetInstance(renderer);
	do
	{
		input->Update();
		if (input->GetKey(GLFW_KEY_W))
		{
			renderer->camera.position += Vector3(0, 0, 1 * input->DeltaTime());
		}
		if (input->GetKey(GLFW_KEY_S))
		{
			renderer->camera.position += Vector3(0, 0, -1 * input->DeltaTime());
		}
		if (input->GetKey(GLFW_KEY_A))
		{
			renderer->camera.position += Vector3(1 * input->DeltaTime(),0,0);
		}
		if (input->GetKey(GLFW_KEY_D))
		{
			renderer->camera.position += Vector3(-1 * input->DeltaTime(), 0, 0);
		}

		renderer->camera.eulerRotation += input->MouseDelta();
		std::cout << input->MouseDelta().x << " " << input->MouseDelta().y << std::endl;
		std::cout << renderer->camera.position.x << std::endl;
		for (int i = 0; i < mesh.size(); i++)
			renderer->RenderMesh(mesh[i], glm::mat4(1));
		renderer->SwapBuffer();
	} while (glfwGetKey(renderer->Window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->Window()) == 0);
}
