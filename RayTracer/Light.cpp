#include "Light.h"

Light::Light(const glm::vec3& _p, const float& _i) : position(_p), intensity(_i)
{}

glm::vec3 Light::getPosition() const
{
	return position;
}

float Light::getIntensity() const
{
	return intensity;
}
