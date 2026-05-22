// scribble.cpp
#include "scribble.h"

#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/draw.h"

Whiteboard* globalBoard = nullptr;
bool isDrawing = false;
int windowWidth = 1000;
int windowHeight = 600;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            isDrawing = true;
            if (globalBoard) globalBoard->startStroke();
        }
        else if (action == GLFW_RELEASE) {
            isDrawing = false;
        }
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        if (globalBoard) globalBoard->clear();
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isDrawing && globalBoard) {
        float ndcX = (2.0f * xpos) / windowWidth - 1.0f;
        float ndcY = 1.0f - (2.0f * ypos) / windowHeight;

        globalBoard->addPoint(ndcX, ndcY);
    }
}

int main() {

	Window window;
	Shader tuffShader("shaders/brush.vert", "shaders/brush.frag");

    Whiteboard board;
    globalBoard = &board;

    GLFWwindow* rawWindow = window.getWindow();

    glfwSetMouseButtonCallback(rawWindow, mouse_button_callback);
    glfwSetCursorPosCallback(rawWindow, cursor_position_callback);

	while (!window.shouldClose()) {

		glClearColor(0.145f, 0.145f, 0.149f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		tuffShader.use();
        board.draw();

		window.swapBuffers();
		window.pollEvents();
	}

	window.clean();
	return 0;
}
