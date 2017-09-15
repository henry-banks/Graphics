#pragma once

#include "RenderObject.h"

Texture loadTexture(const char *path);

Shader loadShader(const char * vPath, const char * fPath);
Shader loadShader(const char * vPath, const char * tcsPath, const char * tesPath, const char * gPath, const char * fPath);
Shader loadShader(const char * vPath, const char * tcsPath, const char * tesPath, const char * fPath);


Geometry loadGeometry(const char *path);