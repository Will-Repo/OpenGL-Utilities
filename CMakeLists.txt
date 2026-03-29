cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

project(OpenGL-Utils)

include(Dependencies.cmake)

add_library(OpenGL-Utils STATIC ${OPENGL_SRC})

target_link_libraries(OpenGL-Utils PUBLIC 
    glm glew_s glfw freetype
)

target_include_directories(core PUBLIC 
   src ${GLM_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIR}
)
