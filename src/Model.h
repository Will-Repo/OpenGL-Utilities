#pragma once
#include <string>
#include <vector>
#include "Mesh.h"

class Model {
    public:
        Model(std::string path);
        void drawModel(unsigned int program);
    private:
        std::vector<Mesh> meshes;
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        std::string dir; // Path to textures.
};
