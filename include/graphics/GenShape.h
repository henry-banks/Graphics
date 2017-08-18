#pragma once


struct Geometry;

Geometry makeRectangle(float x, float y, float w, float h);

Geometry makeCheckerboard(float x, float y, float rad);

Geometry makeNGon(size_t sides, float r);