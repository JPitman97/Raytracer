#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "GLM/glm.hpp"
#include "Colour.h"
#include "Object.h"

class Sphere : public Object
{
private:
	glm::vec3 center;
	double radius;
	Colour colour;

public:
	Sphere();
	Sphere(const glm::vec3& _center, const double& _radius, const Colour& _colour);

	glm::vec3& getSphereCenter();
	double& getSphereRadius();
	Colour getColor() override;

	glm::vec3& getNormalAt(const glm::vec3& _point);
	double findIntersection(Ray _ray) override;
};

#endif