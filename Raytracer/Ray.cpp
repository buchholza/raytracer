#include "Ray.h"

Ray::Ray()
{
	origin = glm::vec3(0, 0, 0);
	direction = glm::vec3(0, 0, -1);
}

Ray::Ray(glm::vec3 origin, glm::vec3 direction)
{
	this->origin = origin;
	this->direction = direction;
}

Ray::~Ray()
{
}
