#include "Light.h"

//Constructor to initialize the position and intensity of the lights
Light::Light(const glm::vec3& _position, const float& _intensity) : position(_position), intensity(_intensity)
{}

//Returns the lights position
glm::vec3 Light::getPosition() const
{
	return position;
}

//Returns the lights intensity
float Light::getIntensity() const
{
	return intensity;
}
