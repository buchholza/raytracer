#pragma once

#include <limits>

#include "glm/glm.hpp"

#include "Object.h"

const double D_INFINITY = std::numeric_limits<double>::max();

class Hit
{
public:
	double t;
	glm::vec3 location;
	Object* hitObject;

	Hit();
	Hit(double t, glm::vec3 location, Object* hitObject);
	~Hit();
};

