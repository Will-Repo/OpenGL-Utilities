# General-Utilities
General cpp utilities library.

## Features
* File reading.
* Model loading - with per mesh AABBs to allow for manual collision detection to be implemented on a per app basis (currently).

## Supports
* obj + mtl files, with pngs for associated textures.

## Build, dependencies & including in projects
First off, ideally the top level project should declare dependencies, to ensure versions match what is required by the main project. If these are not declared, the library will fall back on fetch content to provide the dependencies, but this is not recommended. The following dependencies (target name in bold) should be declared.
Top-level dependencies (libraries and minimum versions the top-level project must declare):
* **GLM** - Minimum Version: 1.0.3
* **GLEW** - Minimum Version: 2.3.1
* **GLFW** - Minimum Version: 3.4
* **FreeType** - Minimum Version: 2.14.2

## To-do
* Properly accredit dependencies, include licenses.
* Remove filepaths object references, use fixed path - renderText.
* Add AABBs to each mesh. These are publically accessible, and program can decide what to do with each mesh depending on its AABB.
