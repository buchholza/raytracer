#include "FinitePlane.h"

#include "Hit.h"
#include "Ray.h"

FinitePlane::FinitePlane() : Plane()
{
	lengthDir = glm::vec3(0, 1, 0);
	length = 1;
	widthDir = glm::vec3(1, 0, 0);
	width = 1;
}

FinitePlane::FinitePlane(glm::vec3 color, float albedo, glm::vec3 position, glm::vec3 normal, glm::vec3 lengthDir, float length, glm::vec3 widthDir, float width) : Plane(color, albedo, position, normal)
{
	this->lengthDir = glm::normalize(lengthDir);
	this->length = length;
	this->widthDir = glm::normalize(widthDir);
	this->width = width;
}

FinitePlane::~FinitePlane()
{
}

Hit FinitePlane::intersect(const Ray &ray)
{
	Hit hit;

	float denom = glm::dot(normal, ray.direction);
	if(abs(denom) > 1e-6)
	{
		glm::vec3 h = position - ray.origin;
		float t = glm::dot(h, normal) / denom;
		if(t >= 0)
		{
			glm::vec3 location = ray.origin + (float)t * ray.direction;
			glm::vec3 diff = location - position;
			if(abs(glm::dot(diff, lengthDir)) < length && abs(glm::dot(diff, widthDir)) < width)
			{
				hit.t = t;
				hit.location = ray.origin + (float)t * ray.direction;
				hit.hitObject = this;
			}
		}
	}

	return hit;
}
