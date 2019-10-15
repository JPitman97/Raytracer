#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "GLM/glm.hpp"
#include "Material.h"

class Sphere
{
private:
	glm::vec3 center;
	
private:
	double radius;
	Material material;

public:
	Sphere();
	Sphere(const glm::vec3& _center, const double& _radius, const Material& _material);

	void setSphereCenter(const glm::vec3& center);
	glm::vec3& getSphereCenter();
	double& getSphereRadius();
	Material getSphereMaterial();

	bool findIntersection(const glm::vec3& _origin, const glm::vec3& _direction, float& t0);
};

#endif