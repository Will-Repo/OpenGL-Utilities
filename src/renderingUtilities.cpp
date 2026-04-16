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

    //TODO: Make texture/window size dynamic. pass in dimensions from window config.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 1920, 1080, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, *texture, 0); 

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    // Application should check and handle this how they want, not this library.
    /*if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "Framebuffer creation failed." << std::endl;
        exit(1);
    }*/
    
    //TODO: Return this to caller, perhaps along with data struct, or just as pointer passed in.
    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo); 
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1920, 1080);  
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// Takes in normalised opengl values.
std::vector<float> getQuad(glm::vec2 centre, float width, float height, float depth, glm::vec3 colour) {
    std::vector<float> quad = {
        (float)(centre.x - 0.5 * width), (float)(centre.y - 0.5 * height), depth, colour.x, colour.y, colour.z,
        (float)(centre.x + 0.5 * width), (float)(centre.y - 0.5 * height), depth, colour.x, colour.y, colour.z,
        (float)(centre.x - 0.5 * width), (float)(centre.y + 0.5 * height), depth, colour.x, colour.y, colour.z,
        (float)(centre.x + 0.5 * width), (float)(centre.y + 0.5 * height), depth, colour.x, colour.y, colour.z
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
