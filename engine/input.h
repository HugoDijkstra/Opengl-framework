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
		if (input == NULL)
		{
			input = new Input();
		}
		return input;
	}

	static Input *GetInstance(Renderer* renderer)
	{
		if (input == NULL)
		{
			input = new Input();
			input->renderer = renderer;
		}
		return input;
	}

	bool GetKey(int keycode);
	bool GetKeyDown(int keycode);
	bool GetKeyUp(int keycode);

private:
	Input();
	virtual ~Input();

	static Input *input;
	Renderer* renderer;
	float deltaTime;

	double lastTime;

	bool keydown[GLFW_KEY_LAST];
	bool keyup[GLFW_KEY_LAST];
	bool key[GLFW_KEY_LAST];
};

#endif // !_INPUT
