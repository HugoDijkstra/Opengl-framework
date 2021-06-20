#pragma once
#ifndef _INPUT
#define _INPUT

#include <renderer.h>

class Input
{
public:
	void Update();
	float DeltaTime() { return deltaTime; };

	static Input *GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Input();
		}
		return instance;
	}

	static Input *GetInstance(Renderer* renderer)
	{
		if (instance == NULL)
		{
			instance = new Input();
			instance->renderer = renderer;
		}
		return instance;
	}

	bool GetKey(int keycode);
	bool GetKeyDown(int keycode);
	bool GetKeyUp(int keycode);
	Vector3 MouseDelta();

	static Input* instance;
private:
	Input();
	virtual ~Input();

	Renderer* renderer;
	float deltaTime;
	double lastTime;

	bool keydown[GLFW_KEY_LAST];
	bool keyup[GLFW_KEY_LAST];
	bool key[GLFW_KEY_LAST];
	
	Vector3 mousePosition;
	Vector3 lastMousePosition;
	Vector3 mouseDelta;
};

#endif // !_INPUT
