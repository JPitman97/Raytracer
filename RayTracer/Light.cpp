#include "Light.h"

Light::Light()
{
	position = glm::vec3(0, 0, 0);
	colour = glm::vec4(1, 1, 1, 0);
}

Light::Light(const glm::vec3& _pos, const Colour& _colour)
	: position(_pos),
	  colour(_colour)
{}

glm::vec3& Light::getLightPosition()
{
	return position;
}

Colour& Light::getLightColour()
{
	return colour;
}
