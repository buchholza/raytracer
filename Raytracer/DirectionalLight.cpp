#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
{
	direction = direction;
}

DirectionalLight::DirectionalLight(glm::vec3 color, double intensity, glm::vec3 direction) : Light(color, intensity)
{
	this->direction = glm::normalize(direction);
}

DirectionalLight::~DirectionalLight()
{
}
