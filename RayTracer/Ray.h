#ifndef _RAY_H_
#define _RAY_H_

#include "GLM/glm.hpp"
#include "Sphere.h"
#include <vector>
#include <algorithm>
#include "Light.h"
#include "Utils.h"

class Ray
{
private:
	glm::vec3 origin, direction;

public:
	Ray();
	Ray(const glm::vec3& _origin, const glm::vec3& _direction, const Sphere& _sphere);

	glm::vec3& getOrigin();
	glm::vec3& getDirection();
	glm::vec3 castRay(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres, const std::vector<Light>& _lights);
	bool sceneIntersects(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres, glm::vec3& _hit, glm::vec3& N, Material& _material) const;
	glm::vec3 reflect(const glm::vec3& I, const glm::vec3& N);
};
#endif