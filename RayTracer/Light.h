#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "GLM/glm.hpp"
#include "Colour.h"

class Light
{
private:
	glm::vec3 position;
	Colour colour;

public:
	Light();
	Light(const glm::vec3& _pos, const Colour& _colour);

	virtual glm::vec3& getLightPosition();
	virtual Colour& getLightColour();
};

#endif