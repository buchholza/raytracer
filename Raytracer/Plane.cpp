#include "Plane.h"

#include "Hit.h"
#include "Ray.h"

#include <iostream>

Plane::Plane()
{
	position = glm::vec3(0, 0, 0);
	normal = glm::vec3(0, 1, 0);
}

Plane::Plane(glm::vec3 color, double albedo, glm::vec3 position, glm::vec3 normal) : Object(color, albedo)
{
	this->position = position;
	this->normal = glm::normalize(normal);
}

Plane::~Plane()
{
}

Hit Plane::intersect(const Ray &ray)
{
	Hit hit;

	double denom = glm::dot(normal, ray.direction);
	if(abs(denom) > 1e-6)
	{
		glm::vec3 h = position - ray.origin;
		double t = glm::dot(h, normal) / denom;
		if(t >= 0)
		{
			hit.t = t;
			hit.location = ray.origin + (float)t * ray.direction;
			hit.hitObject = this;
		}
	}

	return hit;
}

glm::vec3 Plane::calculateNormal(glm::vec3 location)
{
	return normal;
}
