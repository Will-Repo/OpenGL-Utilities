#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "renderingUtilities.h"
#include <glm/glm.hpp>

void setUpFramebuffer(GLuint* framebuffer, GLuint* texture) {
    glGenFramebuffers(1, framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, *framebuffer);

    glGenTextures(1, texture);

    glBindTexture(GL_TEXTURE_2D, *texture);

    //TODO: Make texture/window size dynamic. pass in window config.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 1920, 1080, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, *texture, 0);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "Framebuffer creation failed." << std::endl;
        exit(1);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

/*// Return VAO for drawing a quad.
template <typename T>
void createVAO(unsigned int& VAO, const std::vector<T>& vertices) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(T), vertices.data(), GL_STATIC_DRAW);
}*/

// Takes in normalised opengl values.
std::vector<float> getQuad(glm::vec2 centre, float width, float height, glm::vec3 colour) {
    std::vector<float> quad = {
        centre.x - 0.5 * width, centre.y - 0.5 * height, colour.x, colour.y, colour.z,
        centre.x + 0.5 * width, centre.y - 0.5 * height, colour.x, colour.y, colour.z,
        centre.x - 0.5 * width, centre.y + 0.5 * height, colour.x, colour.y, colour.z,
        centre.x + 0.5 * width, centre.y + 0.5 * height, colour.x, colour.y, colour.z
    };
    return quad;
}

std::vector<unsigned int> getQuadEBO() {
    std::vector<unsigned int> ebo = {
        0, 1, 2,
        1, 2, 3
    };
    return ebo;
}

// VAO should be bound currently.
void bindEBO(const std::vector<unsigned int>& indices) {
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}
