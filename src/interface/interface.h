#include <iostream>

#define IMGUI_DEFINE_MATH_OPERATORS 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Interface {
public:

	void initInterface(GLFWwindow* window);
	void drawInterface();
	void render();
	void destroyInterface();

private:


};