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
	float fov;
	float aspectRatio;
	float scale;

	Camera();
	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up, uint32_t imageWidth, uint32_t imageHeight, float fov);
	~Camera();

	std::vector<Ray> generateRays();
};

