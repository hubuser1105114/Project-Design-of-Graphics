
#include "MyHeader.h"

extern const GLchar* fragmentShaderSource;
extern const GLchar* vertexShaderSource;

int main()
{
	// init opengl and return a window
	GLFWwindow* window = MyInitOpenGL();

	// �����ص� 
	glfwSetKeyCallback(window, key_callback);

	// init VBO, VAO, EBO
	auto temp = MyInitVertexBuffer();
	GLuint VBO = std::get<0>(temp),
		   VAO = std::get<1>(temp),
		   EBO = std::get<2>(temp);

	// create texture1,2
	GLuint texture1 = MyCreateTexture("container2.jpg");
	GLuint texture2 = MyCreateTexture("tupian1.jpg");

	// create a shader program with vertex shader and fragment shader
	GLuint shaderProgram = MyCreateShaderProgram(vertexShaderSource, fragmentShaderSource);

	
		
	// ������Ȳ���
	glEnable(GL_DEPTH_TEST);

	/* ѭ�����ִ��� */
	while (not glfwWindowShouldClose(window))
	{
		// ����¼�
		glfwPollEvents();

		// ��ջ���
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		// ʹ������Ԫ������
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);

		//������ɫ��
		glUseProgram(shaderProgram);

		//glm::mat4 transform = glm::mat4(1.0f);
		//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
		//transform = glm::rotate(transform, (GLfloat)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		//GLuint transformLoc = glGetUniformLocation(shaderProgram, "transform");
		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

	// ����һ��ģ�;���
	// ����ƽ�ơ���������ת
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, (GLfloat)glfwGetTime()*2.0f, glm::vec3(0.5f, 1.0f, 0.0f));

		// ����һ���۲����
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		// ����һ��ͶӰ����
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);


		// ����ϵͳ����ת��
		GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
		GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
		GLint projLoc = glGetUniformLocation(shaderProgram, "projection");

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		//��������
		glBindVertexArray(VAO);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		for (GLuint i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			GLfloat angle = 20.0f * i;
			model = glm::rotate(model, (GLfloat)glfwGetTime()*2.0f, glm::vec3(1.0f, 0.3f, 0.5f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glDrawArrays(GL_TRIANGLES, 0, 36);
	    glBindVertexArray(GL_FALSE);
		// ��������
		glfwSwapBuffers(window);
	}

	// delete buffer and vertex array
	MyDeleteVertexBuffer(VBO, VAO, EBO);

	/* ��ֹ���ڣ�������Դ */
	glfwTerminate();
	return 0;
}
