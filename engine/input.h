#ifndef _INPUT
#define _INPUT

#include <glfw3.h>
class Input {
public:

	void Update();
	float DeltaTime() { return deltaTime; };

	static Input* GetInstance()
	{
		if(input == NULL)
		{
			input = new Input();
		}
		return input;
	}
private:
	Input();
	virtual ~Input();

	

	static Input* input;
	float deltaTime;

	double lastTime;
};

#endif // !_INPUT
