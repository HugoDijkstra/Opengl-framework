#include <renderer.h>

Shader::Shader()
{
	name = "";
	shaderID = 0;
	properties.clear();
}

GLuint Shader::GetPropertyID(std::string propertyName) {
	if (properties.size() > 0) {
		std::map<std::string, GLuint>::iterator it = properties.find(propertyName);
		GLuint location;
		if (it == properties.end())
		{
			GLuint locationID = glGetUniformLocation(shaderID, propertyName.c_str());

			if (locationID == -1) {
				std::cout << "Could not find property: " << propertyName << " in shader " << name << std::endl;
				return -1;
			}
			else
			{
				properties[propertyName] = locationID;

				location = locationID;
			}
			return location;

			return (*it).second;
		}
	}
	else
	{
		GLuint locationID = glGetUniformLocation(shaderID, propertyName.c_str());

		if (locationID == -1) {
			std::cout << "Could not find property: " << propertyName << " in shader " << name << std::endl;
			return -1;
		}
		else
		{
			properties[propertyName] = locationID;
		}
		return locationID;
	}
	return -1;
}
Renderer::Renderer()
{
	if (!glfwInit())
	{
		std::cout << "unable to start glew" << std::endl;
		exit(-1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1920, 1080, "Hello world", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Could not create window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Could not start glad" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glEnable(GL_DEPTH_TEST);
	projectionMatrix = glm::perspective(glm::radians(30.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	camera.position = Vector3(0, 0, 0);
	camera.eulerRotation = Vector3(0, 0, 0);
	camera.Update();
	glEnable(GL_CULL_FACE);
	
}

Renderer::~Renderer()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Renderer::SwapBuffer()
{
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
	camera.Update();
}

void Renderer::RenderMesh(Mesh* mesh, glm::mat4 mvp)
{
	//Setup
	glm::mat4 _mvp = projectionMatrix * camera.cameraMatrix * glm::mat4(1);

	Shader s = *mesh->shader;
	s.Use();
	s.SetMatrix4("MVP", _mvp);

	//Render
	glBindVertexArray(mesh->VertexArrayID());
	glDrawElements(GL_TRIANGLES, mesh->Indices().size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

Shader Renderer::GetShader(std::string name)
{
	std::map<std::string, Shader>::iterator found = shaders.find(name);
	if (found != shaders.end())
	{
		return (*found).second;
	}
	else
	{
		std::cout << "Could not find shader: " << name << ". Falling back on default shader";
		return (*shaders.begin()).second;
	}
}

void Renderer::CreateShader(std::string shaderName, std::string vertexPath, std::string fragmentPath)
{
	Shader s;
	s.shaderID = LoadShaders(vertexPath.c_str(), fragmentPath.c_str());
	s.name = shaderName;
	if (s.shaderID == 0)
	{
		std::cout << "Shader: " << s.name << "Could not be created" << std::endl;
		return;
	}
	std::cout << "Shader created: " << s.shaderID << " : " << s.name << std::endl;

	shaders.emplace(shaderName, s);
}

GLuint Renderer::LoadShaders(const char * vertex_file_path, const char * fragment_file_path) {

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
