#include "input.h"

Input* Input::instance = NULL;
Input::Input()
{
	renderer = NULL;
	lastTime = glfwGetTime();
	for (int i = 0; i < GLFW_KEY_LAST; i++)
	{
		keydown[i] = false;
		keyup[i] = false;
		key[i] = false;
	}
	mousePosition = NULL;
}

Input::~Input()
{
}

void Input::Update()
{
	double timeNow = glfwGetTime();
	deltaTime = timeNow - lastTime;
	lastTime = timeNow;

	if (mousePosition == NULL)
	{
		double mouseX, mouseY;
		glfwGetCursorPos(renderer->Window(), &mouseX, &mouseY);
		lastMousePosition.x = mouseX;
		lastMousePosition.y = mouseY;
		lastMousePosition.z = 0;
		mousePosition = lastMousePosition;
	}
	mouseDelta = mouseDelta - lastMousePosition;
	lastMousePosition = mousePosition;

	double mouseX, mouseY;
	glfwGetCursorPos(renderer->Window(), &mouseX, &mouseY);
	mousePosition.x = mouseX;
	mousePosition.y = mouseY;
	mousePosition.z = 0;

	if (renderer == NULL)
	{
		throw "Render is NULL";
		return;
	}

	glfwPollEvents();

	int key = 0;
	while (key <= GLFW_KEY_LAST)
	{
		this->keyup[key] = false;
		this->keydown[key] = false;
		int keyPressed = glfwGetKey(renderer->Window(), key);
		if (keyPressed == GLFW_PRESS)
		{
			this->key[key] = true;
		}
		if (keyPressed == GLFW_RELEASE)
		{
			if (this->key[key])
			{
				this->key[key] = false;
				this->keyup[key] = true;
			}
		}
		key++;
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

Vector3 Input::MouseDelta()
{
	return mouseDelta;
}
