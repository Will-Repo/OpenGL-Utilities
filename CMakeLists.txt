cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(OpenGL-Utils)

include(Dependencies.cmake)

file(GLOB OPENGL_SRC
    src/*.cpp
)

add_library(OpenGL-Utils STATIC ${OPENGL_SRC})

target_link_libraries(OpenGL-Utils PUBLIC 
    glm glew_s glfw freetype General-Utils assimp
)

target_include_directories(OpenGL-Utils PUBLIC 
    src vendor ${GLM_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIR} ${GENERAL_UTILS_INCLUDE_DIR} ${ASSIMP_INCLUDE_DIR}

)
