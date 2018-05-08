#include "Sphere.h"

#include "Hit.h"
#include "Ray.h"

Sphere::Sphere()
{
	center = glm::vec3(0, 0, 0);
	radius = 0;
}

Sphere::Sphere(glm::vec3 color, float albedo, glm::vec3 center, float radius) : Object(color, albedo)
{
	this->center = center;
	this->radius = radius;
}

Sphere::~Sphere()
{
}

Hit Sphere::intersect(const Ray &ray)
{
	/*Definitions (to help keep comments shorter):
	norm - the line perpendicular to the ray that passes through the sphere's center
	a - the ray's origin
	b - the first point of intersection with the sphere
	c - the point of intersection between the ray and norm
	A - the right triangle defined by a, c, and the sphere's center
	B - the right triangle defined by b, c, and the sphere's center
	*/

	Hit hit;

	glm::vec3 h = center - ray.origin; // Hypotenuse of A
	float t_ac = glm::dot(h, glm::normalize(ray.direction)); // Parametric value of c along the ray
	if(t_ac < 0) // If negative, any intersection is behind the camera and can't be seen, so return empty hit
	{
		return hit;
	}
	
	float d2 = glm::dot(h, h) - t_ac * t_ac; // Square of the length of the line segment between c and the sphere's center
	if(d2 > radius * radius) // If d^2 is greater than radius^2, then the ray misses the sphere, so return 
	{
		return hit;
	}

	float t_bc = sqrt(radius * radius - d2); // Length of line segment from first intersection to the point c
	float t0 = t_ac - t_bc; // The first intersection happens t_bc units before t_ac
	float t1 = t_ac + t_bc; // The second happens t_bc units after

	// TODO: Figure out if swapping t0 and t1 is ever necessary

	hit.t = t0;
	hit.location = ray.origin + (float)t0 * glm::normalize(ray.direction);
	hit.hitObject = this;

	return hit;
}

glm::vec3 Sphere::calculateNormal(glm::vec3 location)
{
	return glm::normalize(location - center);
}
