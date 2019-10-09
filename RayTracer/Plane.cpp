#include "Plane.h"
#include <utility>

Plane::Plane()
{
	normal = glm::vec3(1, 0, 0);
	distance = 0;
	colour = Colour(glm::vec4(0.5f, 0.5f, 0.5f, 0));
}

Plane::Plane(const glm::vec3& _normal, const double& _distance, Colour _colour)
	: normal(_normal),
	  distance(_distance),
	  colour(std::move(_colour))
{
}

glm::vec3& Plane::getPlaneNormal()
{
	return normal;
}

double& Plane::getPlaneDistance()
{
	return distance;
}

Colour Plane::getColor()
{
	return colour;
}

glm::vec3& Plane::getNormalAtPoint(const glm::vec3 _point)
{
	return normal;
}

double Plane::findIntersection(Ray ray)
{
	glm::vec3 rayDir = ray.getDirection();
	double a = glm::dot(rayDir, normal);

	if (a != 0)
	{
		glm::vec3 e (normal.x * distance, normal.y * distance, normal.z * distance);
		glm::vec3 t = ray.getOrigin() + -e;
		double b = glm::dot(normal, t);
		return -1 * b / a;
	}
	else
	{
		//Parallel... skip
		return -1;
	}
}
