#pragma once

#include "Object.h"

class Plane : public Object
{
public:
	glm::vec3 position;
	glm::vec3 normal;

	Plane();
	Plane(glm::vec3 color, double albedo, glm::vec3 position, glm::vec3 normal);
	~Plane();

	virtual Hit intersect(const Ray &ray);
	glm::vec3 calculateNormal(glm::vec3 location);
};

