#pragma once

#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Forward declarations
class Ray;

class Camera
{
public:
	// Camera members
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 worldToCamera;
	glm::mat4 cameraToWorld;

	// Image members
	uint32_t imageWidth;
	uint32_t imageHeight;
	double fov;
	double aspectRatio;
	double scale;

	Camera();
	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up, uint32_t imageWidth, uint32_t imageHeight, double fov);
	~Camera();

	std::vector<Ray> generateRays();
};

