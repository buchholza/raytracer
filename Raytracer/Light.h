#pragma once

#include "glm/glm.hpp"

class Light
{
public:
	double intensity;
	glm::vec3 color;

	Light();
	Light(glm::vec3 color, double intensity);
	~Light();
};

