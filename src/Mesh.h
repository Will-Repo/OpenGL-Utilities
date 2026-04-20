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

struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

class Mesh {
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void drawMesh(unsigned int program);
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        float opacity = 1.0f;
        AABB aabb;
    private:
        unsigned int VAO;
        void setupMesh();
};
