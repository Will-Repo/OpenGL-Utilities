cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

project(OpenGL-Utils)

include(Dependencies.cmake)

add_library(OpenGL-Utils STATIC ${OPENGL_SRC})

#target_link_libraries(core PUBLIC 
#    glm glew_s glfw OpenAL freetype
#)

#target_include_directories(core PUBLIC 
#   src src/utility src/Threads src/Events vendor ${GLM_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${OPENALSOFT_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIR} ${WHEREAMI_INCLUDE_DIR}
#)
