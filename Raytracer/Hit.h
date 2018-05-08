#pragma once

#include <limits>

#include "glm/glm.hpp"

#include "Object.h"

const float F_INFINITY = std::numeric_limits<float>::max();

class Hit
{
public:
	float t;
	glm::vec3 location;
	Object* hitObject;

	Hit();
	Hit(float t, glm::vec3 location, Object* hitObject);
	~Hit();
};

