# 92-spoons-AI
An AI that you can teach things.
## Compiling for Mac
This is very easy, just run ```make``` or compile, then if you want to run directly from the terminal, type ```chmod +x ai```. Then to run, type ```./ai```. If you want a dev version, type ```make dev```.
## Compiling for Windows
Install Visual Studio. Make a new project, then add ```#include "stdafx.h"``` at the very start of the file, then compile.
# Docs:
All of the API is in `files.cpp `
## `files::fileopen(string filename)`
Opens file.
## `files::read()`
This reads the file. 

