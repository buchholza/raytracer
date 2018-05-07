#include "Camera.h"

#include "Ray.h"

Camera::Camera()
{
	position = glm::vec3(0, 0, 0);
	direction = glm::vec3(0, 0, -1);
	up = glm::vec3(0, 1, 0);
	worldToCamera = glm::lookAt(position, direction, up);
	cameraToWorld = glm::inverse(worldToCamera);

	cameraToWorld = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0, 1, 0));

	this->imageWidth = 640;
	this->imageHeight = 480;
	this->fov = 60;
	aspectRatio = imageWidth / (double)imageHeight;
	scale = tan(glm::radians(fov * 0.5));
}

Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up, uint32_t imageWidth, uint32_t imageHeight, double fov)
{
	this->position = position;
	this->direction = direction;
	this->up = up;
	worldToCamera = glm::lookAt(position, direction, up);
	cameraToWorld = glm::inverse(worldToCamera);

	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	this->fov = fov;
	aspectRatio = imageWidth / (double)imageHeight;
	scale = tan(glm::radians(fov * 0.5));
}

Camera::~Camera()
{
}

std::vector<Ray> Camera::generateRays()
{
	std::vector<Ray> rays;
	glm::vec3 origin = glm::vec3(cameraToWorld * glm::vec4(0, 0, 0, 1));

	for(uint32_t j = 0; j < imageHeight; j++)
	{
		for(uint32_t i = 0; i < imageWidth; i++)
		{
			double x = (2 * (i + 0.5) / (double)imageWidth - 1) * aspectRatio * scale;
			double y = (1 - 2 * (j + 0.5) / (double)imageHeight) * scale;
			glm::vec3 direction = glm::normalize(glm::vec3(cameraToWorld * glm::vec4(x, y, 1, 0)));

			rays.push_back(Ray(origin, direction));
		}
	}

	return rays;
}
