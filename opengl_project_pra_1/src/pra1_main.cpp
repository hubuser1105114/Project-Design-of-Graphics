
#include "MyHeader.h"
//#include "stb_image.h"
//extern const GLchar* fragmentShaderSource;
//extern const GLchar* vertexShaderSource;

//// the code when learning opengl
//void LearnOpenGL(void)
//{
//	// init opengl and return a window
//	GLFWwindow* window = MyInitOpenGL();
//
//	// 隐藏光标
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetCursorPosCallback(window, mouse_callback);
//
//	// 函数回调 
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// init VBO, VAO, EBO
//	auto temp = MyInitVertexBuffer();
//	GLuint VBO = std::get<0>(temp),
//		   VAO = std::get<1>(temp),
//		   EBO = std::get<2>(temp);
//
//	// create texture1,2
//	GLuint texture1 = MyCreateTexture("D:/zhuo_mian/学习/opengl_pra/opengl_p1/opengl_project_pra_1/opengl_project_pra_1/muban1.jpg");
//	//GLuint texture2 = MyCreateTexture("tupian1.jpg");
//
//	// create a shader program with vertex shader and fragment shader
//	GLuint shaderProgram = MyCreateShaderProgram(vertexObjectSource, fragmentObjectSource);
//	GLuint LampshaderProgram = MyCreateShaderProgram(vertexObjectSource, fragmentLightSource);
//
//	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//	GLuint lightVAO;
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	// Set the vertex attributes (only position data for the lamp))
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	glUseProgram(shaderProgram);
//	glUniform1i(glGetUniformLocation(shaderProgram, "material.diffuse"), 0);
//
//
//	// 开启深度测试
//	glEnable(GL_DEPTH_TEST);
//
//	/* 循环保持窗口 */
//	while (not glfwWindowShouldClose(window))
//	{
//		// 检查事件
//		glfwPollEvents();
//		do_movement();
//		// 清空缓冲
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glClear(GL_DEPTH_BUFFER_BIT);
//
//		// 使用纹理单元绑定纹理
//		//glActiveTexture(GL_TEXTURE1);
//		//glBindTexture(GL_TEXTURE_2D, texture2);
//		//glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);
//
//		//激活着色器
//		glUseProgram(shaderProgram);
//
//		//GLint objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
//		//GLint lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
//		GLint lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
//		GLint viewPosLoc = glGetUniformLocation(shaderProgram, "viewPos");
//		//glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
//		//glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
//		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
//		glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);
//		// 矩阵变换
//		//MyTransform();
//
//		//GLint matAmbientLoc = glGetUniformLocation(shaderProgram, "material.ambient");
//		//GLint matDiffuseLoc = glGetUniformLocation(shaderProgram, "material.diffuse");
//		//GLint matSpecularLoc = glGetUniformLocation(shaderProgram, "material.specular");
//		//GLint matShineLoc = glGetUniformLocation(shaderProgram, "material.shininess");
//
//		//glUniform3f(matAmbientLoc, 1.0f, 0.5f, 0.31f);
//		//glUniform3f(matDiffuseLoc, 1.0f, 0.5f, 0.31f);
//		//glUniform3f(matSpecularLoc, 0.5f, 0.5f, 0.5f);
//		//glUniform1f(matShineLoc, 32.0f);
//
//
//
//
//		//GLint lightAmbientLoc = glGetUniformLocation(shaderProgram, "light.ambient");
//		//GLint lightDiffuseLoc = glGetUniformLocation(shaderProgram, "light.diffuse");
//		//GLint lightSpecularLoc = glGetUniformLocation(shaderProgram, "light.specular");
//
//		//glUniform3f(lightAmbientLoc, 0.2f, 0.2f, 0.2f);
//		//glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f);// 让我们把这个光调暗一点，这样会看起来更自然
//		//glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);
//		glUniform3f(glGetUniformLocation(shaderProgram, "material.specular"), 0.5f, 0.5f, 0.5f);
//		glUniform1f(glGetUniformLocation(shaderProgram, "material.shininess"), 64.0f);
//		glUniform3f(glGetUniformLocation(shaderProgram, "light.ambient"), 0.2f, 0.2f, 0.2f);
//		glUniform3f(glGetUniformLocation(shaderProgram, "light.diffuse"), 0.5f, 0.5f, 0.5f);
//		glUniform3f(glGetUniformLocation(shaderProgram, "light.specular"), 1.0f, 1.0f, 1.0f);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//
//		glBindVertexArray(VAO);
//		// 3D matrix transform
//		auto Mat = MyAxisSystemTransform(shaderProgram);
//		glm::mat4
//			view = std::get<1>(Mat),
//			projection = std::get<2>(Mat);
//
//		//绘制物体
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//	    glBindVertexArray(GL_FALSE);
//
//
//		// lamp
//		glUseProgram(LampshaderProgram);
//		//lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
//		//lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
//
//		GLuint modelLoc = glGetUniformLocation(LampshaderProgram, "model");
//		GLuint viewLoc = glGetUniformLocation(LampshaderProgram, "view");
//		GLuint projLoc = glGetUniformLocation(LampshaderProgram, "projection");
//		// Set matrices
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		// Draw the light object (using light's vertex attributes)
//		glBindVertexArray(lightVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//		// 交换缓冲
//		glfwSwapBuffers(window);
//	}
//
//	// delete buffer and vertex array
//	MyDeleteVertexBuffer(VBO, VAO, EBO);
//
//	/* 终止窗口，回收资源 */
//	glfwTerminate();
//}
//
//// practice 
//void PraOpenGL(void)
//{
//	GLFWwindow* window = MyInitOpenGL();
//	std::vector<float> vertex;
//	for (int i = 0; i < 25; i++)
//	{
//		float x = -0.5 + i * 1.0 / 25.0;
//		vertex.push_back(x);
//		vertex.push_back(pow(0.25 - x * x, 0.5));
//		vertex.push_back(0.0f);
//	}
//	for (int i = 0; i < 25; i++)
//	{
//		float x = 0.5 - i * 1.0 / 25.0;
//		vertex.push_back(x);
//		vertex.push_back(-pow(0.25 - x * x, 0.5));
//		vertex.push_back(0.0f);
//	}
//	float vertexs[150];
//	for (int i = 0; i < 150; i++)
//	{
//		vertexs[i] = vertex[i];
//	}
//	GLuint VAO, VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW);
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	const GLchar* CircleVertexShader =
//		"#version 330 core\n"
//		"layout (location = 0) in vec3 position;\n"
//		"void main()\n"
//		"{\n"
//		"gl_Position = vec4(position, 1.0f);\n"
//		"}\0";
//	const GLchar* CircleFragmentShader =
//		"#version 330 core\n"
//		"out vec4 color;\n"
//		"void main()\n"
//		"{\n"
//		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//		"}\0";
//	glfwSetKeyCallback(window, key_callback);
//	GLuint shaderprogram = MyCreateShaderProgram(CircleVertexShader, CircleFragmentShader);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glUseProgram(shaderprogram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_LINE_LOOP, 0, 50);
//		glBindVertexArray(GL_FALSE);
//		// 交换缓冲
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//}
//
//// draw model
//void Draw3DModel(void)
//{
//	// 模型顶点着色器
//	const GLchar* ModelVertexShader =
//		"#version 330 core\n"
//		"layout (location = 0) in vec3 position;\n"
//		"layout (location = 1) in vec3 normal;\n"
//		"layout (location = 2) in vec2 texCoords;\n"
//		"out vec2 TexCoords;\n"
//		"uniform mat4 model;\n"
//		"uniform mat4 view;\n"
//		"uniform mat4 projection;\n"
//		"void main()\n"
//		"{\n"
//		"gl_Position = projection * view * model * vec4(1 - position.x,1 - position.y,1 - position.z, 1.0f);\n"
//		"TexCoords = texCoords;\n"
//		"}\0";
//	
//	// 模型片段着色器
//	const GLchar* ModelFragShader =
//		"#version 330 core\n"
//		"in vec2 TexCoords;\n"
//		"out vec4 color;\n"
//		"uniform sampler2D texture_diffuse1;\n"
//		"void main()\n"
//		"{\n"
//		" color = vec4(texture(texture_diffuse1, TexCoords));\n"
//		"}\0";
//
//	// 初始化opengl
//	GLFWwindow* window = MyInitOpenGL();
//
//	// 键盘、鼠标、滚轮回调
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// 隐藏光标
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// 深度测试
//	glEnable(GL_DEPTH_TEST);
//
//	// 创建着色器程序
//	GLuint ShaderProgram = MyCreateShaderProgram(ModelVertexShader, ModelFragShader);
//
//	// 创建Model实体
//	Model ourModel("D:/zhuo_mian/学习/opengl_pra/opengl_p1/opengl_project_pra_1/model5/scene.gltf");
//
//	// 渲染循环
//	while (not glfwWindowShouldClose(window))
//	{
//		// Set frame time
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// 检查事件
//		glfwPollEvents();
//		do_movement();
//
//		// 清空缓冲
//		glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// 启动着色器程序
//		glUseProgram(ShaderProgram);
//
//		// 3D转换
//		// Transformation matrices
//		glm::mat4 projection = glm::perspective(glm::radians(aspect), 800.0f / 600.0f, 0.1f, 100.0f);
//		glm::mat4 view = MyCamera();
//		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
//
//		// Draw the loaded model
//		glm::mat4 model(1.0f);
//		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
//		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
//		//model = glm::rotate(model, (GLfloat)glfwGetTime() * 1.5f, glm::vec3(0.0f, 1.0f, 0.0f));
//		//model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
//
//		// 启动model构建
//		ourModel.Draw(ShaderProgram);
//
//		// 交换缓冲
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//}

//const GLchar* ModelFragShader_Blinn_mdfy_tbn =
//"#version 330 core\n"
//"out vec4 color;\n"
//"in vec3 Normal;\n"
//"in vec2 TexCoords;\n"
//"in vec3 fragPosition;\n"
//"in vec3 TangentLightPos;\n"
//"in vec3 TangentViewPos;\n"
//"in vec3 TangentFragPos;\n"
//"uniform vec3 lightPos;\n"
//"uniform vec3 viewPos;\n"
//"uniform sampler2D normalMap;\n"
//
//"struct Material\n"
//"{\n"
//"sampler2D texture_diffuse1;\n"
//"sampler2D texture_lightmap1;\n"
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
//"float constant;\n"
//"float linear;\n"
//"float quadratic;\n"
//"};\n"
//"uniform Light light;\n"
//
//"void main()\n"
//"{\n"
//"vec3 norm = texture(normalMap, TexCoords).rgb;\n"
//"norm = normalize(norm * 2.0 - 1.0);\n"
//// 计算衰减
//"float distance = length(light.position - fragPosition);\n"
//"float attenuation = 1.0f / (light.constant + light.linear*distance + light.quadratic*(distance*distance));\n"
//// 环境光照
//"vec3 ambient =  light.ambient * vec3(texture(material.texture_diffuse1, TexCoords)) * vec3(texture(material.texture_lightmap1, TexCoords));\n"
//// 漫反射光照
////"vec3 norm = normalize(Normal);\n"
//"vec3 lightDir = normalize(TangentLightPos - TangentFragPos);\n"
//"float diff = max(dot(norm, lightDir), 0.0f);\n"
//"vec3 diffuse = diff * light.diffuse * vec3(texture(material.texture_diffuse1, TexCoords));\n"
//// 镜面高光
//"vec3 viewDir = normalize(TangentViewPos - TangentFragPos);\n"
//"vec3 halfwayDir = normalize(lightDir + viewDir);\n"   // 半程向量
//"float spec = pow(max(dot(norm, halfwayDir), 0.0f), material.shininess);\n"
//"vec3 specular = (material.specular * spec)* light.specular;\n"
//"ambient *= attenuation;\n"
//"diffuse *= attenuation;\n"
//"specular *= attenuation;\n"
//// 光照结果
//"vec3 result = ambient + diffuse + specular;\n"
//"float gamma = 2.2;\n"
//"result = pow(result, vec3(1.0f/gamma));\n"
//"color = vec4(result, 1.0f);\n"
//"}\0";


void Draw3DModelwithLight(void)
{
	//// 模型顶点着色器
	//const GLchar* ModelVertexShader2 =
	//	"#version 330 core\n"
	//	"layout (location = 0) in vec3 position;\n"
	//	"layout (location = 1) in vec3 normal;\n"
	//	"layout (location = 2) in vec2 texCoords;\n"
	//	"out vec2 TexCoords;\n"
	//	"uniform mat4 model;\n"
	//	"uniform mat4 view;\n"
	//	"uniform mat4 projection;\n"
	//	"void main()\n"
	//	"{\n"
	//	"gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0f);\n"
	//	"TexCoords = texCoords;\n"
	//	"}\0";

	
	
	// 模型顶点着色器
	const GLchar* ModelVertexShader =
		"#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec3 normal;\n"
		"layout (location = 2) in vec2 texCoords;\n"
		"layout (location = 3) in vec3 tangent;\n"
		"layout (location = 4) in vec3 bitangent;\n"

		"out vec2 TexCoords;\n"
		"out vec3 fragPosition;\n"
		"out vec3 Normal;\n"
		"out vec3 TangentLightPos;\n"
		"out vec3 TangentViewPos;\n"
		"out vec3 TangentFragPos;\n"

		"uniform vec3 lightPosition;\n"
		"uniform vec3 viewPosition;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"fragPosition = vec3(model * vec4(position, 1.0f));\n"
		"mat3 normalMatrix = transpose(inverse(mat3(model)));\n"
		"vec3 T = normalize(normalMatrix * tangent);\n"
		"vec3 N = normalize(normalMatrix * normal);\n"
		"T = normalize(T - dot(T, N) * N);"
		"vec3 B = cross(N, T);"
		"mat3 TBN = transpose(mat3(T, B, N));\n"
		"TangentLightPos = TBN * lightPosition;\n"
		"TangentViewPos  = TBN * viewPosition;\n"
		"TangentFragPos  = TBN * fragPosition;\n"

		"gl_Position = projection * view * model * vec4(position, 1.0f);\n"
		"TexCoords = texCoords;\n"
		"Normal = mat3(transpose(inverse(model))) * normal;\n"
		"}\0";

	//// 模型片段着色器  无衰减、非Blinn、无Gamma矫正
	//const GLchar* ModelFragShader =
	//	"#version 330 core\n"
	//	"out vec4 color;\n"
	//	"in vec3 Normal;\n"
	//	"in vec2 TexCoords;\n"
	//	"in vec3 fragPosition;\n"
	//	"uniform vec3 lightPos;\n"
	//	"uniform vec3 viewPos;\n"

	//	"struct Material\n"
	//	"{\n"
	//	"sampler2D diffuse;\n"
	//	"vec3 specular;\n"
	//	"float shininess;\n"
	//	"};\n"
	//	"uniform Material material;\n"

	//	"struct Light\n"
	//	"{\n"
	//	"vec3 position;\n"
	//	"vec3 ambient;\n"
	//	"vec3 diffuse;\n"
	//	"vec3 specular;\n"
	//	"float constant;\n"
	//	"float linear;\n"
	//	"float quadratic;\n"
	//	"};\n"
	//	"uniform Light light;\n"

	//	"void main()\n"
	//	"{\n"
	//	//"float distance = length(light.position - fragPosition);\n"
	//	//"float attenuation = 1.0f / (light.constant + light.linear*distance + light.quadratic*(distance*distance));\n"
	//	// 环境光照
	//	"vec3 ambient =  light.ambient * vec3(texture(material.diffuse, TexCoords));\n"
	//	// 漫反射光照
	//	//"float gamma = 2.2;\n"
	//	"vec3 norm = normalize(Normal);\n"
	//	"vec3 lightDir = normalize(lightPos - fragPosition);\n"
	//	"float diff = max(dot(norm, lightDir), 0.0f);\n"
	//	"vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, TexCoords));\n"
	//	//"vec3 diffuseColor = pow(texture(diffuse, TexCoords).rgb, vec3(gamma));\n"
	//	// 镜面高光
	//	"vec3 viewDir = normalize(viewPos - fragPosition);\n"
	//	"vec3 reflectDir = reflect(-lightDir, norm);\n"
	//	"float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);\n"
	//	"vec3 specular = (material.specular * spec)* light.specular;\n"
	//	//"ambient *= attenuation;\n"
	//	//"diffuse *= attenuation;\n"
	//	//"specular *= attenuation;\n"
	//	// 光照结果
	//	"vec3 result = ambient + diffuse + specular;\n"
	//	//"color = vec4(pow(result, vec3(1.0/gamma)), 1.0f);\n"
	//	"color = vec4(result, 1.0f);\n"
	//	"}\0";
		

	//// 模型片段着色器  有衰减、Blinn算法，Gamma校正
	//const GLchar* ModelFragShader_Blinn =
	//	"#version 330 core\n"
	//	"out vec4 color;\n"
	//	"in vec3 Normal;\n"
	//	"in vec2 TexCoords;\n"
	//	"in vec3 fragPosition;\n"
	//	"uniform vec3 lightPos;\n"
	//	"uniform vec3 viewPos;\n"

	//	"struct Material\n"
	//	"{\n"
	//	"sampler2D diffuse;\n"
	//	"vec3 specular;\n"
	//	"float shininess;\n"
	//	"};\n"
	//	"uniform Material material;\n"

	//	"struct Light\n"
	//	"{\n"
	//	"vec3 position;\n"
	//	"vec3 ambient;\n"
	//	"vec3 diffuse;\n"
	//	"vec3 specular;\n"
	//	"float constant;\n"
	//	"float linear;\n"
	//	"float quadratic;\n"
	//	"};\n"
	//	"uniform Light light;\n"

	//	"void main()\n"
	//	"{\n"
	//	// 计算衰减
	//	"float distance = length(light.position - fragPosition);\n"
	//	"float attenuation = 1.0f / (light.constant + light.linear*distance + light.quadratic*(distance*distance));\n"
	//	// 环境光照
	//	"vec3 ambient =  light.ambient * vec3(texture(material.diffuse, TexCoords));\n"
	//	// 漫反射光照
	//	"vec3 norm = normalize(Normal);\n"
	//	"vec3 lightDir = normalize(lightPos - fragPosition);\n"
	//	"float diff = max(dot(norm, lightDir), 0.0f);\n"
	//	"vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, TexCoords));\n"
	//	// 镜面高光
	//	"vec3 viewDir = normalize(viewPos - fragPosition);\n"
	//	"vec3 halfwayDir = normalize(lightDir + viewDir);\n"   // 半程向量
	//	"vec3 reflectDir = reflect(-lightDir, norm);\n"
	//	"float spec = pow(max(dot(norm, halfwayDir), 0.0f), material.shininess);\n"
	//	"vec3 specular = (material.specular * spec)* light.specular;\n"
	//	"ambient *= attenuation;\n"
	//	"diffuse *= attenuation;\n"
	//	"specular *= attenuation;\n"
	//	// 光照结果
	//	"vec3 result = ambient + diffuse + specular;\n"
	//	"float gamma = 2.2;\n"
	//	"result = pow(result, vec3(1.0f/gamma));\n"
	//	"color = vec4(result, 1.0f);\n"
	//	"}\0";

    // 模型片段着色器
	const GLchar* ModelFragShader_Blinn_mdfy =
		"#version 330 core\n"
		"out vec4 color;\n"
		"in vec3 Normal;\n"
		"in vec2 TexCoords;\n"
		"in vec3 fragPosition;\n"
		"uniform vec3 lightPos;\n"
		"uniform vec3 viewPos;\n"

		"struct Material\n"
		"{\n"
		"sampler2D texture_diffuse1;\n"
		"sampler2D texture_lightmap1;\n"
		"vec3 specular;\n"
		"float shininess;\n"
		"};\n"
		"uniform Material material;\n"

		"struct Light\n"
		"{\n"
		"vec3 position;\n"
		"vec3 ambient;\n"
		"vec3 diffuse;\n"
		"vec3 specular;\n"
		"float constant;\n"
		"float linear;\n"
		"float quadratic;\n"
		"};\n"
		"uniform Light light;\n"

		"void main()\n"
		"{\n"
		// 计算衰减
		"float distance = length(light.position - fragPosition);\n"
		"float attenuation = 1.0f / (light.constant + light.linear*distance + light.quadratic*(distance*distance));\n"
		// 环境光照
		"vec3 ambient =  light.ambient * vec3(texture(material.texture_diffuse1, TexCoords)) * vec3(texture(material.texture_lightmap1, TexCoords));\n"
		// 漫反射光照
		"vec3 norm = normalize(Normal);\n"
		"vec3 lightDir = normalize(lightPos - fragPosition);\n"
		"float diff = max(dot(norm, lightDir), 0.0f);\n"
		"vec3 diffuse = diff * light.diffuse * vec3(texture(material.texture_diffuse1, TexCoords));\n"
		// 镜面高光
		"vec3 viewDir = normalize(viewPos - fragPosition);\n"
		"vec3 halfwayDir = normalize(lightDir + viewDir);\n"   // 半程向量
		"float spec = pow(max(dot(norm, halfwayDir), 0.0f), material.shininess);\n"
		"vec3 specular = (material.specular * spec)* light.specular;\n"
		"ambient *= attenuation;\n"
		"diffuse *= attenuation;\n"
		"specular *= attenuation;\n"
		// 光照结果
		"vec3 result = ambient + diffuse + specular;\n"
		"float gamma = 2.2;\n"
		"result = pow(result, vec3(1.0f/gamma));\n"
		"color = vec4(result, 1.0f);\n"
		"}\0";



	// 光照的片段着色器
	const GLchar* LightFragShader = 
		"#version 330 core\n"
		"out vec4 color;\n"

		"void main()\n"
		"{\n"
		"color = vec4(1.0f);\n"
		"}\0";


	// 初始化opengl
	GLFWwindow* window = MyInitOpenGL();

	// 键盘、鼠标、滚轮回调
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// 隐藏光标
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// 深度测试
	glEnable(GL_DEPTH_TEST);

	// 创建VBO，VAO，EBO
	GLuint lightVBO, lightVAO, lightEBO;
	glGenBuffers(1, &lightVBO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glGenBuffers(1, &lightEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(GL_FALSE);

	// 创建着色器程序
	GLuint ShaderProgram = MyCreateShaderProgram(ModelVertexShader, ModelFragShader_Blinn_mdfy);
	GLuint LightShaderProgram = MyCreateShaderProgram(ModelVertexShader, LightFragShader);

	// 创建Model实体
	Model ourModel("D:/zhuo_mian/学习/opengl_pra/opengl_p1/opengl_project_pra_1/model5/scene.gltf");

	// 渲染循环
	while (not glfwWindowShouldClose(window))
	{
		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// 检查事件
		glfwPollEvents();
		do_movement();

		// 清空缓冲
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 启动着色器程序
		glUseProgram(ShaderProgram);

		GLint lightPosLoc = glGetUniformLocation(ShaderProgram, "lightPos");
		GLint viewPosLoc = glGetUniformLocation(ShaderProgram, "viewPos");
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
		glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);

		glUniform3f(glGetUniformLocation(ShaderProgram, "material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(glGetUniformLocation(ShaderProgram, "material.shininess"), 128.0f);
		glUniform3f(glGetUniformLocation(ShaderProgram, "light.ambient"), 0.08f, 0.08f, 0.08f);
		glUniform3f(glGetUniformLocation(ShaderProgram, "light.diffuse"), 0.85f, 0.85f, 0.85f);
		glUniform3f(glGetUniformLocation(ShaderProgram, "light.specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(ShaderProgram, "light.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(ShaderProgram, "light.linear"), 0.09);
		glUniform1f(glGetUniformLocation(ShaderProgram, "light.quadratic"), 0.032);



		// model 坐标系统转换
		glm::mat4 projection = glm::perspective(glm::radians(aspect), 800.0f / 600.0f, 0.1f, 100.0f);
		glm::mat4 view = MyCamera();
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -0.8f, 0.0f)); 
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

		// 启动model构建
		ourModel.Draw(ShaderProgram);

		// light
		glUseProgram(LightShaderProgram);
		GLuint modelLoc = glGetUniformLocation(LightShaderProgram, "model");
		GLuint viewLoc = glGetUniformLocation(LightShaderProgram, "view");
		GLuint projLoc = glGetUniformLocation(LightShaderProgram, "projection");
		// 光源模型 坐标系统转换
		glm::mat4 lightmodelmat = glm::mat4(1.0f);
		glm::mat4 lightviewmat = MyCamera();
		glm::mat4 lightprjmat = glm::mat4(1.0f);
		lightprjmat = glm::perspective(glm::radians(aspect), 800.0f / 600.0f, 0.1f, 100.0f);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(lightviewmat));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(lightprjmat));
		// human_skull
		lightPos.x = 0.25f + sin(glfwGetTime()) * 2.2f;
		lightPos.y = -0.1f + sin(glfwGetTime() / 2.0f) * 3.6f;
		lightmodelmat = glm::translate(lightmodelmat, lightPos);
		lightmodelmat = glm::scale(lightmodelmat, glm::vec3(0.2f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(lightmodelmat));
		
		// 画光源模型
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);


		// 交换缓冲
		glfwSwapBuffers(window);
	}
	MyDeleteVertexBuffer(lightVBO, lightVAO, lightEBO);
	glfwTerminate();
}

int main()
{
	Draw3DModelwithLight();
	return 0;
}
