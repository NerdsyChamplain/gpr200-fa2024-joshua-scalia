#include <stdio.h>
#include <math.h>

#include <ew/external/glad.h>
#include <ew/ewMath/ewMath.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <C:\Users\Josh\Documents\GitHub\gpr200-fa2024-joshua-scalia\core\josh\shader.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

float posXBotRight = 0.5f;
float posXBotLeft = -0.5f;
float posXTop = 0.0f;
float posYBotRight = -0.5f;
float posYBotLeft = -0.5f;
float posYTop = 0.5f;
const float POSZ = 0.0f;
float red = 1.0f;
float green = 1.0f;
float blue = 1.0f;
const float NONTARGCOLORS = 0.0f;
float vertices[] = {
	// positions                           // colors
	 posXBotRight, posYBotRight, POSZ,  red, NONTARGCOLORS, NONTARGCOLORS,   // bottom right
	posXBotLeft, posYBotLeft, POSZ,  NONTARGCOLORS, green, NONTARGCOLORS,   // bottom left
	 posXTop,  posYTop, POSZ,  NONTARGCOLORS, NONTARGCOLORS, blue    // top 
};

int main() {
	printf("Initializing...");
	if (!glfwInit()) {
		printf("GLFW failed to init!");
		return 1;
	}
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello Triangle", NULL, NULL);
	if (window == NULL) {
		printf("GLFW failed to create window");
		return 1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGL(glfwGetProcAddress)) {
		printf("GLAD Failed to load GL headers");
		return 1;
	}
	Shader ourShader("C:/Users/Josh/Documents/GitHub/gpr200-fa2024-joshua-scalia/assignments/assignment1_helloTriangle/assets/vertexShader.vert", "C:/Users/Josh/Documents/GitHub/gpr200-fa2024-joshua-scalia/assignments/assignment1_helloTriangle/assets/fragmentShader.frag");

//shaders
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//Render loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		//Clear framebuffer
		glClearColor(0.3f, 0.4f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		float timeValue = glfwGetTime();
		red = (sin(timeValue) / 2.0f) + 0.5f;
		green = (cos(timeValue) / 2.0f) + 0.5f;
		blue = (tan(timeValue) / 2.0f) + 0.5f;
		posYBotRight += 0.0001f;
		if (posYBotRight >= 0.6f)
		{
			posYBotRight = -0.5f;
		}
		posYBotLeft += 0.0001f;
		if (posYBotLeft >= 0.6f)
		{
			posYBotLeft = -0.5f;
		}
		posYTop += 0.0001f;
		if (posYTop >= 1.0f)
		{
			posYTop = 0.5f;
		}
		float vertices[] = {
			// positions                           // colors
			 posXBotRight, posYBotRight, POSZ,  red, NONTARGCOLORS, NONTARGCOLORS,   // bottom right
			posXBotLeft, posYBotLeft, POSZ,  NONTARGCOLORS, green, NONTARGCOLORS,   // bottom left
			 posXTop,  posYTop, POSZ,  NONTARGCOLORS, NONTARGCOLORS, blue    // top 
		};
		//Drawing happens here!
		// update shader uniform
		ourShader.use();
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
	}
	printf("Shutting down...");



}
	