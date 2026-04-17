#pragma once 
#include <glm/glm.hpp>
#include <string>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
    glm::vec3 tangent;
    glm::vec3 biTangent;
};

struct Texture {
    unsigned int id;
    std::string type;    
    std::string path;  // For comparison with other textures.
};  

class Mesh {
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void drawMesh(unsigned int program);
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        float opacity = 1.0f;
    private:
        unsigned int VAO;
        void setupMesh();
};
