#ifndef _COLOUR_H_
#define _COLOUR_H_

#include "GLM/glm.hpp"
#include "cmath"

class Colour
{
private:
	glm::vec4 colour;
public:
	Colour();
	Colour(const glm::vec4& _colour);

	virtual glm::vec4 getColour();
	void setColour(const glm::vec4& _colour);
};

#endif