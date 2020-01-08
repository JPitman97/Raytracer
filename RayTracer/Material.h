#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <GLM/glm.hpp>

class Material
{
public:
	Material();
	Material(const glm::fvec2& albedo, const glm::vec3& colour, const float& spec);

	glm::fvec2 getAlbedo() const;
	glm::vec3 getDiffuseColour() const;
	float getSpecularExponent() const;

private:
	glm::fvec2 albedo;
	glm::vec3 diffuse_colour;
	float specular_exponent;
};

#endif