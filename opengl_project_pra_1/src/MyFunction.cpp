#pragma once
#include "MyHeader.h"
#include "stb_image.h"
#include <string>

//// 顶点着色器源码
//extern const GLchar* vertexShaderSource =
//"#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 normal;\n"
//"layout (location = 2) in vec2 texCoords;\n"
////"out vec3 ourColor;\n"
//"out vec2 TexCoords;\n"
//
//"uniform mat4 model;\n"
//"uniform mat4 view;\n"
//"uniform mat4 projection;\n"
//
//"void main()\n"
//"{\n"
////"gl_Position = transform * vec4(position, 1.0f);\n"
//"gl_Position = projection * view * model * vec4(position, 1.0f);\n"
////"ourColor = color;\n"
//"TexCoords = texCoords;\n"
//"}\0";
//
//
//
//// 片段着色器源码
//extern const GLchar* fragmentShaderSource =
//"#version 330 core\n"
////"in vec3 ourColor;\n"
//"in vec2 TexCoord;\n"
//"out vec4 color;\n"
//"uniform sampler2D ourTexture1;\n"
//"uniform sampler2D ourTexture2;\n"
//
//"void main()\n"
//"{\n"
//"color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.6);\n"
////"color = texture(ourTexture1, TexCoord);\n"
//"}\0";
//
//
//extern const GLchar* fragmentObjectSource =
//"#version 330 core\n"
//"out vec4 color;\n"
//"in vec3 Normal;\n"
//"in vec3 FragPos;\n"
//"uniform vec3 objectColor;\n"
//"uniform vec3 lightColor;\n"
//"uniform vec3 lightPos;\n"
//"uniform vec3 viewPos;\n"
//
//"struct Material\n"
//"{\n"
////"vec3 ambient;\n"
////"vec3 diffuse;\n"
//"sampler2D diffuse;\n"
//"vec3 specular;\n"
//"float shininess;\n"
//"};\n"
//"uniform Material material;\n"
//
//"struct Light\n"
//"{\n"
//"vec3 position;\n"
//"vec3 ambient;\n"
//"vec3 diffuse;\n"
//"vec3 specular;\n"
//"};\n"
//"uniform Light light;\n"
//
//"in vec2 TexCoords;\n"
//"void main()\n"
//"{\n"
//// 环境光照
//"vec3 ambient =  light.ambient * vec3(texture(material.diffuse, TexCoords));\n"
//// 漫反射光照
//"vec3 norm = normalize(Normal);\n"
//"vec3 lightDir = normalize(lightPos - FragPos);\n"
//"float diff = max(dot(norm, lightDir), 0.0f);\n"
//"vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, TexCoords));\n"
//// 镜面高光
//"vec3 viewDir = normalize(viewPos - FragPos);\n"
//"vec3 reflectDir = reflect(-lightDir, norm);\n"
//"float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);\n"
//"vec3 specular = (material.specular * spec)* light.specular;\n"
//// 光照结果
//"vec3 result = ambient + diffuse + specular;\n"
//"color = vec4(result, 1.0f);\n"
//
//"}\0";
//
//extern const GLchar* vertexObjectSource = 
//"#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 normal;\n"
//"layout (location = 2) in vec2 texCoords;\n"
//"uniform mat4 model;\n"
//"uniform mat4 view;\n"
//"uniform mat4 projection;\n"
//"out vec3 Normal;\n"
//"out vec3 FragPos;\n"
//"out vec2 TexCoords;\n"
//"void main()\n"
//"{\n"
////"gl_Position = transform * vec4(position, 1.0f);\n"
//"gl_Position = projection * view * model * vec4(position, 1.0f);\n"
//"Normal = normal;\n"
//"FragPos = vec3(model * vec4(position, 1.0f));\n"
//"TexCoords = texCoords;\n"
////"ourColor = color;\n"
//"}\0";
//
//
//extern const GLchar* fragmentLightSource =
//"#version 330 core\n"
//"out vec4 color;\n"
//
//"void main()\n"
//"{\n"
//"color = vec4(1.0f);\n"
//"}\0";
//extern glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1000.0f);

extern glm::vec3 cameraPos = glm::vec3(0.0f, -0.8f, 2.0f);
extern glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
extern glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
extern bool keys[1024]{true};
extern GLfloat deltaTime = 0.0f;
extern GLfloat lastFrame = 0.0f;
extern GLfloat yaw = -90.0f;
extern GLfloat pitch = 0.0f;
extern bool firstMouse = true;
extern GLfloat lastX = 400;
extern GLfloat lastY = 300;
extern GLfloat aspect = 20.0f;
extern glm::vec3 lightPos(1.2f, 0.5f, 3.0f);

// 按键回调函数
void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
		if (key == GLFW_KEY_ESCAPE and action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

		// 动作判定
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
}

// 创建特定类型的shader并编译
GLuint MyCreateShader(const GLenum ShaderType, const GLchar* &ShaderSource)
{
	// create shader
	GLuint shader = glCreateShader(ShaderType);
	// attribute shader with program
	glShaderSource(shader, 1, &ShaderSource, nullptr);
	// compile shader
	glCompileShader(shader);
	return shader;
}

// 创建着色器程序
GLuint MyCreateShaderProgram(const GLchar* &VertexShaderSource, const GLchar* &FragmentShaderSource)
{
	// create a vertex shader
	GLuint VertexShader = MyCreateShader(GL_VERTEX_SHADER, VertexShaderSource);

	// test vertex shader if vaild
	GLint ifsuccess = GL_TRUE;
	GLchar info[512];
	glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &ifsuccess);
	if (not ifsuccess)
	{
		glGetShaderInfoLog(VertexShader, 512, nullptr, info);
		std::cout << "ERROR: vertex shader build or compile failed!" << std::endl;
		std::abort();
	}

	// create a fragment shader
	GLuint FragmentShader = MyCreateShader(GL_FRAGMENT_SHADER, FragmentShaderSource);

	// test fragment shader if vaild
	glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &ifsuccess);
	if (not ifsuccess)
	{
		glGetShaderInfoLog(FragmentShader, 512, nullptr, info);
		std::cout << "ERROR: fragment shader build or compile failed!" << std::endl;
		std::abort();
	}

	// create a shader program
	GLuint shaderProgram = glCreateProgram();
	// attach vertex shader and fragment shader to content
	glAttachShader(shaderProgram, VertexShader);
	glAttachShader(shaderProgram, FragmentShader);
	// link Program with content
	glLinkProgram(shaderProgram);

	// test shader program if vaild
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &ifsuccess);
	if (not ifsuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, nullptr, info);
		std::cout << "ERROR:shader program wrong!" << std::endl;
		std::abort();
	}

	// delete shader
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);

	// return shader program
	return shaderProgram;
}


// 初始化glfw库、glew库，创建窗口和视口
GLFWwindow* MyInitOpenGL(void)
{
	// glfw init
	if (GLFW_TRUE != glfwInit())
	{
		std::cout << "ERROR: init glfw failed!" << std::endl;
		std::abort();
	}

	// set some parameters
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// build a window
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WIDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (nullptr == window)
	{
		std::cout << "ERROR: create a window failed!" << std::endl;
		glfwTerminate();
		std::abort();
	}

	// make content 
	glfwMakeContextCurrent(window);

	// init glew
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		std::cout << "ERROR: init glew failed!" << std::endl;
		std::abort();
	}

	// make viewport
	glViewport(0, 0, WINDOW_WIDTH, WIDOW_HEIGHT);

	return window;
}


//// init VBO,VAO,EBO
//std::tuple<GLuint, GLuint, GLuint> MyInitVertexBuffer(void)
//{
//	// vertex buffer object
//	GLuint VBO;
//	// vertex array object
//	GLuint VAO;
//	// element buffer object
//	GLuint EBO;
//
//	// generate buffer
//	glGenBuffers(1, &VBO);
//	// bind VBO with GL_ARRAY_BUFFER type
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	// sent data to buffer
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// generate VAO
//	glGenVertexArrays(1, &VAO);
//	// bind VAO
//	glBindVertexArray(VAO);
//
//	// explain vertex coordinate
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	// Enable vertex array
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(2);
//	//// explain vertex color
//    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//    //glEnableVertexAttribArray(1);
//	// explain vertex texture
//	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	//glEnableVertexAttribArray(2);
//
//	// unbind VAO
//	glBindVertexArray(GL_FALSE);
//
//	std::tuple<GLuint, GLuint, GLuint> ret(VBO, VAO, EBO);
//	return ret;
//}


// 清空删除VBO,VAO,EBO
void MyDeleteVertexBuffer(GLuint & VBO, GLuint & VAO, GLuint & EBO) noexcept
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}


//// create a texture with stbi_image.h
//const GLuint MyCreateTexture(const std::string ImageSource)
//{
//	GLuint texture;
//	// create a texture
//	glGenTextures(1, &texture);
//	// bind texture with 2D
//	glBindTexture(GL_TEXTURE_2D, texture);
//	// S axis and T axis
//	glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	// 纹理过滤
//	glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// load texture
//	int width, height, channels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* image = stbi_load(ImageSource.c_str(), &width, &height, &channels, 0);
//	if (nullptr == image)
//	{
//		std::cout << "ERROR: return null,stbi_load failed!" << std::endl;
//		std::cout << stbi_failure_reason();
//		std::abort();
//	}
//
//	// generate texture
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//	//free memory
//	stbi_image_free(image);
//	// unbind
//	glBindTexture(GL_TEXTURE, GL_FALSE);
//
//	return texture;
//}

//// 2D to 3D
//std::tuple<glm::mat4, glm::mat4, glm::mat4> MyAxisSystemTransform(const GLuint ShaderProgram)
//{
//	// create a model matrix
//	glm::mat4 model = glm::mat4(1.0f);
//	//model = glm::rotate(model, GLfloat(glfwGetTime() * 1.8), glm::vec3(-0.5f, 1.0f, 0.0f));
//
//	// create a view matrix
//	glm::mat4 view = glm::mat4(1.0f);
//	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f * GLfloat(sin(glfwGetTime()))));
//	view = MyCamera();
//
//	// create a projection matrix
//	glm::mat4 projection = glm::mat4(1.0f);
//	projection = glm::perspective(glm::radians(aspect), 800.0f / 600.0f, 0.1f, 100.0f);
//
//	// get uniform location
//	GLuint modelloc = glGetUniformLocation(ShaderProgram, "model");
//	GLuint viewloc = glGetUniformLocation(ShaderProgram, "view");
//	GLuint projloc = glGetUniformLocation(ShaderProgram, "projection");
//
//	//
//	glUniformMatrix4fv(modelloc, 1, GL_FALSE, glm::value_ptr(model));
//	glUniformMatrix4fv(viewloc, 1, GL_FALSE, glm::value_ptr(view));
//	glUniformMatrix4fv(projloc, 1, GL_FALSE, glm::value_ptr(projection));
//
//	//
//	return std::make_tuple(model, view, projection);
//}

// 创建摄像机坐标系统
const glm::mat4 MyCamera(void)
{
	glm::mat4 view(1.0f);
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	return view;
}

// 完成上下左右键的检测回调
void do_movement(void)
{
	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	GLfloat cameraSpeed = 15.0f * deltaTime;
	if (keys[GLFW_KEY_UP])
		cameraPos += cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_DOWN])
		cameraPos -= cameraSpeed * cameraFront;
	if(keys[GLFW_KEY_LEFT])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keys[GLFW_KEY_RIGHT])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	
}

// 鼠标回调函数
void mouse_callback(GLFWwindow * window, double xpos, double ypos)
{
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}
		GLfloat xoffset = xpos - lastX;
		GLfloat yoffset = lastY - ypos;
		lastX = xpos;
		lastY = ypos;

		GLfloat sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		front.y = sin(glm::radians(pitch));
		front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		cameraFront = glm::normalize(front);

}

// 鼠标滚轮回调函数
void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
		aspect -= yoffset;
	if (aspect < 1.0f)
		aspect = 1.0f;
	if (aspect > 45.0f)
		aspect = 45.0f;
}

// Mesh构造函数
Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	this->setupMesh();
}

// 完成Mesh的VBO,VAO,EBO绑定
void Mesh::setupMesh(void)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

	// 设置顶点坐标
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// 设置法线坐标
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	glEnableVertexAttribArray(1);

	// 设置纹理坐标
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
	glEnableVertexAttribArray(2);

	// vertex tangent
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
	glEnableVertexAttribArray(3);

	// vertex bitangent
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
	glEnableVertexAttribArray(4);
	// ids
	glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));
	glEnableVertexAttribArray(5);

	// weights
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
	glEnableVertexAttribArray(6);
	glBindVertexArray(0);

}

// 网格纹理处理
void Mesh::Draw(const GLuint shaderprogram)
{
	// 绑定合适的纹理
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	unsigned int ambientNr = 1;
	unsigned int displacementNr = 1;
	unsigned int emissiveNr = 1;
	unsigned int lightmapNr = 1;
	unsigned int reflectionNr = 1;
	unsigned int shininessNr = 1;
	unsigned int opacityNr = 1;
	unsigned int noneNr = 1;
	unsigned int unknownNr = 1;
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		// 激活纹理单元
		glActiveTexture(GL_TEXTURE0 + i); 
		std::string number;
		std::string name = textures[i].type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++); 
		else if (name == "texture_normal")
			number = std::to_string(normalNr++); 
		else if (name == "texture_height")
			number = std::to_string(heightNr++); 
		else if (name == "texture_ambient")
			number = std::to_string(ambientNr++);
		else if (name == "texture_displacement")
			number = std::to_string(displacementNr++);
		else if (name == "texture_emissive")
			number = std::to_string(emissiveNr++);
		else if (name == "texture_lightmap")
			number = std::to_string(lightmapNr++);
		else if (name == "texture_reflection")
			number = std::to_string(reflectionNr++);
		else if (name == "texture_shininess")
			number = std::to_string(shininessNr++);
		else if (name == "texture_opacity")
			number = std::to_string(opacityNr++);
		else if (name == "texture_none")
			number = std::to_string(noneNr++);
		else if (name == "texture_unknown")
			number = std::to_string(unknownNr++);

		// 给着色器的uniform赋值
		glUniform1i(glGetUniformLocation(shaderprogram, ("material." + name + number).c_str()), i);
		// 绑定纹理
		glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}

	// draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// always good practice to set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}

// 预处理加载模型
void Model::loadModel(std::string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
		return;
	}
	this->directory = path.substr(0, path.find_last_of('/'));
	this->processNode(scene->mRootNode, scene);
}

// 处理每个节点
void Model::processNode(aiNode* node, const aiScene* scene)
{
	// 添加当前节点中的所有Mesh
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	// 递归处理该节点的子孙节点
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}
}

// 处理网格
Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector(1.0f); 
		// 获取位置坐标
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		// 获取法线坐标
		if (mesh->HasNormals())
		{
			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			vertex.Normal = vector;
		}
		// 获取纹理坐标
		if (mesh->mTextureCoords[0]) 
		{
			glm::vec2 vec(1.0f);
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
			// tangent
			vector.x = mesh->mTangents[i].x;
			vector.y = mesh->mTangents[i].y;
			vector.z = mesh->mTangents[i].z;
			vertex.Tangent = vector;
			// bitangent
			vector.x = mesh->mBitangents[i].x;
			vector.y = mesh->mBitangents[i].y;
			vector.z = mesh->mBitangents[i].z;
			vertex.Bitangent = vector;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		vertices.push_back(vertex);
	}

	// 处理顶点索引
	 // Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		// Retrieve all indices of the face and store them in the indices vector
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	std::cout << mesh->mMaterialIndex << std::endl;

	if (mesh->mMaterialIndex >= 0)
	{
		// 处理材质
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		// We assume a convention for sampler names in the shaders. Each diffuse texture should be named
		// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
		// Same applies to other texture as the following list summarizes:
		// Diffuse: texture_diffuseN
		// Specular: texture_specularN
		// Normal: texture_normalN

		// 1. Diffuse maps  get
		std::vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		// 2. Specular maps
		std::vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		// 3. normal maps   get
		std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		//// 4. height maps
		//std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_height");
		//textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
		//// 5. ambient maps
		//std::vector<Texture> ambientsMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_ambient");
		//textures.insert(textures.end(), ambientsMaps.begin(), ambientsMaps.end());
		//// 6. displacement maps
		//std::vector<Texture> diplacementMaps = loadMaterialTextures(material, aiTextureType_DISPLACEMENT, "texture_displacement");
		//textures.insert(textures.end(), diplacementMaps.begin(), diplacementMaps.end());
		//// 7. emissive maps
		//std::vector<Texture> emissiveMaps = loadMaterialTextures(material, aiTextureType_EMISSIVE, "texture_emissive");
		//textures.insert(textures.end(), emissiveMaps.begin(), emissiveMaps.end());
		// 8. lightmap     get
		std::vector<Texture> lightmapMaps = loadMaterialTextures(material, aiTextureType_LIGHTMAP, "texture_lightmap");
		textures.insert(textures.end(), lightmapMaps.begin(), lightmapMaps.end());
		//// 9.
		//std::vector<Texture> reflectionMaps = loadMaterialTextures(material, aiTextureType_REFLECTION, "texture_reflection");
		//textures.insert(textures.end(), reflectionMaps.begin(), reflectionMaps.end());
		//// 10.
		//std::vector<Texture> shininessMaps = loadMaterialTextures(material, aiTextureType_SHININESS, "texture_shininess");
		//textures.insert(textures.end(), shininessMaps.begin(), shininessMaps.end());
		//// 11.
		//std::vector<Texture> opacityMaps = loadMaterialTextures(material, aiTextureType_OPACITY, "texture_opacity");
		//textures.insert(textures.end(), opacityMaps.begin(), opacityMaps.end());
		//// 12.
		//std::vector<Texture> noneMaps = loadMaterialTextures(material, aiTextureType_NONE, "texture_none");
		//textures.insert(textures.end(), noneMaps.begin(), noneMaps.end());
		//// 13.
		//std::vector<Texture> unknownMaps = loadMaterialTextures(material, aiTextureType_UNKNOWN, "texture_unknown");
		//textures.insert(textures.end(), unknownMaps.begin(), unknownMaps.end());
	}

	return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	std::vector<Texture> textures;
	for (GLuint i = 0; i < mat->GetTextureCount(type); i++)
	{
		
		aiString str;
		mat->GetTexture(type, i, &str);
		GLboolean skip = false;
		for (GLuint j = 0; j < textures_loaded.size(); j++)
		{
			if (textures_loaded[j].path == str)
			{
				textures.push_back(textures_loaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{   // 如果纹理没有被加载过，加载之
			Texture texture;
			texture.id = TextureFromFile(str.C_Str(), this->directory, type);
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			this->textures_loaded.push_back(texture);  // 添加到纹理列表 textures
		}
	}
	return textures;
}

// 加载纹理贴图
GLint TextureFromFile(const char* path, std::string directory, aiTextureType type)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;

	std::cout << filename << std::endl;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		if (type == aiTextureType_DIFFUSE)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

//void button_callback(GLFWwindow* window, int button, int action, int mods)
//{
//	// 在鼠标左键按下时需记录x,y坐标
//	// 在鼠标左键松开时需记录x,y坐标
//	// 计算x偏移量,y偏移量
//	// 改变摄像机位置camerapos
//	IfClick = true;
//	double xpos_press, ypos_press;
//	double xpos_release, ypos_release;
//	if (action == GLFW_PRESS and button == GLFW_MOUSE_BUTTON_LEFT)
//	{
//		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//		std::cout << "左键被按下" << std::endl;
//		glfwGetCursorPos(window, &xpos_press, &ypos_press);
//		std::cout << xpos_press << "  " << ypos_press;
//	}
//	if (action == GLFW_RELEASE and button == GLFW_MOUSE_BUTTON_LEFT)
//	{
//		std::cout << "左键被松开" << std::endl;
//		glfwGetCursorPos(window, &xpos_release, &ypos_release);
//		std::cout << xpos_release << "  " << ypos_release;
//		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
//	}
//	IfClick = false;
//}



