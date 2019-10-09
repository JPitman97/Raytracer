#include "Object.h"

Object::Object()
{
}

Colour Object::getColor()
{
	Colour blank;
	blank.setColour(glm::vec4(0, 0, 0, 0));
	return blank;
}

double Object::findIntersection(Ray _ray)
{
	return 0;
}
