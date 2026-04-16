#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

void setUpFramebuffer(GLuint* framebuffer, GLuint* texture);
// Return VAO for drawing a quad.
template <typename T>
void createVAO(unsigned int& VAO, const std::vector<T>& vertices) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(T), vertices.data(), GL_STATIC_DRAW);
}
std::vector<float> getQuad(glm::vec2 centre, float width, float height, float depth, glm::vec3 colour);
std::vector<unsigned int> getQuadEBO();
void bindEBO(const std::vector<unsigned int>& indices);
