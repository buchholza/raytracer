#pragma once

#include "glm/glm.hpp"

class Light
{
public:
	float intensity;
	glm::vec3 color;

	Light();
	Light(glm::vec3 color, float intensity);
	~Light();
};

