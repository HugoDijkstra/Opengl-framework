#include "input.h"

Input::Input()
{
	lastTime = glfwGetTime();
}

void Input::Update()
{
	double timeNow = glfwGetTime();
	deltaTime = timeNow - lastTime;
	lastTime = timeNow;

	glfwPollEvents();
	
	return;
}
