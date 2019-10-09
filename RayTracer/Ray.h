#ifndef _RAY_H_
#define _RAY_H_

#include "GLM/glm.hpp"

class Ray
{
private:
	glm::vec3 origin, direction;

public:
	glm::vec3& getOrigin();
	glm::vec3& getDirection();
	Ray(const glm::vec3& origin, const glm::vec3& direction);
	
};
#endif