#pragma once

#include "Light.h"

class PointLight : public Light
{
public:
	glm::vec3 position;

	PointLight();
	PointLight(glm::vec3 color, double intensity, glm::vec3 position);
	~PointLight();

	glm::vec3 getColorIntensity(glm::vec3 point);
	glm::vec3 getLightDirection(glm::vec3 point);
	double getLightDist(glm::vec3 distance);
};

