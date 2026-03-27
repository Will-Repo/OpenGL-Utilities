# OpenGL-Utilities
Repository for OpenGL utility functions.

## Features
* Rendering basic geometry - quads, triangles.
* Rendering text.
* Compiling shaders.
* Loading models.

## Build, dependencies & including in projects
First off, ideally the top level project should declare dependencies, to ensure versions match what is required by the main project. If these are not declared, the library will fall back on fetch content to provide the dependencies, but this is not recommended. The following dependencies (target name in bold) should be declared:
* **General-Utils** - primarily for file reading when compiling shaders.
*

## To-do
