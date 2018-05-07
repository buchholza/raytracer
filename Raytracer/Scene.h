#pragma once

#include <vector>
#include <memory>

#include "glm/glm.hpp"

#include "Camera.h"
#include "Light.h"
#include "Object.h"

// Forward declarations
class Ray;
class Hit;

class Scene
{
public:
	glm::vec3 backgroundColor;
	std::vector<std::unique_ptr<Object>> *objects;
	std::vector<std::unique_ptr<Light>> *lights;
	Camera camera;
	double bias;

	Scene();
	Scene(glm::vec3 backgroundColor, std::vector<std::unique_ptr<Object>> *objects, std::vector<std::unique_ptr<Light>> *lights, Camera camera, double bias);
	~Scene();

	glm::vec3* render();
	Hit trace(Ray &ray);
	glm::vec3 castRay(Ray &ray);
};

