#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
	glm::vec3 direction;

	DirectionalLight();
	DirectionalLight(glm::vec3 color, double intensity, glm::vec3 direction);
	~DirectionalLight();
};

