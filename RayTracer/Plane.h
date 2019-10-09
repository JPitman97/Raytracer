#pragma once
#include "Object.h"
class Plane : public Object
{
private:
	glm::vec3 normal;
	double distance;
	Colour colour;

public:
	Plane();
	Plane(const glm::vec3& _normal, const double& _distance, const Colour& _colour);
	glm::vec3& getPlaneNormal();
	double& getPlaneDistance();
	Colour getColor() override;
	glm::vec3& getNormalAtPoint(const glm::vec3 _point);
	double findIntersection(Ray ray);
};

