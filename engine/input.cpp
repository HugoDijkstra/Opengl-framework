#include "input.h"

Input::Input()
{
	renderer = NULL;
	lastTime = glfwGetTime();
}

void Input::Update()
{
	double timeNow = glfwGetTime();
	deltaTime = timeNow - lastTime;
	lastTime = timeNow;

if(renderer == NULL)
{
	throw "Render is NULL";
	return;
}
	glfwPollEvents();

	int key = 0;
	while (key <= GLFW_KEY_LAST)
	{
		int keyPressed = glfwGetKey(renderer->Window(),key);
	}
	return;
}

bool Input::GetKey(int keycode)
{
	return key[keycode];
}

bool Input::GetKeyDown(int keycode)
{
	return keydown[keycode];
}

bool Input::GetKeyUp(int keycode)
{
	return keyup[keycode];
}
