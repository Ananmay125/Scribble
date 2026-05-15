// scribble.cpp
#include "scribble.h"
#include "graphics/window.h"

int main() {

	Window window;

	while (!window.shouldClose()) {

		glClearColor(0.145f, 0.145f, 0.149f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffers();
		window.pollEvents();
	}

	window.clean();
	return 0;
}
