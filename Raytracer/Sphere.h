#pragma once

#include "glm/glm.hpp"

#include "Object.h"

class Sphere : public Object
{
public:
	glm::vec3 center;
	float radius;

	Sphere();
	Sphere(glm::vec3 color, float albedo, glm::vec3 center, float radius);
	~Sphere();

	Hit intersect(const Ray &ray);
	glm::vec3 calculateNormal(glm::vec3 location);
};
