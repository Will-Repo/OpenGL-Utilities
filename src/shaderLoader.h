#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

enum class ShaderDataType {
    Path,
    Source
};

struct ShaderInfo {
    GLenum type;
    const char* data; //File path from shaders directory, or full source.
    ShaderDataType dataType;
};

// Takes in array of shaders with names, and path to directory containing them.
GLuint loadShaders(ShaderInfo* info, std::string dirPath);
GLuint compileShader(GLenum type, std::string sourceString);
