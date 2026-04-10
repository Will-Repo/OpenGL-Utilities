#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

void setUpFramebuffer(GLuint* framebuffer, GLuint* texture);
void createVAO(unsigned int& VAO, const std::vector<float>& vertices);
