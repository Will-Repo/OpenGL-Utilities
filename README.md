# General-Utilities
General cpp utilities library.

## Features
* File reading.

## Build, dependencies & including in projects
First off, ideally the top level project should declare dependencies, to ensure versions match what is required by the main project. If these are not declared, the library will fall back on fetch content to provide the dependencies, but this is not recommended. The following dependencies (target name in bold) should be declared:
* 

Top-level dependencies (libraries and minimum versions the top-level project must declare):
* **GLM** - Minimum Version: 1.0.3
* **GLEW** - Minimum Version: 2.3.1
* **GLFW** - Minimum Version: 3.4
* **FreeType** - Minimum Version: 2.14.2

## To-do
* Properly accredit dependencies, include licenses.
* Remove filepaths object references, use fixed path - renderText.
