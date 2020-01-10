#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <GLM/glm.hpp>

class Light
{
public:
	Light(const glm::vec3& _position, const float& _intensity);

	glm::vec3 getPosition() const;
	float getIntensity() const;

private:
	glm::vec3 position;
	float intensity;
};

#endif