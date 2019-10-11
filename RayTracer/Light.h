#pragma once
#include <GLM/glm.hpp>

class Light
{
public:
	Light(const glm::vec3& p, const float& i);

	glm::vec3 getPosition() const;
	float getIntensity() const;

private:
	glm::vec3 position;
	float intensity;
};

