#pragma once
#include "MyHeader.h"
#include "stb_image.h"
#include <string>

// 顶点着色器源码
extern const GLchar* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 color;\n"
"layout (location = 2) in vec2 texCoord;\n"
//"out vec3 ourColor;\n"
"out vec2 TexCoord;\n"

//"uniform mat4 transform;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"

"void main()\n"
"{\n"
//"gl_Position = transform * vec4(position, 1.0f);\n"
"gl_Position = projection * view * model * vec4(position, 1.0f);\n"
//"ourColor = color;\n"
"TexCoord = vec2(texCoord.x, texCoord.y);\n"
"}\0";



// 片段着色器源码
extern const GLchar* fragmentShaderSource =
"#version 330 core\n"
//"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"
"out vec4 color;\n"
"uniform sampler2D ourTexture1;\n"
"uniform sampler2D ourTexture2;\n"

"void main()\n"
"{\n"
"color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.6);\n"
//"color = texture(ourTexture1, TexCoord);\n"
"}\0";


// create a shader a
// return shader number
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

// create a shader program and
// return shader program number
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

// glfw and glew init
// create window and viewport
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

// init VBO,VAO,EBO
std::tuple<GLuint, GLuint, GLuint> MyInitVertexBuffer(void)
{
	// vertex buffer object
	GLuint VBO;
	// vertex array object
	GLuint VAO;
	// element buffer object
	GLuint EBO;

	// generate buffer
	glGenBuffers(1, &VBO);
	// bind VBO with GL_ARRAY_BUFFER type
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// sent data to buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// generate VAO
	glGenVertexArrays(1, &VAO);
	// bind VAO
	glBindVertexArray(VAO);

	// explain vertex coordinate
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	// Enable vertex array
	glEnableVertexAttribArray(0);
	//// explain vertex color
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    //glEnableVertexAttribArray(1);
	// explain vertex texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// unbind VAO
	glBindVertexArray(GL_FALSE);

	std::tuple<GLuint, GLuint, GLuint> ret(VBO, VAO, EBO);
	return ret;
}

// delete VAO,VBO,EBO
void MyDeleteVertexBuffer(GLuint & VBO, GLuint & VAO, GLuint & EBO) noexcept
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}

// create a texture with stbi_image.h
const GLuint MyCreateTexture(const std::string ImageSource)
{
	GLuint texture;
	// create a texture
	glGenTextures(1, &texture);
	// bind texture with 2D
	glBindTexture(GL_TEXTURE_2D, texture);
	// S axis and T axis
	glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// 纹理过滤
	glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load texture
	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image = stbi_load(ImageSource.c_str(), &width, &height, &channels, 0);
	if (nullptr == image)
	{
		std::cout << "ERROR: return null,stbi_load failed!" << std::endl;
		std::cout << stbi_failure_reason();
		std::abort();
	}

	// generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	//free memory
	stbi_image_free(image);
	// unbind
	glBindTexture(GL_TEXTURE, GL_FALSE);

	return texture;
}
