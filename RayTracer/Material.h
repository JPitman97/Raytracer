#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <GLM/glm.hpp>

class Material
{
public:
	Material();
	Material(const glm::vec3& _colour, const float& _spec);

	glm::vec3 getDiffuseColour() const;
	float getSpecularExponent() const;

private:
	glm::vec3 diffuse_colour;
	float specular_exponent;
};

#endif