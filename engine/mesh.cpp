#include <mesh.h>

Assimp::Importer *Mesh::importer = NULL;

std::vector<std::string> Split(std::string str, char splitAt)
{
	std::vector<std::string> toReturn;
	std::string currentString = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != splitAt)
		{
			currentString = currentString + str[i];
		}
		else
		{
			toReturn.push_back(currentString);
			currentString = "";
		}
	}
	toReturn.push_back(currentString);
	return toReturn;
}
Mesh::Mesh()
{
	vertexArrayID = 0;
	vertexBuffer = 0;
	elementBuffer = 0;
}

Mesh::Mesh(Shader *s)
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
	shader = s;
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	//VAO
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//VBO
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	//EBO
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	//Set vertex atribbs
	//vertex
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
	//normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));
	//uv
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, uv));

	glBindVertexArray(0);

	this->vertices = vertices;
	this->indices = indices;
	shader = NULL;
}

/*Mesh* Mesh::LoadMesh(std::string path)
{
	std::ifstream reader;
	reader.open(path);
	if (reader.is_open()) {
		//variables for mesh
		int v = 0, i = 0, n = 0, t = 0;
		std::string name = "";
		std::vector<Vertex> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;
		std::vector<unsigned int> indices;
		std::string line;
		while (std::getline(reader, line))
		{
			char second = line[1];
			switch (line[0]) {
			case 'v':
			{
				if (second == 't')
				{
					std::vector<std::string> splitString = Split(line, ' ');
					glm::vec2 uv;
					uv.x = std::stof(splitString[1]);
					uv.y = std::stof(splitString[2]);
					if (t < v) {
						vertices[t].uv = uv;
					}
					uvs.push_back(uv);
					t++;
				}
				else if (second == 'n')
				{
					std::vector<std::string> splitString = Split(line, ' ');
					glm::vec3  normal;
					normal.x = std::stof(splitString[1]);
					normal.y = std::stof(splitString[2]);
					normal.z = std::stof(splitString[3]);
					normals.push_back(normal);
					n++;
				}
				else if (second == ' ')
				{
					Vertex vert;
					vert.normalAmount = 0;
					std::vector<std::string> splitString = Split(line, ' ');
					vert.position.x = std::stof(splitString[1]);
					vert.position.y = std::stof(splitString[2]);
					vert.position.z = std::stof(splitString[3]);
					vertices.push_back(vert);
					v++;
				}
				break;
			}
			case 'f': {
				std::vector<std::string> splitString = Split(line, ' ');

				for (int i = 1; i < splitString.size(); i++) {
					std::vector<std::string> splitParts = Split(splitString[i], '/');
					int vertextmp = std::stoi(splitParts[0]) - 1;
					indices.push_back(vertextmp);
					//vertices[vertextmp].uv = uvs[std::stoi(splitParts[1]) - 1];
					//vertices[vertextmp].normal += normals[std::stoi(splitParts[1]) - 1];
					//vertices[vertextmp].normalAmount++;
				}
				break;
			}
			case 'o':
				name = line.substr(2, line.length() - 2);
				break;
			}
		}

		for (int i = 0; i < vertices.size(); i++)
		{
			vertices[i].normal /= vertices[i].normalAmount;
		}

		std::cout << "Name: " << name << "\nVertices: " << vertices.size() << "\nUvs: " << uvs.size() << "\nNormals: " << normals.size() << "\nIndices: " << indices.size() << std::endl;
		Mesh* newMesh = new Mesh(vertices, indices);
		newMesh->name = name;
		return newMesh;
	}
	else
	{
		std::cout << "Could not open obj file: " << path << std::endl;
	}
	return NULL;
}*/

Mesh::~Mesh()
{
}

void Mesh::Draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void Mesh::SetVertices(std::vector<GLfloat> vertices)
{
}

Mesh *Mesh::LoadMesh(std::string path)
{
	if (importer == NULL)
		importer = new Assimp::Importer();
	const aiScene *scene = importer->ReadFile(path, aiProcess_CalcTangentSpace |
														aiProcess_Triangulate |
														aiProcess_JoinIdenticalVertices |
														aiProcess_SortByPType);

	if (!scene)
	{
		std::cout << "Failed to load: " << path << importer->GetErrorString() << std::endl;
		return NULL;
	}
	std::vector<Vertex> vertices;
	for (int i = 0; i < scene->mMeshes[0]->mNumVertices; i++)
	{
		aiVector3D vector = scene->mMeshes[0]->mVertices[i];
		Vertex v;
		v.position = glm::vec3(vector.x, vector.y, vector.z);
		if (scene->mMeshes[0]->mTextureCoords[0])
		{
			aiVector3D uv = scene->mMeshes[0]->mTextureCoords[0][i];
			v.uv = glm::vec2(uv.x, uv.y);
		}
		vertices.push_back(v);
	}
	scene->mMeshes[0]->mVertices;

	std::vector<unsigned int> indices;
	for (int i = 0; i < scene->mMeshes[0]->mNumFaces; i++)
	{
		aiFace face = scene->mMeshes[0]->mFaces[i];
		for (int f = 0; f < face.mNumIndices; f++)
		{
			indices.push_back((unsigned int)face.mIndices[f]);
		}
	}

	Mesh *mesh = new Mesh(vertices, indices);
	;
	delete scene;
	return mesh;
}

std::vector<Mesh *> Mesh::LoadMeshes(std::string path)
{
	if (importer == NULL)
		importer = new Assimp::Importer();
	const aiScene *scene = importer->ReadFile(path, aiProcess_CalcTangentSpace |
														aiProcess_Triangulate |
														aiProcess_JoinIdenticalVertices |
														aiProcess_SortByPType);
	std::vector<Mesh *> meshes;
	if (!scene)
	{
		std::cout << "Failed to load: " << path << importer->GetErrorString() << std::endl;
		return meshes;
	}

	aiNode *node = scene->mRootNode;
	ProccesNode(scene, node, &meshes);
	delete scene;
	return meshes;
}

void Mesh::ProccesNode(const aiScene *scene, aiNode *node, std::vector<Mesh *> *meshes)
{
	for (int m = 0; m < node->mNumMeshes; m++)
	{
		std::vector<Vertex> vertices;
		for (int i = 0; i < scene->mMeshes[node->mMeshes[m]]->mNumVertices; i++)
		{
			Vertex v;
			aiVector3D vector = scene->mMeshes[node->mMeshes[m]]->mVertices[i];
			v.position = glm::vec3(vector.x, vector.y, vector.z);
			if (scene->mMeshes[node->mMeshes[m]]->mTextureCoords[0] != NULL)
			{
				aiVector3D uv = scene->mMeshes[node->mMeshes[m]]->mTextureCoords[0][i];
				v.uv = glm::vec2(uv.x, uv.y);
			}
			vertices.push_back(v);
		}

		std::vector<unsigned int> indices;
		for (int i = 0; i < scene->mMeshes[node->mMeshes[m]]->mNumFaces; i++)
		{
			aiFace face = scene->mMeshes[node->mMeshes[m]]->mFaces[i];
			for (int f = 0; f < face.mNumIndices; f++)
			{
				indices.push_back((unsigned int)face.mIndices[f]);
			}
		}

		Mesh *mesh = new Mesh(vertices, indices);
		meshes->push_back(mesh);
	}

	for (int i = 0; i < node->mNumChildren; i++)
	{
		ProccesNode(scene, node->mChildren[i], meshes);
	}
}