#pragma once
#include "Plane.h"
class FinitePlane :
	public Plane
{
public:
	glm::vec3 lengthDir;
	double length;
	glm::vec3 widthDir;
	double width;

	FinitePlane();
	FinitePlane(glm::vec3 color, double albedo, glm::vec3 position, glm::vec3 normal, glm::vec3 lengthDir, double length, glm::vec3 widthDir, double width);
	~FinitePlane();

	Hit intersect(const Ray &ray);
};

