#include "Object.h"

Object::Object()
{
	color = glm::vec3(255, 255, 255);
	albedo = 0.18f;
}

Object::Object(glm::vec3 color, float albedo)
{
	this->color = color;
	this->albedo = albedo;
}

Object::~Object()
{
}
