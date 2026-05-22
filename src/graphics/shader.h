#pragma once

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Note: this was taken from another repository.. 

class Shader {
public:

	unsigned int ID;

	Shader(const char* vertexFilePath, const char* fragmentFilePath);

	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	int getID();
};