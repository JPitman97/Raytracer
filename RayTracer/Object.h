#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Ray.h"
#include "Colour.h"

class Object
{
public:
	virtual ~Object() = default;
	Object();
	virtual Colour getColor();
	virtual double findIntersection(Ray _ray);
};

#endif