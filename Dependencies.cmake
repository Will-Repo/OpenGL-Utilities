include(FetchContent)

# Check if each is installed by top-level app, if not, install minimum required version ourselves.

# GLM - Version 1.0.3
find_package(glm 1.0.3 QUIET) # Module mode
if (NOT glm_FOUND)
    FetchContent_Declare(
    	glm
    	GIT_REPOSITORY	https://github.com/g-truc/glm.git
    	GIT_TAG 	8d1fd52e5ab5590e2c81768ace50c72bae28f2ed
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glm)
    set(GLM_INCLUDE_DIR ${glm_SOURCE_DIR}/include)
endif()
set_target_properties(glm PROPERTIES FOLDER "Dependencies") # Only affects IDE folder placement, not actual file location, so not really necessary for me.

# GLEW - Version 2.3.1
find_package(GLEW 2.3.1 QUIET) # Module mode
if (NOT GLEW_FOUND)
    FetchContent_Declare(
    	glew
        #GIT_REPOSITORY	https://github.com/nigels-com/glew.git
        #GIT_TAG 	glew-2.3.1
        URL https://github.com/nigels-com/glew/releases/download/glew-2.3.1/glew-2.3.1.tgz
        SOURCE_SUBDIR  build/cmake
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glew)  
    set(GLEW_INCLUDE_DIR ${glew_SOURCE_DIR}/include)
endif()
set_target_properties(glew_s PROPERTIES FOLDER "Dependencies")

# GLFW - Version 3.4
find_package(glfw 3.4 QUIET) # Module mode
if (NOT glfw_FOUND)
    FetchContent_Declare(
    	glfw
    	GIT_REPOSITORY	https://github.com/glfw/glfw.git
        GIT_TAG 	7b6aead9fb88b3623e3b3725ebb42670cbe4c579
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glfw)
    set(GLFW_INCLUDE_DIR ${glfw_SOURCE_DIR}/include)
endif()
set_target_properties(glfw PROPERTIES FOLDER "Dependencies")

# FreeType - Version 2.14.1
find_package(FreeType 2.14.1 QUIET)
if (NOT FreeType_FOUND)
    FetchContent_Declare(
        FreeType
    	GIT_REPOSITORY	https://gitlab.com/freetype/freetype.git
        GIT_TAG 	f4205da14867c5387cd6a329b90ee10a6df6eeff
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(FreeType)
    set(FREETYPE_INCLUDE_DIR ${FreeType_SOURCE_DIR}/include)
endif()
set_target_properties(freetype PROPERTIES FOLDER "Dependencies")

# General utils.
find_package(General-Utils QUIET)
if (NOT General-Utils_FOUND)
    # General utils
    FetchContent_Declare(
        general_utils
        GIT_REPOSITORY https://github.com/Will-Repo/General-Utilities.git
        GIT_TAG main
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(general_utils)  
    set(GENERAL_UTILS_INCLUDE_DIR ${general_utils_SOURCE_DIR}/src)
endif()
