#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Model.h"
#include <iostream>
#include "textureReader.h"

Model::Model(std::string path) {
    loadModel(path);
}

void Model::drawModel(unsigned int program) {
    for (Mesh mesh : meshes) {
        mesh.drawMesh(program);
    }
}

// Load model given by path, textures for the model should be in the same directory.
void Model::loadModel(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    // If scene creation failed, flag error.
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Error generating scene from model at: " << path << ". Error: " << importer.GetErrorString() << std::endl;
        return;
    }
    dir = path.substr(0, path.find_last_of('/'));

    // Start recursively processing nodes.
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    for (int i = 0; i < node->mNumMeshes; ++i) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]]; 
        meshes.push_back(processMesh(mesh, scene));	
    }
    for (int i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    for (int i = 0; i < mesh->mNumVertices; ++i) {
        Vertex vertex;
        glm::vec3 vector; 
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z; 
        vertex.position = vector;
        if (mesh->HasNormals()) {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.normal = vector;
        }
        // If mesh contains texture coordinates.
        if(mesh->mTextureCoords[0]) {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x; 
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoords = vec;
        } else {
            vertex.texCoords = glm::vec2(0.0f, 0.0f);
        }
        if(mesh->HasTangentsAndBitangents()) {
            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.tangent = vector;
            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.biTangent = vector;
        } else {
            vertex.tangent = glm::vec3(0.0f, 0.0f, 0.0f);
            vertex.biTangent = glm::vec3(0.0f, 0.0f, 0.0f);
        }
        vertices.push_back(vertex);
    }
    for (int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }  
    if (mesh->mMaterialIndex >= 0) {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse", textures);
        loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular", textures);
        material->Get(AI_MATKEY_OPACITY, mesh->opacity);
    }  
    return Mesh(vertices, indices, textures);
}

//TODO: Check my implementation is correct.
void Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName, std::vector<Texture>& meshTextures) {
    for (int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for (Texture tex : loadedTextures) {
            //strcmp returns 0 (false) if strings match.
            if (!std::strcmp(tex.path.data(), str.C_Str())) {
                meshTextures.push_back(tex);
                skip = true;
                break;
            }
        }
        if (!skip) {
            Texture texture;
            texture.id = TextureFromFile((dir + "/" + str.C_Str()).c_str(), false);
            texture.type = typeName;
            texture.path = str.C_Str();
            meshTextures.push_back(texture);
            loadedTextures.push_back(texture);
        }
    }
}  
