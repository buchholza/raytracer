#include "Hit.h"

Hit::Hit()
{
	t = D_INFINITY;
	location = glm::vec3(0, 0, 0);
	hitObject = NULL;
}

Hit::Hit(double t, glm::vec3 location, Object* hitObject)
{
	this->t = t;
	this->location = location;
	this->hitObject = hitObject;
}

Hit::~Hit()
{
}
