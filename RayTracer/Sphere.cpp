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
	glm::vec3 normal_Vect = _point + (-center);
	normal_Vect = glm::normalize(normal_Vect);
	return normal_Vect;
}

double Sphere::findIntersection(Ray _ray)
{
	//Vect ray_origin (_ray.getOrigin().x, _ray.getOrigin().y, _ray.getOrigin().z);
	glm::vec3 ray_origin = _ray.getOrigin();


	glm::vec3 ray_direction = _ray.getDirection();


	double a = 1; // normalized
	double b = (2 * (ray_origin.x - center.x) * ray_direction.x) + (2 * (ray_origin.y - center.y) * ray_direction.y) + (2 * (ray_origin.z - center.z) * ray_direction.z);
	double c = pow(ray_origin.x - center.x, 2) + pow(ray_origin.y - center.y, 2) + pow(ray_origin.z - center.z, 2) - (radius * radius);

	double discriminant = b * b - 4 * c;

	if (discriminant > 0) {
		/// the ray intersects the sphere

		// the first root
		double root_1 = ((-1 * b - sqrt(discriminant)) / 2) - 0.000001;

		if (root_1 > 0) {
			// the first root is the smallest positive root
			return root_1;
		}
		else {
			// the second root is the smallest positive root
			double root_2 = ((sqrt(discriminant) - b) / 2) - 0.000001;
			return root_2;
		}
	}
	else {
		// the ray missed the sphere
		return -1;
	}
}
