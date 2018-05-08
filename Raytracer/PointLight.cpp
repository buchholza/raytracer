#include "PointLight.h"

#include "glm/gtx/norm.hpp"

#define M_PI 3.1415926535897

PointLight::PointLight()
{
	position = position;
}

PointLight::PointLight(glm::vec3 color, float intensity, glm::vec3 position) : Light(color, intensity)
{
	this->position = position;
}

PointLight::~PointLight()
{
}

glm::vec3 PointLight::getColorIntensity(glm::vec3 point)
{
	glm::vec3 lightDir = position - point;
	float r2 = lightDir.x * lightDir.x + lightDir.y * lightDir.y + lightDir.z * lightDir.z;
	return (float)intensity * color / (4 * (float)M_PI * (float)r2);
}

glm::vec3 PointLight::getLightDirection(glm::vec3 point)
{
	glm::vec3 lightDir = position - point;
	return glm::normalize(lightDir);
}

float PointLight::getLightDist(glm::vec3 point)
{
	glm::vec3 lightDir = position - point;
	float r2 = lightDir.x * lightDir.x + lightDir.y * lightDir.y + lightDir.z * lightDir.z;
	return sqrt(r2);
}
