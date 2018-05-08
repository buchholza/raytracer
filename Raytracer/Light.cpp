#include "Light.h"

Light::Light()
{
	color = glm::vec3(255, 255, 255);
	intensity = 1;
}

Light::Light(glm::vec3 color, float intensity)
{
	this->color = color;
	this->intensity = intensity;
}

Light::~Light()
{
}
