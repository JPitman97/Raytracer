#include "Ray.h"

glm::vec3& Ray::getOrigin()
{
	return origin;
}

glm::vec3& Ray::getDirection()
{
	return direction;
}

Ray::Ray(const glm::vec3& origin, const glm::vec3& direction)
	: origin(origin),
	  direction(direction)
{}
