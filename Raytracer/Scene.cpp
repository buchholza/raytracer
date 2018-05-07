#include "Scene.h"

#include <algorithm>
#define M_PI 3.14159265358979323846

#include "DirectionalLight.h"
#include "PointLight.h"
#include "Hit.h"
#include "Ray.h"

Scene::Scene()
{
	backgroundColor = glm::vec3(88, 139, 218);
	objects = new std::vector<std::unique_ptr<Object>>();
	lights = new std::vector<std::unique_ptr<Light>>();
	camera = Camera();
	bias = 0.001;
}

Scene::Scene(glm::vec3 backgroundColor, std::vector<std::unique_ptr<Object>> *objects, std::vector<std::unique_ptr<Light>> *lights, Camera camera, double bias)
{
	this->backgroundColor = backgroundColor;
	this->objects = objects;
	this->lights = lights;
	this->camera = camera;
	this->bias = bias;
}

Scene::~Scene()
{
}

glm::vec3* Scene::render()
{
	glm::vec3 *framebuffer = new glm::vec3[camera.imageWidth * camera.imageHeight];
	glm::vec3 *pixel = framebuffer;

	std::vector<Ray> rays = camera.generateRays();
	for(std::vector<Ray>::iterator iter = rays.begin(); iter != rays.end(); ++iter)
	{
		*pixel = castRay(*iter);
		pixel++;
	}

	return framebuffer;
}

Hit Scene::trace(Ray &ray)
{
	Hit nearestHit;
	for(std::vector<std::unique_ptr<Object>>::const_iterator iter = objects->begin(); iter != objects->end(); ++iter)
	{
		Hit hit = (*iter)->intersect(ray);
		if(hit.hitObject != NULL && hit.t < nearestHit.t)
		{
			nearestHit = hit;
		}
	}
	return nearestHit;
}

glm::vec3 Scene::castRay(Ray &ray)
{
	glm::vec3 hitColor = glm::vec3(0, 0, 0);

	Hit hit = trace(ray);
	if(hit.hitObject != NULL)
	{
		
		DirectionalLight light = *((DirectionalLight*)lights->at(0).get());
		glm::vec3 normal = hit.hitObject->calculateNormal(hit.location);
		Ray shadowRay = Ray(hit.location + normal * (float)bias, -light.direction);
		bool visible = trace(shadowRay).hitObject == NULL;
		hitColor = visible * (float)hit.hitObject->albedo / (float)M_PI * (float)light.intensity * light.color * std::max(0.0f, glm::dot(normal, -light.direction));
		
		/*PointLight light = *((PointLight*)lights->at(0).get());
		glm::vec3 normal = hit.hitObject->calculateNormal(hit.location);
		double lightDist = light.getLightDist(hit.location);
		Ray shadowRay = Ray(hit.location + normal * (float)bias, -light.getLightDirection(hit.location));
		Hit shadowHit = trace(shadowRay);
		bool visible = true;
		hitColor = visible * (float)hit.hitObject->albedo * light.getColorIntensity(hit.location) * std::max(0.0f, glm::dot(normal, -light.getLightDirection(hit.location)));*/
	}
	else
	{
		hitColor = backgroundColor;
	}

	return glm::clamp(hitColor, 0.0f, 255.0f);
}
