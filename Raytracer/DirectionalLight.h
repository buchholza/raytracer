#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
	glm::vec3 direction;

	DirectionalLight();
	DirectionalLight(glm::vec3 color, float intensity, glm::vec3 direction);
	~DirectionalLight();
};

