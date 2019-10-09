#include "Colour.h"

Colour::Colour()
{
	colour = glm::vec4(0.5f, 0.5f, 0.5f, 0);
}

Colour::Colour(const glm::vec4& _colour) 
	: colour(_colour)
{}

glm::vec4 Colour::getColour()
{
	return colour;
}

void Colour::setColour(const glm::vec4& _colour)
{
	colour = _colour;
}
