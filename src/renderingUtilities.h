#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

void setUpFramebuffer(GLuint* framebuffer, GLuint* texture);
void createVAO(unsigned int& VAO, const std::vector<float>& vertices);
std::vector<float> getQuad(glm::vec2 centre, float width, float height);
std::vector<int> getQuadEBO();
void bindEBO(const std::vector<int>& indices);
