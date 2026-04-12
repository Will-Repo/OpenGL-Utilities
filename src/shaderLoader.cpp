#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shaderLoader.h"
#include <iostream>
#include <string>
#include "fileReading.h"

GLuint loadShaders(ShaderInfo* info, std::string dirPath) {
    GLuint program = glCreateProgram();
    for (int enumType = 0; info[enumType].type != GL_NONE; enumType++) {
        std::string sourceString;
        if (info[enumType].dataType == ShaderDataType::Path) {
            const char* filePath = info[enumType].data;
            sourceString = getFileContents((dirPath + "/" + filePath).c_str());
        } else if (info[enumType].dataType == ShaderDataType::Path) {
            sourceString = info[enumType].data;
        }
        GLuint shader = compileShader(info[enumType].type, sourceString);
        glAttachShader(program, shader);
        glDeleteShader(shader);
    }
    glLinkProgram(program);
    //TODO: Error check.
    
    return program;
}

GLuint compileShader(GLenum type, std::string sourceString) {
    const char* source = sourceString.c_str();
    int success;
    char infoLog[512];
    
    //std::cout << source << std::endl;
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader compilation failed: " << type << ", " << infoLog << std::endl;
    };

    return shader;
}
