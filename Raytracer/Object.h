#pragma once

#include "glm/glm.hpp"

// Forward declarations
class Hit;
class Ray;

class Object
{
public:
	glm::vec3 color;
	float albedo;

	Object();
	Object(glm::vec3 color, float albedo);
	~Object();
	
	virtual Hit intersect(const Ray &ray) = 0;
	virtual glm::vec3 calculateNormal(glm::vec3 location) = 0;
};

