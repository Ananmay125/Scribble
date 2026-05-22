#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:

	Window();
	
	bool shouldClose();
	void swapBuffers();
	void pollEvents();
	void clean();

	GLFWwindow* getWindow();

private:

	GLFWwindow* window;
	int width = 1000;
	int height = 600;
};