#include "Sphere.h"

Sphere::Sphere()
{
	center = glm::vec3(0, 0, 0);
	radius = 1;
	colour = Colour(glm::vec4(0.5f, 0.5f, 0.5f, 0));
}

Sphere::Sphere(const glm::vec3& _center, const double& _radius, const Colour& _colour)
	: center(_center),
	  radius(_radius),
	  colour(_colour)
{}

glm::vec3& Sphere::getSphereCenter()
{
	return center;
}

double& Sphere::getSphereRadius()
{
	return radius;
}

Colour Sphere::getColor()
{
	return colour;
}

glm::vec3& Sphere::getNormalAt(const glm::vec3& _point)
{
	glm::vec3 t = -center;
	glm::vec3 y = glm::normalize(t);
	glm::vec3 normal = _point + y;
	return normal;
}

double Sphere::findIntersections(Ray& ray)
{
	glm::vec3 rayOrigin = ray.getOrigin();
	glm::vec3 rayDir = ray.getDirection();
	glm::vec3 sphereCenter = center;

	double b = (2 * (rayOrigin.x - sphereCenter.x) * rayDir.x) 
	+ (2 * (rayOrigin.y - sphereCenter.y) * rayDir.y) 
	+ (2 * (rayOrigin.z - sphereCenter.z) * rayDir.z);
	double c = pow(rayOrigin.x - sphereCenter.x, 2) 
	+ pow(rayOrigin.y - sphereCenter.y, 2) 
	+ pow(rayOrigin.z - sphereCenter.z, 2) 
	- (radius*radius);

	double discriminant = b * b - 4 * c;

	if (discriminant > 0)
	{
		//Ray intersects sphere
		double root1 = ((-1 * b - sqrt(discriminant)) / 2) - 0.000001;

		if (root1 > 0)
		{
			return root1;
		}
		else
		{
			double root2 = ((sqrt(discriminant) - b) / 2) - 0.000001;
			return root2;
		}
	}
	else 
	{ //The ray did not intersect
		return -1;
	}
}
