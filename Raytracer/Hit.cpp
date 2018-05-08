#include "Hit.h"

Hit::Hit()
{
	t = F_INFINITY;
	location = glm::vec3(0, 0, 0);
	hitObject = NULL;
}

Hit::Hit(float t, glm::vec3 location, Object* hitObject)
{
	this->t = t;
	this->location = location;
	this->hitObject = hitObject;
}

Hit::~Hit()
{
}
