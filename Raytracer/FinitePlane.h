#pragma once
#include "Plane.h"
class FinitePlane :
	public Plane
{
public:
	glm::vec3 lengthDir;
	float length;
	glm::vec3 widthDir;
	float width;

	FinitePlane();
	FinitePlane(glm::vec3 color, float albedo, glm::vec3 position, glm::vec3 normal, glm::vec3 lengthDir, float length, glm::vec3 widthDir, float width);
	~FinitePlane();

	Hit intersect(const Ray &ray);
};

