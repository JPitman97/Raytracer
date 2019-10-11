#include "Sphere.h"


Sphere::Sphere()
{
	center = glm::vec3(0, 0, 0);
	radius = 1;
}

Sphere::Sphere(const glm::vec3& _center, const double& _radius, const Material& _material)
	: center(_center),
	  radius(_radius),
	  material(_material)
{}

glm::vec3& Sphere::getSphereCenter()
{
	return center;
}

double& Sphere::getSphereRadius()
{
	return radius;
}

Material Sphere::getSphereMaterial()
{
	return material;
}

bool Sphere::findIntersection(const glm::vec3& _origin, const glm::vec3& _direction, float& t0)
{
	glm::vec3 L = center - _origin;
	float tca = L.x  * _direction.x + L.y * _direction.y + L.z * _direction.z;
	float d2 = (L.x * L.x + L.y * L.y + L.z * L.z) - tca * tca;
	if (d2 > (radius * radius))
		return false;
	float thc = sqrt(radius * radius - d2);
	t0 = tca - thc;
	float t1 = tca + thc;
	if (t0 < 0)
		t0 = t1;
	return t0 >= 0;
}
