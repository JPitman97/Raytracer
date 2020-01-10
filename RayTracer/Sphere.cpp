#include "Sphere.h"

//Set the spheres position (Used if animating)
void Sphere::setSphereCenter(const glm::vec3& _center)
{
	this->center = _center;
}

//Default constructor with basic values
Sphere::Sphere()
{
	center = glm::vec3(0, 0, 0);
	radius = 1;
}

//Standard constructor that initialises passed in values for position and radius, as well as material
Sphere::Sphere(const glm::vec3& _center, const double& _radius, const Material& _material)
	: center(_center),
	  radius(_radius),
	  material(_material)
{}

//Return the spheres position
glm::vec3& Sphere::getSphereCenter()
{
	return center;
}

//Return the spheres radius
double& Sphere::getSphereRadius()
{
	return radius;
}

//Return the spheres material
Material Sphere::getSphereMaterial() const
{
	return material;
}

//Find intersection between this sphere and any rays fired towards it
bool Sphere::findIntersection(const glm::vec3& _origin, const glm::vec3& _direction, float& _t0) const
{
	const glm::vec3 L = center - _origin; //Calculate the difference between the sphere center and rays origin
	const float tca = L.x * _direction.x + L.y * _direction.y + L.z * _direction.z;
	const float d2 = (L.x * L.x + L.y * L.y + L.z * L.z) - tca * tca;
	if (d2 > radius * radius) //If d2 is larger than the sqrt of radius, nothing was hit
		return false;
	const float thc = std::sqrt(radius * radius - d2);
	_t0 = tca - thc; //Assign a distance value from the ray and sphere to the dist_i value passed in
	const float t1 = tca + thc;
	if (_t0 < 0)
		_t0 = t1;
	return _t0 >= 0; //If an object is hit one or more times (Each side), then return true meaning an object was hit
}
