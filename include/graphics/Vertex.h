#pragma once

#include "glm\glm.hpp"

struct Vertex
{
	glm::vec4 pos;	// 4 floats = 16 bytes, pos starts at byte 0 and eats up to byte 15
	glm::vec4 color; // color starts at... 16
	glm::vec2 texCoord;
};