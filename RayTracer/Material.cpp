#include "Material.h"

Material::Material() : albedo(1, 0), specular_exponent() {}

Material::Material(const glm::fvec2& albedo, const glm::vec3& colour, const float& spec) : albedo(albedo), diffuse_colour(colour), specular_exponent(spec)
{}

glm::fvec2 Material::getAlbedo() const
{
	return albedo;
}

glm::vec3 Material::getDiffuseColour() const
{
	return diffuse_colour;
}

float Material::getSpecularExponent() const
{
	return specular_exponent;
}
