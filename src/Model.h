#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <vector>
#include "Mesh.h"

class Model {
    public:
        Model() = default; // For cases where objects allocated immediately - must be overriden before use.
        Model(std::string path);
        void drawModel(unsigned int program);
        std::vector<Mesh> meshes;
    private:
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        void loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName, std::vector<Texture>& loadedTextures);
        std::string dir; // Path to textures.
        std::vector<Texture> loadedTextures; // Vector of textures already loaded, to avoid duplication.
};
